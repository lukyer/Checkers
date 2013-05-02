#ifndef GUIBOARD_H
#define GUIBOARD_H

#include <QtGui>

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>

#include "common.h"
#include "abstractplayer.h"
#include "realplayer.h"
#include "checkers.h"
#include "guisquare.h"
#include "guifigure.h"
#include "networkplayer.h"


class GUIBoard : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GUIBoard(QWidget *parent = 0);
    void setCheckers (Checkers *);
    Checkers *getCheckers();

public slots:
    void figureMove(Move, PlayerType);
    void redraw();
    void timeout();
    void settingsReceived(GameSettings);

private:
    Checkers *checkers = null;
    QGraphicsScene *scene;
    QGraphicsGridLayout *grid;




    
};

#endif // GUIBOARD_H
