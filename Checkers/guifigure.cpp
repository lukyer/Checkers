#include "guifigure.h"

GUIFigure::GUIFigure(QGraphicsWidget *parent) : QGraphicsWidget(parent)
{
    pressed = false;
    //setFlag(ItemIsMovable);

}


void GUIFigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    rec = QRectF(5,5,40,40);

    QColor color;
    QBrush brush;

    if (this->type == FIGURE_W) {
        color = Qt::white;
        brush.setStyle(Qt::SolidPattern);
    } else if (this->type == FIGURE_B) {
        color = Qt::black;
        brush.setStyle(Qt::SolidPattern);
    } else if (this->type == QUEEN_W) {
        color = Qt::white;
        brush.setStyle(Qt::Dense7Pattern);
    } else if (this->type == QUEEN_B) {
        color = Qt::black;
        brush.setStyle(Qt::Dense7Pattern);
    }



    brush.setColor(color);




    //painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    //painter->fillRect(rec, brush);
    painter->drawEllipse(rec);

    //painter->drawRect(QRectF(0,0,50,50));
}

void GUIFigure::setType(BoardTypes type)
{
    this->type = type;
}




void GUIFigure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{


    QPixmap pixmap = QPixmap();




    GUISquare *parent;  // parent has index!
    parent = (GUISquare *) this->parent();


    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << (parent->getIndex().x);   // nemuze posilat cely Position, jen po prvcich
    dataStream << (parent->getIndex().y);
    QMimeData *mimeData = new QMimeData;

    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(event->widget());
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    //drag->setHotSpot((QPoint)event->pos());




   drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);


return;








    pressed = true;
    lastPosition = this->pos();

    // zindex se MUSI NASTAVIT RODICI ktery obaluje figurku, tzn square .. proc? Protoze nemuzes mit
    // vetsi / mensi zindex nez tvuj rodic!!!
    // Dale this->parent() vraci QObject() ktery NEZNA setZValue, takze se musi navratova hodnota
    // PRETYPOVAT na opravdovou tridu kterou parent vraci (kterou jsme mu nastavili pomoci setParent)

    if (this->parent() == 0) throw "Neni nastaveny rodic!";
    ((GUISquare*) this->parent())->setZValue(100); // zvys z at je pred vsemi objekty
    //this->scene()->update();  muze pomoci

    update();
    QGraphicsWidget::mousePressEvent(event);  // rethrow, important!

}

void GUIFigure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "RELEASE";
    if (this->parent() == 0) throw "Neni nastaveny rodic!";
    ((GUISquare*) this->parent())->setZValue(0); // sniz z zpatky at muzou ostatni objekty prekryt pri drag





    this->setPos(this->lastPosition);
    //emit(wantMove(this->index, event->pos()));
    pressed = false;
    update();
    QGraphicsWidget::mouseReleaseEvent(event);  // rethrow, important!
}

