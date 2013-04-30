#include "checkers.h"

Checkers::Checkers()
{
    resetBoard();
    debugBoard();
    this->onturn = PLAYER_W;    // white starts
}

void Checkers::resetBoard() {
    memcpy(&board, BOARD_INITIAL, sizeof(BOARD_INITIAL));
}

void Checkers::debugBoard() {
    for (int i = 0 ; i < 8 ; i++) {
        QString row;
        for (int j = 0 ; j < 8 ; j++) {
            row += QString::number(board[i][j]) + " ";
        }
        qDebug() << row;
    }
}

void Checkers::makeMove(Position coords) {
    qDebug() << "I just moved ... " << this->onturn << " x : " << coords.x << " y : " << coords.y;
}

void Checkers::play() {
    while (1) {
        if (this->onturn == PLAYER_W) {
            int can = this->playerW->isReady();
            if (can == false) {
                // Cant move right now (RealPlayer / Network async)
                return; // sleep
            } else {
                Position coords = this->playerW->getMove();
                this->playerW->clearReady();
                this->makeMove(coords);
                this->onturn = PLAYER_B;
            }
        } else {
            int can = this->playerB->isReady();
            if (can == false) {
                // Cant move right now (RealPlayer / Network async)
                return; // sleep
            } else {
                Position coords = this->playerB->getMove();
                this->playerB->clearReady();
                this->makeMove(coords);
                this->onturn = PLAYER_W;
            }
        }
    }
}


void Checkers::setPlayerW(Player * p) {
    this->playerW = p;
}

void Checkers::setPlayerB(Player * p) {
    this->playerB = p;
}

Player * Checkers::getPlayerW() {
    return this->playerW;
}

Player *Checkers::getPlayerB() {
    return this->playerB;
}

Players Checkers::getOnTurn() {
    return this->onturn;
}
