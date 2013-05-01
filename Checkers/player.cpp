#include "player.h"

Player::Player()
{
    game = null;
}

void Player::setName(QString name) {
    this->name = name;
}

QString Player::getName() {
    return this->name;
}

void Player::setType(PlayerType type) {
    this->type = type;
}

Move Player::getMove() {
    return movePosition;   // return prepared move coords
}

void Player::setMove(Move coords) {
    this->movePosition = coords;
}

bool Player::isReady() {
    return moveReady;   // is some move ready?
}

void Player::clearReady() {
    this->moveReady = false;
}

bool Player::canMove(PlayerColor color) // Parametr color misto setColour() setteru kvuli tomu, ze checkers ma playerW, playerB a bylo by divne kdyby se to dalo porusit pri vnejsi inicializaci hracu ... treba dvakrat playerB ... to se nemuze stat, player je nestaranny!
{
    // Projit possible moves a pokud = 0 tak cant move!
    if (game == null) {
        throw "No GAME object has been set. I cant get player's possible moves!";
    }
    QVector<Move> possible = this->game->getPossibleMoves(color);
    if (possible.count() == 0) return false;    // neni zadny mozny tah k dispozici
    return true;
}

void Player::setCheckersGame(CheckersGame *game)
{
    this->game = game;
}


void Player::setReady() {
    this->moveReady = true;
}

PlayerType Player::getType() {
    return this->type;
}
