#include "checkerswindow.h"
#include "ui_checkerswindow.h"
#include "checkers.h"
#include "realplayer.h"
#include "networkplayer.h"
#include "guisquare.h"
#include "networkplayer.h"

CheckersWindow::CheckersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckersWindow)
{
    ui->setupUi(this);

    checkers = new Checkers();
    ui->board->setCheckers(checkers);





    /* Startuju network hrace */
    // Musim zajistit at ma naplnene move vcas (tj jak prijdou po siti)
    // V teto situaci zatim ja chci hrat, ja jsem iniciator a tudiz ten druhy clovek na siti je SERVER

    // tady muzu zachytit emitnuty signal connectServerFailed pro nejaky progress zobrazeni

    /* *** */

    connect(checkers->getNetwork(), SIGNAL(moveReady(Move, PlayerType)), ui->board, SLOT(figureMove(Move, PlayerType)));
    connect(checkers->getNetwork(), SIGNAL(settingsReceived(GameSettings)), ui->board, SLOT(settingsReceived(GameSettings)));

    QTimer *refresh = new QTimer(this);
    connect(refresh, SIGNAL(timeout()), ui->board, SLOT(redraw()));
    refresh->start(1000);




    /*
    QTimer *timeout = new QTimer(this);
    connect(timeout, SIGNAL(timeout()), ui->board, SLOT(timeout()));
    timeout->start(5000);
*/



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





void CheckersWindow::on_actionPripoj_server_triggered()
{
    GameSettings settings;
    settings.color = PLAYER_W; // pripojujici se ma vzdy hlavni slovo a jeho barva bude respektovana. Server bude mit opacnou!
    settings.playerName = "lukyer";

    checkers->getNetwork()->setMySettings(settings);
    checkers->getNetwork()->connectServer("127.0.0.1", 5555);

}

void CheckersWindow::on_actionVytvor_server_triggered()
{
    GameSettings settings;
    settings.color = PLAYER_W;
    settings.playerName = "kulo";





    checkers->getNetwork()->setMySettings(settings);
    checkers->getNetwork()->establishServer();
}

void CheckersWindow::on_actionNov_triggered()
{
    QDialog *test = new QDialog(this, Qt::Popup);
    // tady se musi podedit QDialog do naseho SettingsDialog a pak se bude otevirat / zavirat ...
    test->open();
}
