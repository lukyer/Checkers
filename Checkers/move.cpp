#include "move.h"

Move::Move()
{
    /*debug*/
    //qDebug() << "Debug: constructing Move without parameters";
    /*endof debug*/

}

Move::Move(Position posFrom, Position posTo) {
    Position pos{-1,-1};
    from = posFrom;
    to = posTo;
    takenFigure = std::pair<BoardTypes,Position>(NONE,pos);
}

Position Move::getFrom() {
    return from;
}

Position Move::getTo() {
    return to;
}

std::pair<BoardTypes,Position> Move::getTakenFigure()
{
    return takenFigure;
}

void Move::setTakenFigure(std::pair<BoardTypes,Position> pair)
{
    takenFigure = pair;
}

bool Move::operator ==(const Move &mov) {
    if (this->from== mov.from && this->to==mov.to ) {
        return true;
    } else {
        return false;
    }

}
