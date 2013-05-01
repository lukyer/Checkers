#include "checkers.h"




Checkers::Checkers()
{
    resetBoard();
    this->onTurn = PLAYER_W;    // white starts
}

BoardTypes Checkers::getBoard(int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) throw "Coords not valid.";
    return this->board[x][y];
}

void Checkers::resetBoard() {
    memcpy(&board, BOARD_INITIAL, sizeof(BOARD_INITIAL));
}
/*debug*/
void Checkers::debugBoard() {
    qDebug() << "   0 1 2 3 4 5 6 7";
    for (int i = 0 ; i < 8 ; i++) {
        QString row;
        for (int j = 0 ; j < 8 ; j++) {
            row += QString::number(board[i][j]) + " ";
        }
        qDebug() << i << row;
    }
}

void Checkers::debugMoveVec(QVector<Move> v) {

    for(int i=0; i < v.size(); i++ ){
        qDebug() << "from" << v[i].getFrom().x << ":" << v[i].getFrom().y <<
                    "to:" << v[i].getTo().x   << ":" << v[i].getTo().y;
    }

}

/*endof debug*/

bool Checkers::moveFigure(Move move) {

    /*debug*/
   /*     int test = board[move.getFrom().x][move.getFrom().y];
        qDebug() << test;
        test = board[move.getTo().x][move.getTo().y];
        qDebug() << test;*/
    /*endof debug*/

    QVector<Move> possibleMoves;
    std::pair<int,Position> takenFigure;
    BoardTypes tempFigure;

    possibleMoves = getPossibleMoves(onTurn);

    debugMoveVec(possibleMoves);

    if (possibleMoves.contains(move)) {// po validnim tahu pridame move a zmenime board

        takenFigure = getTakenFigure(move);
        moves.append(move);

        tempFigure = board[move.getFrom().x][move.getFrom().y];
        board[move.getFrom().x][move.getFrom().y] = NONE;

        qDebug() << "taken:" << takenFigure.first << takenFigure.second.x << takenFigure.second.y;

        if (takenFigure.first > 0) {
            board[takenFigure.second.x][takenFigure.second.y] = NONE;
        }

        if (!changeToQueen(move)) {
            board[move.getTo().x][move.getTo().y] = tempFigure;
        }

    } else {
        qDebug() << "nevalidni tah";
        return false;
    }


    debugBoard();
    return true;
}


