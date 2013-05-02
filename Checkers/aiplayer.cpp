#include "aiplayer.h"


AIPlayer::AIPlayer(PlayerColor color) : AbstractPlayer(color) {
    name = "Nonamed UI";
    this->setType(PLAYER_AI);
}

bool AIPlayer::isReady() {
    return true;    // yes i can always
}

Move AIPlayer::getMove() {
    /*QTime dieTime= QTime::currentTime().addSecs(1);
        while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);*/    
    QVector<Move> possible = this->game->getPossibleMoves(color);
    if (possible.count() == 0) return Move();
    int selectedIndex = qrand() % possible.count();
    Move selectedMove = possible.at(selectedIndex);

    return selectedMove;

}
