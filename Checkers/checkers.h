#ifndef CHECKERS_H
#define CHECKERS_H

#include <QVector>
#include <QDebug>
#include <player.h>
#include <move.h>
#include <common.h>

/* OrigTable
const int BOARD_INITIAL[8][8] = {
                                    {FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE},
                                    {NONE,FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W},
                                    {FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B},
                                    {FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B,NONE},
                                    {NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_B}
                                };*/
const int BOARD_INITIAL[8][8] = { // test
    {FIGURE_W,NONE,FIGURE_W,NONE,FIGURE_W,NONE,NONE,NONE},
    {NONE,FIGURE_W,NONE,FIGURE_W,NONE,NONE,NONE,FIGURE_W},
    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
    {NONE,NONE,NONE,FIGURE_W,NONE,NONE,NONE,NONE},
    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
    {NONE,NONE,NONE,FIGURE_B,NONE,NONE,NONE,NONE},
    {FIGURE_B,NONE,FIGURE_B,NONE,FIGURE_W,NONE,FIGURE_B,NONE},
    {NONE,FIGURE_B,NONE,FIGURE_B,NONE,NONE,NONE,FIGURE_B}
};

class Checkers
{
public:
    Checkers();
<<<<<<< HEAD
    bool moveFigure(Move);
    QVector<Move> getPossibleMoves(int player);
private:
    int board[8][8];
    int onTurn;
    QVector<Move> moves;
    Player playerW;
    Player playerB;
    void resetBoard();
    void debugBoard();
    void debugMoveVec(QVector<Move>);
    bool isValidMove(Move); // nepouzivam
    bool changeToQueen(Move);
    bool inBoard(Position);
    std::pair<int, Position> isOnDiagonal(Position,Position); // nepouzivam
    std::pair<int, Position> getTakenFigure(Move); // nepouzivam
=======
    void setPlayerW(Player *);
    void setPlayerB(Player *);
    Player *getPlayerW();
    Player *getPlayerB();
    Players getOnTurn();
    BoardTypes getBoard(int x,int y);

    void play();
    BoardTypes board[8][8];

private:

    QVector<Move> moves;
    Player *playerW;
    Player *playerB;
    Players onturn;

    void resetBoard();
    void debugBoard();
    void makeMove(Position);
>>>>>>> c4575145f40a15276eb2ef35cc373413fab07491


};

#endif // CHECKERS_H
