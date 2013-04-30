#ifndef CHECKERS_H
#define CHECKERS_H

#include <QVector>
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


};

#endif // CHECKERS_H
