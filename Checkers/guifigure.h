#ifndef GUIFIGURE_H
#define GUIFIGURE_H

#include <QtGui>
#include <QObject>
#include <QBrush>
#include <QPainter>

#include "common.h"
#include "guiboard.h"
#include "guisquare.h"

class GUIFigure : public QGraphicsWidget
{
    Q_OBJECT

public:
    GUIFigure(QGraphicsWidget *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setType(BoardTypes);


private:
    bool pressed;
    Position position;
    BoardTypes type = NONE;
    QPointF lastPosition;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);




    
//public slots:
    
};

#endif // GUIFIGURE_H
