#include "checkers.h"




Checkers::Checkers()
{
    this->game = new CheckersGame();
    this->actualNotation = new StdNotation(); // defaultne standartni notace
    this->onTurn = PLAYER_W;    // white starts
    this->gameOver = false; // TODO: dokud nezacne hra, je povazovana za ukoncenou
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
        move = game->updateBoard(move);
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
            bool canMove = this->playerB->canMove(PLAYER_W);
            if (!canMove) {
                // Hrac nemuze udelat zadny tah => prohral
                this->endGame(PLAYER_B); // Black vyhral
                return;
            }
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
            bool canMove = this->playerB->canMove(PLAYER_B);
            if (!canMove) {
                // Hrac nemuze udelat zadny tah => prohral
                this->endGame(PLAYER_W); // White vyhral
                return;
            }
            bool isReady = this->playerB->isReady();
            if (isReady == false) {
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

void Checkers::resetGame()
{
    // Tady udelat prvotni inicializaci hry, connectnutych signalu, uvolneni ui atd
    game->resetBoard();
    onTurn = PLAYER_W;
    gameOver = false;
    play();
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

PlayerColor Checkers::getOnTurn() {
    return this->onTurn;
}

void Checkers::endGame(PlayerColor winner)
{
    // Musi se zrusit connect signalu ktere spousti play() atd!
    qDebug() << "********************";
    qDebug() << "GAME IS OVER!";
    if (winner == PLAYER_B) qDebug() << "PLAYER BLACK WIN " << this->playerB->getName();
    if (winner == PLAYER_W) qDebug() << "PLAYER WHITE WIN " << this->playerW->getName();
    if (winner == NONE) qDebug() << "!!!!!!!!!!!! NIKDO NEVYHRAL??? !!!!!!!!!!!!!!!!";
    qDebug() << "********************";
    //debugNotation(moves);

    //actualNotation->convert(moves);
    this->debugMoveVec(this->loadGame(STANDART,"karel.txt"));
    qDebug() << "nove/actual";
    this->debugMoveVec(moves);
    //actualNotation->debugNotation();
    //actualNotation->debugNotation();

    //this->saveGame();

    gameOver = true;
}

QVector<Move> Checkers::loadGame(NotationType notationType, QString fileName)
{
    Notation *notation;
    QVector<Move> move;

   switch (notationType) {
       case STANDART:
            notation = new StdNotation();
            break;
       case TEST:
            notation = new TestNotation();
            break;
       case XML:
            //notation = new XMLNotation();
            //break;
       default:
           qDebug() << "Wrong notation";
           break;

   }
   move = notation->loadGame(fileName);
   notation->debugNotation();
   return move;

}

Player * Checkers::getPlayerOnTurn() {
    if (this->getOnTurn() == PLAYER_W) {
        return this->playerW;
    } else if (this->getOnTurn() == PLAYER_B){
        return this->playerB;
    } else {
        throw "No player on turn !";
        return null;
    }
}

CheckersGame *Checkers::getGame()
{
    return this->game;
}

bool Checkers::isGameOver()
{
    return this->gameOver;
}

