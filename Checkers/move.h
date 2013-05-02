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
    void setFrom(Position); // kvuli pretizenym operatorum nestaci jen v konstruktoru
    void setTo(Position);
    bool operator==(const Move &x);
private:
    Position from;
    Position to;
};


// Definice, deklarace je v main
QDataStream &operator<<(QDataStream &out, Move &settings); // const delal warningy
QDataStream &operator>>(QDataStream &in, Move &settings);

#endif // MOVE_H
