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
    void resetGame();
    Player *getPlayerOnTurn();
    CheckersGame *getGame();
    bool isGameOver();

private:

    Player *getPlayerW();
    Player *getPlayerB();
    PlayerColor getOnTurn();
    void endGame(PlayerColor);

    QVector<Move> moves;
    Player *playerW;
    Player *playerB;
    PlayerColor onTurn;
    CheckersGame *game;
    bool gameOver;


    void makeMove(Position); // debug zatim, smazat
    void debugMoveVec(QVector<Move>); //debug vypis move Vectoru



};

#endif // CHECKERS_H
