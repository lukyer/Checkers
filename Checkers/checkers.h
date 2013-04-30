#ifndef CHECKERS_H
#define CHECKERS_H

#include <QVector>
#include <QDebug>
#include <player.h>
#include <move.h>
#include <common.h>

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

class Checkers
{
public:
    Checkers();
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


};

#endif // CHECKERS_H
