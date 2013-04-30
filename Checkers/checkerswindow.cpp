#include "checkerswindow.h"
#include "ui_checkerswindow.h"
#include "checkers.h"
#include "realplayer.h"

CheckersWindow::CheckersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckersWindow)
{
    ui->setupUi(this);



    Player *player1 = new RealPlayer();
    player1->setName("lukyer");

    Player *player2 = new AIPlayer();
    player2->setName("kulo");

    Checkers *game1 = new Checkers();
    game1->setPlayerW(player1);
    game1->setPlayerB(player2);


    ui->board->setCheckers(game1);
    game1->play();



}

CheckersWindow::~CheckersWindow()
{
    delete ui;
}
