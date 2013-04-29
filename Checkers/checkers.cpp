#include "checkers.h"
#include <QDebug>

Checkers::Checkers()
{
    resetBoard();
    debugBoard();
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
