#ifndef MOVE_H
#define MOVE_H

#include <QDebug>
#include "common.h"

class Move
{
public:
    Move(); // debug.. delete?
    Move(Position, Position);
    Position getFrom();
    Position getTo();
    std::pair<BoardTypes,Position> getTakenFigure();
    void setTakenFigure(std::pair<BoardTypes,Position>);
    bool operator==(const Move &x);
private:
    Position from;
    Position to;
    std::pair<BoardTypes,Position> takenFigure;
};

#endif // MOVE_H
