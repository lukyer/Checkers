#ifndef GUISQUARE_H
#define GUISQUARE_H

#include <QtGui>
#include "common.h"

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


    void setIndex(Position);
    Position getIndex();

    bool test = false;

protected:
    Position index;

signals:
    void wantMove(Position, Position);
    
public slots:
    
};

#endif // GUISQUARE_H
