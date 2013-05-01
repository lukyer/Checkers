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

    Checkers *game1 = new Checkers();
    ui->board->setCheckers(game1);


    Player *player1 = new RealPlayer();
    game1->setPlayerW(player1);


    Player *player2 = new RealPlayer();
    game1->setPlayerB(player2);

    player1->setName("lukyer");
    player1->setCheckersGame(ui->board->getCheckers()->getGame()); // pro ziskavani possible tahu ... pokud uz neni zadny possible tah, oznamit prohru

    player2->setName("kulo");
    player2->setCheckersGame(ui->board->getCheckers()->getGame());











    QTimer *refresh = new QTimer(this);
    connect(refresh, SIGNAL(timeout()), ui->board, SLOT(redraw()));
    refresh->start(1000);

    /*
    QTimer *timeout = new QTimer(this);
    connect(timeout, SIGNAL(timeout()), ui->board, SLOT(timeout()));
    timeout->start(5000);
*/


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
