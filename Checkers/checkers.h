#ifndef CHECKERS_H
#define CHECKERS_H

#include <QVector>
#include <QDebug>
#include <player.h>
#include <move.h>
#include <common.h>
#include <QCoreApplication>
#include <QTime>

/* OrigTable*/
const int BOARD_INITIAL[8][8] = {
                                    {FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE},
                                    {NONE,FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W},
                                    {FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B},
                                    {FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B,NONE},
                                    {NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B}
                                };
/*const int BOARD_INITIAL[8][8] = { // test
    {FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE,NONE,NONE},
    {NONE,FIGURE_W,NONE,FIGURE_W,NONE,NONE,NONE,FIGURE_W},
    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
    {NONE,NONE,NONE,FIGURE_W,NONE,NONE,NONE,NONE},
    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
    {NONE,NONE,NONE,FIGURE_B,NONE,NONE,NONE,NONE},
    {FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_W,NONE,FIGURE_B,NONE},
    {NONE,FIGURE_B,NONE,FIGURE_B,NONE,NONE,NONE,FIGURE_B}
};*/

class Checkers
{
public:
    Checkers();

    bool moveFigure(Move);
    QVector<Move> getPossibleMoves(int player);
    void setPlayerW(Player *);
    void setPlayerB(Player *);
    void play();
    void resetGame();
    BoardTypes getBoard(int x,int y);
    Player *getPlayerOnTurn();

private:
    void debugMoveVec(QVector<Move>);//debug
    bool isValidMove(Move); // nepouzivam
    bool changeToQueen(Move);
    bool inBoard(Position);
    std::pair<int, Position> isOnDiagonal(Position,Position); // nepouzivam
    std::pair<int, Position> getTakenFigure(Move);

    Player *getPlayerW();
    Player *getPlayerB();
    Players getOnTurn();
    void gameOver();




    BoardTypes board[8][8];

    QVector<Move> moves;
    Player *playerW;
    Player *playerB;
    Players onTurn;

    void resetBoard();
    void debugBoard();
    void makeMove(Position); // debug zatim, smazat



};

#endif // CHECKERS_H
