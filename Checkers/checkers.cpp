#include "checkers.h"




Checkers::Checkers()
{
    this->game = new CheckersGame();
    this->onTurn = PLAYER_W;    // white starts
}

BoardTypes Checkers::getBoard(Position pos) {

    /* delegovane z game
    * if (pos.x < 0 || pos.x > 7 || pos.y < 0 || pos.y > 7) throw "Coords not valid.";
    * return this->board[pos.x][pos.y];
    */
    this->game->getBoard(pos);

}


/*debug*/


void Checkers::debugMoveVec(QVector<Move> v) {

    for(int i=0; i < v.size(); i++ ){
        qDebug() << "from" << v[i].getFrom().x << ":" << v[i].getFrom().y <<
                    "to:" << v[i].getTo().x   << ":" << v[i].getTo().y;
    }

}

/*endof debug*/

bool Checkers::moveFigure(Move move) {

    QVector<Move> possibleMoves;

    possibleMoves = game->getPossibleMoves(onTurn);

    debugMoveVec(possibleMoves); // debug

    if (possibleMoves.contains(move)) {// po validnim tahu pridame move a zmenime board

        game->updateBoard(move);
        moves.append(move);

    } else {
        qDebug() << "nevalidni tah";
        return false;
    }


    //debugBoard();   //debug vypsani boardu
    return true;
}





void Checkers::makeMove(Position coords) {
    qDebug() << "I just moved ... " << this->onTurn << " x : " << coords.x << " y : " << coords.y;
}

void Checkers::play() {
    qDebug() << "ON TURN: " << this->onTurn;
    while (1) {

        if (this->onTurn == PLAYER_W) {
            int can = this->playerW->isReady();
            if (can == false) {
                // Cant move right now (RealPlayer / Network async)
                return; // sleep
            } else {
                Move move = this->playerW->getMove();
                qDebug() << "PLAYER WHITE HAS TURNED : " << move.getFrom().x << "x" << move.getFrom().y << "   to    " << move.getTo().x << "x" << move.getTo().y;

                this->playerW->clearReady();
                if (!this->moveFigure(move)) {
                    continue;
                }

                this->onTurn = PLAYER_B;
            }
        } else {
            int can = this->playerB->isReady();
            if (can == false) {
                // Cant move right now (RealPlayer / Network async)
                return; // sleep
            } else {

                Move move = this->playerB->getMove();
                qDebug() << "PLAYER BLACK HAS TURNED : " << move.getFrom().x << "x" << move.getFrom().y << "   to    " << move.getTo().x << "x" << move.getTo().y;

                this->playerB->clearReady();
                if (!this->moveFigure(move)) {
                    continue;
                }

                this->onTurn = PLAYER_W;
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
    return this->onTurn;
}

Player * Checkers::getPlayerOnTurn() {
    if (this->getOnTurn() == PLAYER_W) {
        return this->playerW;
    } else if (this->getOnTurn() == PLAYER_B){
        return this->playerB;
    } else {
        return null;
    }
}
