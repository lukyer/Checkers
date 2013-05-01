#include "move.h"

Move::Move()
{
    /*debug*/
    //qDebug() << "Debug: constructing Move without parameters";
    /*endof debug*/

}

Move::Move(Position posFrom, Position posTo) {
    from = posFrom;
    to = posTo;
}

Position Move::getFrom() {
    return from;
}

Position Move::getTo() {
    return to;
}

bool Move::operator ==(const Move &mov) {
    if (this->from== mov.from && this->to==mov.to ) {
        return true;
    } else {
        return false;
    }

}
