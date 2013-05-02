#include "abstractplayer.h"

AbstractPlayer::AbstractPlayer(PlayerColor col)
{
    game = null;
    this->color = col;
}

void AbstractPlayer::setName(QString name) {
    this->name = name;
}

QString AbstractPlayer::getName() {
    return this->name;
}

void AbstractPlayer::setType(PlayerType type) {
    this->type = type;
}

Move AbstractPlayer::getMove() {
    return movePosition;   // return prepared move coords
}

void AbstractPlayer::setMove(Move coords) {
    this->movePosition = coords;
}

bool AbstractPlayer::isReady() {
    return moveReady;   // is some move ready?
}

void AbstractPlayer::clearReady() {
    this->moveReady = false;
}

bool AbstractPlayer::canMove() // Parametr color misto setColour() setteru kvuli tomu, ze checkers ma playerW, playerB a bylo by divne kdyby se to dalo porusit pri vnejsi inicializaci hracu ... treba dvakrat playerB ... to se nemuze stat, player je nestaranny!
{
    // Projit possible moves a pokud = 0 tak cant move!
    if (game == null) {
        throw "No GAME object has been set. I cant get player's possible moves!";
    }
    QVector<Move> possible = this->game->getPossibleMoves(color);
    if (possible.count() == 0) return false;    // neni zadny mozny tah k dispozici
    return true;
}

void AbstractPlayer::setCheckersGame(CheckersGame *game)
{
    this->game = game;
}

PlayerColor AbstractPlayer::getColor()
{
    return this->color;
}


void AbstractPlayer::setReady() {
    this->moveReady = true;
}

PlayerType AbstractPlayer::getType() {
    return this->type;
}
