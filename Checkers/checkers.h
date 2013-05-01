#ifndef CHECKERS_H
#define CHECKERS_H

#include <QVector>
#include <QDebug>
#include <QCoreApplication>
#include <QTime>

#include "player.h"
#include "move.h"
#include "common.h"
#include "checkersgame.h"




class Checkers
{
public:
    Checkers();

    bool moveFigure(Move);
    void setPlayerW(Player *);
    void setPlayerB(Player *);
    void play();
    BoardTypes getBoard(Position);
    Player *getPlayerOnTurn();

private:

    Player *getPlayerW();
    Player *getPlayerB();
    Players getOnTurn();

    QVector<Move> moves;
    Player *playerW;
    Player *playerB;
    Players onTurn;
    CheckersGame *game;


    void makeMove(Position); // debug zatim, smazat
    void debugMoveVec(QVector<Move>); //debug vypis move Vectoru



};

#endif // CHECKERS_H