QVector<Move> Checkers::getPossibleMoves(int player) {

    QVector<Move> possibleMoves;
    QVector<Move> possibleJumps;
    Move          tempMove;
    Position      from;
    Position      to;
    int           tempFigure;
    int           diagDir[4][2] = {{1,1}, {1,-1}, {-1,-1}, {-1, 1}};

    for (from.x = 0; from.x < 8; from.x++ ) {
        for (from.y = 0; from.y < 8; from.y++ ) {

            tempFigure = board[from.x][from.y];

            if (tempFigure == NONE) {
                continue;
            } else if (player == PLAYER_W && tempFigure == FIGURE_W) {
                to.x = from.x + 1;
                to.y = from.y + 1;
                if (inBoard(to)) {
                    if (board[to.x][to.y] == NONE) { // pole bylo prazdne
                        possibleMoves.push_back(Move(from,to));
                    } else { // na poli je souperova figurka
                        if (board[to.x][to.y] == FIGURE_B || board[to.x][to.y] == QUEEN_B) {
                            to.x = from.x + 2;
                            to.y = from.y + 2;
                            if (inBoard(to)) {
                                if (board[to.x][to.y] == NONE) {
                                    possibleJumps.push_back(Move(from,to));
                                }
                            }
                        }
                    }
                }

                to.x = from.x + 1;
                to.y = from.y - 1;
                if (inBoard(to)) {
                    if (board[to.x][to.y] == NONE) { // pole bylo prazdne
                        possibleMoves.push_back(Move(from,to));
                    } else { // na poli je souperova figurka
                        if (board[to.x][to.y] == FIGURE_B || board[to.x][to.y] == QUEEN_B) {
                            to.x = from.x + 2;
                            to.y = from.y - 2;
                            if (inBoard(to)) {
                                if (board[to.x][to.y] == NONE) {
                                    possibleJumps.push_back(Move(from,to));
                                }
                            }
                        }
                    }
                }

            } else if (player == PLAYER_W && tempFigure == QUEEN_W) {
                  for (int dir = 0;dir < 4; dir++) { // vsechny 4 strany
                      to.x = from.x + diagDir[dir][0];
                      to.y = from.y + diagDir[dir][1];
                      while (inBoard(to)) {
                          if (board[to.x][to.y] == NONE) {
                              possibleMoves.push_back(Move(from,to));
                          } else if (board[to.x][to.y] == FIGURE_B || board[to.x][to.y] == QUEEN_B) {
                                  to.x = to.x + diagDir[dir][0];
                                  to.y = to.y + diagDir[dir][1];
                                  while (inBoard(to)) {
                                          if (board[to.x][to.y] == NONE) {
                                              possibleJumps.push_back(Move(from,to));
                                          } else {
                                              break;
                                          }
                                  to.x = to.x + diagDir[dir][0];
                                  to.y = to.y + diagDir[dir][1];
                                  }
                              } else {
                                  break;
                              }
                          to.x = to.x + diagDir[dir][0];
                          to.y = to.y + diagDir[dir][1];
                      }
                  }

            } else if (player == PLAYER_B && tempFigure == FIGURE_B) {
                to.x = from.x - 1;
                to.y = from.y - 1;
                if (inBoard(to)) {
                    if (board[to.x][to.y] == NONE) { // pole bylo prazdne
                        possibleMoves.push_back(Move(from,to));
                    } else { // na poli je souperova figurka
                        if (board[to.x][to.y] == FIGURE_W || board[to.x][to.y] == QUEEN_W) {
                            to.x = from.x - 2;
                            to.y = from.y - 2;
                            if (inBoard(to)) {
                                if (board[to.x][to.y] == NONE) {
                                    possibleJumps.push_back(Move(from,to));
                                }
                            }
                        }
                    }
                }

                to.x = from.x - 1;
                to.y = from.y + 1;
                if (inBoard(to)) {
                    if (board[to.x][to.y] == NONE) { // pole bylo prazdne
                        possibleMoves.push_back(Move(from,to));
                    } else { // na poli je souperova figurka
                        if (board[to.x][to.y] == FIGURE_W || board[to.x][to.y] == QUEEN_W) {
                            to.x = from.x - 2;
                            to.y = from.y + 2;
                            if (inBoard(to)) {
                                if (board[to.x][to.y] == NONE) {
                                    possibleJumps.push_back(Move(from,to));
                                }
                            }
                        }
                    }
                }

            } else if (player == PLAYER_B && tempFigure == QUEEN_B) {
                  for (int dir = 0;dir < 4; dir++) { // vsechny 4 strany
                      to.x = from.x + diagDir[dir][0];
                      to.y = from.y + diagDir[dir][1];
                      while (inBoard(to)) {
                          if (board[to.x][to.y] == NONE) {
                              possibleMoves.push_back(Move(from,to));

                          } else if (board[to.x][to.y] == FIGURE_W || board[to.x][to.y] == QUEEN_W) {
                                  to.x = to.x + diagDir[dir][0];
                                  to.y = to.y + diagDir[dir][1];

                                  while (inBoard(to)) {
                                          if (board[to.x][to.y] == NONE) {
                                              possibleJumps.push_back(Move(from,to));
                                          } else {
                                              break;
                                          }
                                  to.x = to.x + diagDir[dir][0];
                                  to.y = to.y + diagDir[dir][1];
                                  }
                              } else {
                                  break;
                              }
                          to.x = to.x + diagDir[dir][0];
                          to.y = to.y + diagDir[dir][1];
                      }
                  }
            } // end queenB
        } // end for y
    }//end for x

    if (possibleJumps.empty()) {
        return possibleMoves;
    } else {
        return possibleJumps;
    }

}


