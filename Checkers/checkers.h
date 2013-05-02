#ifndef CHECKERS_H
#define CHECKERS_H

#include <QVector>
#include <QDebug>
#include <QCoreApplication>
#include <QTime>

#include "abstractplayer.h"
#include "move.h"
#include "common.h"
#include "checkersgame.h"
#include "network.h"



class Checkers
{
public:
    Checkers();

    bool moveFigure(Move);
    void setPlayerW(AbstractPlayer *);
    void setPlayerB(AbstractPlayer *);
    void play();
    BoardTypes getBoard(Position);
    void resetGame();
    AbstractPlayer *getPlayerOnTurn();
    CheckersGame *getGame();
    bool isGameOver();
    Network *getNetwork();

private:

    AbstractPlayer *getPlayerW();
    AbstractPlayer *getPlayerB();
    PlayerColor getOnTurn();
    void endGame(PlayerColor);

    QVector<Move> moves;
    AbstractPlayer *playerW;
    AbstractPlayer *playerB;
    PlayerColor onTurn;
    CheckersGame *game;
    bool gameOver;
    Network *net;

    void makeMove(Position); // debug zatim, smazat
    void debugMoveVec(QVector<Move>); //debug vypis move Vectoru



};

#endif // CHECKERS_H
