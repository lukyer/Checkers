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
<<<<<<< HEAD
    BoardTypes getBoard(Position);
    void resetGame();
=======
    void resetGame();
    BoardTypes getBoard(int x,int y);
>>>>>>> 9a59bfb22e39b3d08d4f45126e4d81b54d718524
    Player *getPlayerOnTurn();

private:

    Player *getPlayerW();
    Player *getPlayerB();
    Players getOnTurn();
    void gameOver();
<<<<<<< HEAD
=======




    BoardTypes board[8][8];
>>>>>>> 9a59bfb22e39b3d08d4f45126e4d81b54d718524

    QVector<Move> moves;
    Player *playerW;
    Player *playerB;
    Players onTurn;
    CheckersGame *game;


    void makeMove(Position); // debug zatim, smazat
    void debugMoveVec(QVector<Move>); //debug vypis move Vectoru



};

#endif // CHECKERS_H
