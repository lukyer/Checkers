#include "checkers.h"
<<<<<<< HEAD
#include <QDebug>
#include <algorithm>
#include <iterator>
=======
>>>>>>> c4575145f40a15276eb2ef35cc373413fab07491

Checkers::Checkers()
{
    resetBoard();
<<<<<<< HEAD
    /*debug testing*/
        debugBoard();

        QVector<Move> possiblemoves;
        Position first, second;
        first.x=6;
        first.y=4;
        second.x=7;
        second.y=5;

        Move move1(first,second);
        first.x=7;
        first.y=5;
        second.x=3;
        second.y=1;

        Move move2(first,second);
        onTurn = PLAYER_W;

        possiblemoves = getPossibleMoves(onTurn);
        debugMoveVec(possiblemoves);

        moveFigure(move1);
        possiblemoves = getPossibleMoves(onTurn);
        debugMoveVec(possiblemoves);

        moveFigure(move2);

    /*endof debug*/
=======
    debugBoard();
    this->onturn = PLAYER_W;    // white starts
}

BoardTypes Checkers::getBoard(int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) throw "Coords not valid.";
    return this->board[x][y];
>>>>>>> c4575145f40a15276eb2ef35cc373413fab07491
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
    int tempFigure;

    possibleMoves = getPossibleMoves(onTurn);
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
