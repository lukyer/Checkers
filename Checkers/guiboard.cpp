#include "guiboard.h"

GUIBoard::GUIBoard(QWidget *parent) : QGraphicsView(parent)
{

}

void GUIBoard::mousePressEvent(QMouseEvent * e) {
    if (this->checkers == null) {
        qDebug() << "No checkers set up!";
        return;
    }

    Position target = {5,2};


    if (e->x() < 150) {
        // White player move
        if (this->checkers->getOnTurn() == PLAYER_W) {
            // Ok, its my turn, but am i REAL player at all?
            if (this->checkers->getPlayerW()->getType() == PLAYER_REAL) {
                this->checkers->getPlayerW()->setMove(target);
                this->checkers->getPlayerW()->setReady();
                this->checkers->play();
            }
        }

    } else {
        // Black player move
        if (this->checkers->getOnTurn() == PLAYER_B) {
            // Ok, its my turn, but am i REAL player at all?
            if (this->checkers->getPlayerW()->getType() == PLAYER_REAL) {
                this->checkers->getPlayerB()->setMove(target);
                this->checkers->getPlayerB()->setReady();
                this->checkers->play();
            }
        }

    }

}

void GUIBoard::setCheckers(Checkers * ch) {
    this->checkers = ch;
}
