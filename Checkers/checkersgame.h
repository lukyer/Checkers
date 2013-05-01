#ifndef CHECKERSGAME_H
#define CHECKERSGAME_H

#include "move.h"
#include "common.h"

/* OrigTable*/
/*
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
*/
const int BOARD_INITIAL[8][8] = {
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,NONE,FIGURE_W,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,FIGURE_B,NONE},
                                    {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE}
                                };

class CheckersGame
{
public:
    CheckersGame();
    QVector<Move> getPossibleMoves(PlayerColor);
    BoardTypes getBoard(Position);
    bool updateBoard(Move);
    void resetBoard();

private:
    BoardTypes board[8][8];

    std::pair<BoardTypes, Position> getTakenFigure(Move);
    bool changeToQueen(Move);
    bool inBoard(Position);    
    void debugBoard();  //debug vypis hraci plochy


};

#endif // CHECKERSGAME_H