bool Checkers::inBoard(Position pos) {
    if (pos.x < 0 || pos.x > 7 || pos.y < 0 || pos.y> 7 ) {
        return false;
    } else {
        return true;
    }
}


bool Checkers::changeToQueen(Move move) {

    if (move.getTo().x == 7 && onTurn == PLAYER_W) {//bila dama
        board[move.getTo().x][move.getTo().y] = QUEEN_W;
        return true;
    }
    if (move.getTo().x == 0 && onTurn == PLAYER_B) {//cerna dama
        board[move.getTo().x][move.getTo().y] = QUEEN_B;
        return true;
    }

    return false;

}


std::pair<int,Position> Checkers::getTakenFigure(Move move) {

    Position from = move.getFrom();
    Position to = move.getTo();
    Position takenFigure;
    takenFigure.x = -1;
    takenFigure.y = -1;
    int      diagDir[4][2] = {{1,1}, {1,-1}, {-1, 1}, {-1, -1}};
    int      dir=0;

    if (from.x > to.x) {
        dir += 2;
    }
    if (from.y > to.y){
        dir += 1;
    }

    while (from.x != to.x && from.y != to.y) {
        from.x = from.x + diagDir[dir][0];
        from.y = from.y + diagDir[dir][1];
        if (board[from.x][from.y] != NONE) {
            takenFigure.x = from.x;
            takenFigure.y = from.y;
            return std::pair<int,Position>(board[from.x][from.y],takenFigure);
        }
    }

    return std::pair<int,Position>(0,takenFigure);


}

/* NEPOUZIVANA FCE
 * int je -1 neni diagonalni tah nebo je pres vice figurek
 * int je BoardTypes kdyz skace
 * Position je preskocena pozice, v pripade neskakani -1,-1
 */
std::pair<int, Position> Checkers::isOnDiagonal(Position from,Position to) {

    int x,y;
    int hopped;
    int hopCount;
    Position position;
    position.x = -1;
    position.y = -1;
    /*pouze po vlastni diagonale*/

    x = to.x;
    y = to.y;
    hopCount = 0;
    hopped = 0;
    while (x > 0 && y > 0) {

        x--;
        y--;

        if (x == from.x && y == from.y) {
            if (hopCount > 1) {
                return std::pair<int,Position>(-1,position);
            } else {
                return std::pair<int,Position>(hopped,position);
            }
        } else if (board[x][y] != NONE) {
            hopCount ++;
            hopped = board[x][y];
            position.x = x;
            position.y = y;
        }
    }

    x = to.x;
    y = to.y;
    hopCount = 0;
    hopped = 0;
    while (x < 7 && y < 7) {

        x++;
        y++;

        if (x == from.x && y == from.y) {
            if (hopCount > 1) {
                return std::pair<int,Position>(-1,position);
            } else {
                return std::pair<int,Position>(hopped,position);
            }
        } else if (board[x][y] != NONE) {
            hopCount ++;
            hopped = board[x][y];
            position.x = x;
            position.y = y;
        }
    }

    x = to.x;
    y = to.y;
    hopCount = 0;
    hopped = 0;
    while (x < 7 && y > 0) {
        x++;
        y--;

        if (x == from.x && y == from.y) {
            if (hopCount > 1) {
                return std::pair<int,Position>(-1,position);
            } else {
                return std::pair<int,Position>(hopped,position);
            }
        } else if (board[x][y] != NONE) {
            hopCount ++;
            hopped = board[x][y];
            position.x = x;
            position.y = y;
        }
    }

    x = to.x;
    y = to.y;
    hopCount = 0;
    hopped = 0;
    while (x > 0 && y < 7) {
        x--;
        y++;

        if (x == from.x && y == from.y) {
            if (hopCount > 1) {
                return std::pair<int,Position>(-1,position);
            } else {
                return std::pair<int,Position>(hopped,position);
            }
        } else if (board[x][y] != NONE) {
            hopCount ++;
            hopped = board[x][y];
            position.x = x;
            position.y = y;
        }
    }

   // qDebug() << hopCount << "hopcount" <<  hopped;

        return std::pair<int,Position>(-1,position);

    /*end diagonal check*/

}

