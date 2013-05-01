#ifndef GUISQUARE_H
#define GUISQUARE_H

#include <QtGui>
#include "common.h"
#include "guifigure.h"

class GUIFigure;    // kvuli kruhove zavislosti GUIFigure <> GUISquare

class GUISquare : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit GUISquare(QGraphicsWidget *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    ~GUISquare();

    void setFigure(GUIFigure *);
    GUIFigure * getFigure();
    void hideFigure();
    void showFigure();
    void addFigure(BoardTypes);
    void delFigure();


    void setIndex(Position);
    Position getIndex();

    bool test = false;

protected:
    Position index;

private:
    GUIFigure *figure;

signals:
    void wantMove(Position, Position);
    
public slots:
    
};

#endif // GUISQUARE_H
