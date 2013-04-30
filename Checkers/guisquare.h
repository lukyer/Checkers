#ifndef GUISQUARE_H
#define GUISQUARE_H

#include <QtGui>
#include "common.h"

class GUISquare : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit GUISquare(QGraphicsWidget *parent = 0);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);


    void setIndex(Position);
    Position getIndex();

    bool test = false;

protected:
    Position index;

signals:
    
public slots:
    
};

#endif // GUISQUARE_H
