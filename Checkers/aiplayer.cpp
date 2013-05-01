#include "aiplayer.h"

AIPlayer::AIPlayer() {
    name = "Nonamed UI";
    this->setType(PLAYER_AI);
}

bool AIPlayer::move() {
    qDebug() << "I am UI player and i am moving!";
}

bool AIPlayer::isReady() {
    return true;    // yes i can always
}

Position AIPlayer::getMove() {
    return {qrand() % 8, qrand() % 8};
}
