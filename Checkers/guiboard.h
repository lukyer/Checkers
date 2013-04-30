#ifndef GUIBOARD_H
#define GUIBOARD_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include "common.h"
#include "player.h"
#include "realplayer.h"
#include "checkers.h"

#define null 0

class GUIBoard : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GUIBoard(QWidget *parent = 0);
    void setCheckers (Checkers *);
        
public slots:
    void mousePressEvent(QMouseEvent * e);

private:
    Checkers *checkers = null;

    
};

#endif // GUIBOARD_H
