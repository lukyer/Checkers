#include "player.h"

Player::Player()
{

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

bool Player::canMove()
{
    // Projit possible moves a pokud = 0 tak cant move!
    return true;
}

void Player::setReady() {
    this->moveReady = true;
}

PlayerType Player::getType() {
    return this->type;
}
