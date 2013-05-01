#include "checkersgame.h"

CheckersGame::CheckersGame()
{
        resetBoard();
}


void CheckersGame::resetBoard() {
    memcpy(&board, BOARD_INITIAL, sizeof(BOARD_INITIAL));
}

QVector<Move> CheckersGame::getPossibleMoves(Players player) {

    QVector<Move> possibleMoves;
    QVector<Move> possibleJumps;
    Position      from;
    Position      to;
    BoardTypes    tempFigure;
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

BoardTypes CheckersGame::getBoard(Position pos)
{
      if (pos.x < 0 || pos.x > 7 || pos.y < 0 || pos.y > 7) throw "Coords not valid.";
      return this->board[pos.x][pos.y];
}




bool CheckersGame::updateBoard(Move move) {

    std::pair<BoardTypes,Position> takenFigure;
    BoardTypes tempFigure;

    takenFigure = getTakenFigure(move);


    tempFigure = board[move.getFrom().x][move.getFrom().y];
    board[move.getFrom().x][move.getFrom().y] = NONE;

    qDebug() << "taken:" << takenFigure.first << takenFigure.second.x << takenFigure.second.y;

    if (takenFigure.first > 0) {
        board[takenFigure.second.x][takenFigure.second.y] = NONE;
    }

    if (!changeToQueen(move)) {
        board[move.getTo().x][move.getTo().y] = tempFigure;
    }


    return true;
}

bool CheckersGame::inBoard(Position pos) {
    if (pos.x < 0 || pos.x > 7 || pos.y < 0 || pos.y> 7 ) {
        return false;
    } else {
        return true;
    }
}


bool CheckersGame::changeToQueen(Move move) {

    if (move.getTo().x == 7 && board[move.getFrom().x][move.getFrom().y] == FIGURE_W /*onTurn == PLAYER_W*/) {//bila dama
        board[move.getTo().x][move.getTo().y] = QUEEN_W;
        return true;
    }
    if (move.getTo().x == 0 && board[move.getFrom().x][move.getFrom().y] == FIGURE_B /*onTurn == PLAYER_B*/) {//cerna dama
        board[move.getTo().x][move.getTo().y] = QUEEN_B;
        return true;
    }

    return false;

}


std::pair<BoardTypes,Position> CheckersGame::getTakenFigure(Move move) {

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
            return std::pair<BoardTypes,Position>(board[from.x][from.y],takenFigure);
        }
    }

    return std::pair<BoardTypes,Position>(NONE,takenFigure);


}

void CheckersGame::debugBoard() {
    qDebug() << "   0 1 2 3 4 5 6 7";
    for (int i = 0 ; i < 8 ; i++) {
        QString row;
        for (int j = 0 ; j < 8 ; j++) {
            row += QString::number(board[i][j]) + " ";
        }
        qDebug() << i << row;
    }
}
