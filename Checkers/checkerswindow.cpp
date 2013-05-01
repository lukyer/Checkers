#include "checkerswindow.h"
#include "ui_checkerswindow.h"
#include "checkers.h"
#include "realplayer.h"
#include "guisquare.h"

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
    ui->board->redraw();

    game1->play();
    /*

    QGraphicsRectItem *aa = new QGraphicsRectItem(QRect(0,0,100,100));
    aa->setFlag(QGraphicsRectItem::ItemIsMovable);
    QColor c = QColor(10,20,30);
    QBrush b = QBrush(c);
    aa->setBrush(b);
    aa->setZValue(99);

    QGraphicsRectItem *bb = new QGraphicsRectItem(QRect(90,90,100,100));
    bb->setFlag(QGraphicsRectItem::ItemIsMovable);
    c = QColor(120,11,120);
    b = QBrush(c);
    bb->setBrush(b);
    bb->setZValue(99);

    QGraphicsRectItem *cc = new QGraphicsRectItem(QRect(180,180,100,100));
    cc->setFlag(QGraphicsRectItem::ItemIsMovable);
    c = QColor(50,250,30);
    b = QBrush(c);
    cc->setBrush(b);
    cc->setZValue(99);

    ui->board->scene->addItem(aa);
    ui->board->scene->addItem(bb);
    ui->board->scene->addItem(cc);
    */

    //GUISquare *aa = new GUISquare(ui->widget);




}

CheckersWindow::~CheckersWindow()
{
    delete ui;
}
