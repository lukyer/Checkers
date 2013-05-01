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

Move AIPlayer::getMove() {
    /*QTime dieTime= QTime::currentTime().addSecs(1);
        while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);*/    
    return Move({qrand() % 8, qrand() % 8},{qrand() % 8, qrand() % 8});

}