bool Checkers::isValidMove(Move move) {
    //int x,y;
    int posFrom,posTo;
    std::pair<int, Position> preskoceno;
    Position from = move.getFrom();
    Position to = move.getTo();

    posFrom = board[from.x][from.y];
    posTo   = board[to.x][to.y];

    /* obe pozice musi zustat v poli
     * kontrolovat zde ci v const. Move? */
    if (from.x < 0) return false;
    if (from.x > 7) return false;
    if (from.y < 0) return false;
    if (from.y > 7) return false;
    if (to.x < 0) return false;
    if (to.x > 7) return false;
    if (to.y < 0) return false;
    if (to.y > 7) return false;

    /* tahnu nicim nebo na misto kde je figurka */
    if (posFrom == NONE || posTo != NONE) {
        return false;
    }
    /* bila figurka nebily hrac*/
    if (posFrom == FIGURE_W && onTurn != PLAYER_W ) {
        return false;
    }
    /* cerna figurka necerny hrac*/
    if (posFrom == FIGURE_B && onTurn != PLAYER_B ) {
        return false;
    }
    /*tahneme pouze po cernych polich*/
    if (from.x % 2 != from.y % 2) {
        return false;
    }
    if (to.x % 2 != to.y % 2) {
        return false;
    }

    /*kontroluju diagonalu a vratim co/jestli bylo preskoceno*/
    preskoceno = isOnDiagonal(from,to);
    if (preskoceno.first == -1) {
        return false;
    }

   // qDebug() << preskoceno.first << "preskoceno";

    /*tahneme obycejnym bilym kamenem, musime overit zda dopredu*/
    if (posFrom == FIGURE_W) {
        if (from.x >= to.x) {
            return false;
        } else if ((to.x - from.x) > 2) { // vic nez tah o 1 pole nebo preskok
            return false;
        } else if ((to.x - from.x) == 2) {
            if (preskoceno.first != FIGURE_B && preskoceno.first != QUEEN_B) {
                return false;
            }
        }
    }

    /*tahneme obycejnym cernym kamenem, musime overit zda "dozadu"*/
    if (posFrom == FIGURE_B) {
        if (from.x <= to.x) {
            return false;
        } else if ((from.x - to.x) > 2) { // vic nez tah o 1 pole nebo preskok
            return false;
        } else if ((from.x - to.x) == 2) {
            if (preskoceno.first != FIGURE_W && preskoceno.first != QUEEN_W) {
                return false;
            }
        }
    }


    /*smazu preskoceneho
     * nema tu co delat
     */
   /* if (preskoceno.first > 0) {
        board[preskoceno.second.x][preskoceno.second.y] = NONE;
    }*/

    return true;
}

void Checkers::makeMove(Position coords) {
    qDebug() << "I just moved ... " << this->onTurn << " x : " << coords.x << " y : " << coords.y;
}

void Checkers::play() {
    qDebug() << "ON TURN: " << this->onTurn;
    while (1) {

        if (this->onTurn == PLAYER_W) {
            bool canMove = this->playerB->canMove();
            if (!canMove) {
                // Hrac nemuze udelat zadny tah => prohral
                this->gameOver();
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
            bool canMove = this->playerB->canMove();
            if (!canMove) {
                // Hrac nemuze udelat zadny tah => prohral
                this->gameOver();
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
    resetBoard();
    onTurn = PLAYER_W;
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

Players Checkers::getOnTurn() {
    return this->onTurn;
}

void Checkers::gameOver()
{
    // Musi se zrusit connect signalu ktere spousti play() atd!
    qDebug() << "********************";
    qDebug() << "GAME IS OVER!";
    if (this->playerW->canMove()) qDebug() << "PLAYER BLACK WIN " << this->playerB->getName();
    if (this->playerB->canMove()) qDebug() << "PLAYER WHITE WIN " << this->playerW->getName();
    qDebug() << "********************";
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
