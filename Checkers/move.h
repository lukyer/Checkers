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
    bool operator==(const Move &x);
private:
    Position from;
    Position to;
};

#endif // MOVE_H
