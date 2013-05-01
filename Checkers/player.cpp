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

Position Player::getMove() {
    return movePosition;   // return prepared move coords
}

void Player::setMove(Position coords) {
    this->movePosition = coords;
}

bool Player::isReady() {
    return moveReady;   // is some move ready?
}

void Player::clearReady() {
    this->moveReady = false;
}

void Player::setReady() {
    this->moveReady = true;
}

PlayerType Player::getType() {
    return this->type;
}
