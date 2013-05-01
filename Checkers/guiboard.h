#ifndef GUIBOARD_H
#define GUIBOARD_H

#include <QtGui>

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>

#include "common.h"
#include "player.h"
#include "realplayer.h"
#include "checkers.h"
#include "guisquare.h"
#include "guifigure.h"


class GUIBoard : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GUIBoard(QWidget *parent = 0);
    void setCheckers (Checkers *);
    Checkers *getCheckers();

public slots:
    void figureMove(Position, Position);
    void redraw();
    void timeout();

private:
    Checkers *checkers = null;
    QGraphicsScene *scene;
    QGraphicsGridLayout *grid;




    
};

#endif // GUIBOARD_H
