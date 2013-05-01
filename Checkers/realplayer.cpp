#include "realplayer.h"

RealPlayer::RealPlayer() {
    name = "Nonamed REAL";
    this->setType(PLAYER_REAL);
}

bool RealPlayer::move() {
    /*if (this->checker == null) {
        qDebug() << "Checker has not been set!";
        return false;
    }*/
    qDebug() << "I am real player called " << name << " and i am moving!";
}
