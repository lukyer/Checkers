#include "guisquare.h"

GUISquare::GUISquare(QGraphicsWidget *parent) : QGraphicsWidget(parent)
{
    this->setAcceptDrops(true);
    figure = null;
    //qDebug() << "GUI SQUARE CONSTRUCTED";
}

GUISquare::~GUISquare() {
    qDebug() << "GUI SQUARE DESTRUCTED";
}



void GUISquare::setFigure(GUIFigure * fig)
{
    this->figure = fig;
}

GUIFigure *GUISquare::getFigure()
{
    return this->figure;
}

void GUISquare::hideFigure()
{
    //
}

void GUISquare::showFigure()
{
    //
}

void GUISquare::addFigure(BoardTypes type)
{
    figure = new GUIFigure(this);
    figure->setType(type);
    figure->setParent(this);    // musime nastavit parent i pomoci teto metody, konstruktor nestaci pro odkazovani se na rodice! Pro vykreslovani uvnitr staci.
}

void GUISquare::delFigure()
{
    if (figure == null) return;
    delete figure;
    figure = null;
}

QRectF GUISquare::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void GUISquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QColor color;
    if (test) {
        color = QColor(Qt::red);
    } else {
        color = QColor(Qt::gray);
    }

    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawRect(rec);
}

void GUISquare::dropEvent(QGraphicsSceneDragDropEvent *event)
{


    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        Position sourceIndex;
        Position destinationIndex = this->index;

        dataStream >>  sourceIndex.x;
        dataStream >>  sourceIndex.y;


//        qDebug() << "POZADAVEK NA PRESUN Z " << sourceIndex.x << "x" << sourceIndex.y << " DO " << destinationIndex.x << "x" << destinationIndex.y;
        emit wantMove(sourceIndex, destinationIndex);

        this->test = false;
        this->update();

        event->accept();
        event->setDropAction(Qt::MoveAction);
        event->acceptProposedAction();
        /*
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
        */
    } else {
        event->ignore();
    }

}

void GUISquare::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    this->test = true;
    this->update();
}

void GUISquare::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
}

void GUISquare::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    this->test = false;
    this->update();
}


void GUISquare::setIndex(Position index)
{
    this->index = index;
}

Position GUISquare::getIndex()
{
    return this->index;
}



