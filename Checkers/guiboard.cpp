#include "guiboard.h"

GUIBoard::GUIBoard(QWidget *parent) : QGraphicsView(parent)
{
/*    scene = new QGraphicsScene(this);
    this->setScene(scene);

    GUIFigure *test = new GUIFigure(this);



     scene->addItem(test);*/





     scene = new QGraphicsScene(this);
     grid = new QGraphicsGridLayout();
     grid->columnSpacing(0);
     grid->rowSpacing(0);
     grid->setHorizontalSpacing(0);
     grid->setVerticalSpacing(0);




     QGraphicsWidget *form = new QGraphicsWidget;
     form->setLayout(grid);
     scene->addItem(form);

     this->setScene(scene);


     /* Vygenerovat vsechny policka + vsechny figurky.
        Pro kazde policko bude vygenerovana figurka (stejny pocet jako policek)
        ale muze mit nastaveno dead, tzn ze se nevykresluje. Je to kvuli snadnemu
        zobrazeni figurek v redraw() */

     for (int x = 0 ; x < 8 ; x++) {
         for (int y = 0; y < 8 ; y++) {

             GUISquare *square = new GUISquare();  // reprezentuje graficky policko prazdne (obrys + drop eventy)
             square->setIndex({x,y});

                /*
             GUIFigure *fig = new GUIFigure(square);    // DULEZITE: square je PARENT a tudiz se bude vykreslovat DO NEJ
             fig->setType(NONE);
             fig->setParent(square); // musime nastavit rodice, at muzeme pote na nej odkazovat. KONSTRUKTOR NESTACI
                */
             grid->addItem(square, 7-x, y); // 7-x protoze kreslime zvrchu dolu, ale pole mame zdola nahoru
             // Aby figurka nemusela mit pristup k pianu (top objekt Checkers), tak jen od ni vyzvedavame signaly v pripade interakce
             connect(square, SIGNAL(wantMove(Move, PlayerType)), this, SLOT(figureMove(Move, PlayerType)));

         }
     }

}

void GUIBoard::redraw() {

    /* Zde jsme resili velky problem jak vykreslit po cele herni plose mrizku a pres ni pripadne figurky tak, at jsou figurky
       zvlaste selektovatelne objekty ... nakonec pomohlo spravne dedeni, volani parent konstruktoru A SPOJENI OBJEKTU
       PRI VYTVARENI PRES PARENT UKAZATEL.
       Nicmene stejne se musi udelat nejake pomocne objekty, viz nize
    */



    for (int x = 0 ; x < 8 ; x++) {
        for (int y = 0; y < 8 ; y++) {
            Position pos{x,y};
            BoardTypes squareType = checkers->getBoard(pos);

            GUISquare *square = (GUISquare *)grid->itemAt(7-x, y);
            square->delFigure();    // uvolni figurku ktera je na policku ted, pokud nejaka

            if (squareType != NONE) {
                square->addFigure(squareType);  // pridej novou s timto typem
                if (checkers->isGameOver()) {
                    // Pokud uz skoncila hra, nastavime vsem figurkam at neemituji signaly drag atd.
                    square->emitSignals(false);
                }
            }
        }
    }





}

void GUIBoard::timeout()
{
    qDebug() << " TIMEOOOOUT ";
    this->checkers->resetGame();
    this->redraw();
}

void GUIBoard::settingsReceived(GameSettings settings)
{

    AbstractPlayer *player1;
    AbstractPlayer *player2;
    if (settings.color == PLAYER_W) {
        player1 = new NetworkPlayer(PLAYER_W);
        player1->setName("lukyer");
        player2 = new RealPlayer(PLAYER_B);
        player2->setName("kulo");
        qDebug() << "SETTINGS HAS ARRIVED!" << " MY COLOR IS BLACK";
    } else {
        player1 = new RealPlayer(PLAYER_W);
        player1->setName("lukyer");
        player2 = new NetworkPlayer(PLAYER_B);
        player2->setName("kulo");
        qDebug() << "SETTINGS HAS ARRIVED!" << " MY COLOR IS WHITE";
    }
    checkers->setPlayerW(player1);
    checkers->setPlayerB(player2);

    player1->setCheckersGame(checkers->getGame()); // pro ziskavani possible tahu ... pokud uz neni zadny possible tah, oznamit prohru
    player2->setCheckersGame(checkers->getGame());









    checkers->resetGame();
}



void GUIBoard::figureMove(Move move, PlayerType type)
{
    // Tento slot se vola i kdyz tahne network player a proto musim delat tak, at je dovoleno tahnout i za protihrace ktery je NETWORK jakoby
    // Jenze to by mohl potom tahnout i pres GUI za sitoveho hrace hrac realny, takze dalsi parametr tohoto slotu musi byt kdo signal emitnul,
    // jestli hrac real nebo network
    Position from = move.getFrom();
    Position to = move.getTo();
    qDebug() << "some figure moving " << from.x << "x" << from.y << " to " << to.x << "x" << to.y;
    Move change = Move(from, to);

    //bool moved = this->checkers->moveFigure(change);
    AbstractPlayer *turnPlayer = this->checkers->getPlayerOnTurn();
    if (turnPlayer->getType() != type) {
        qDebug() << "You're not allowed to control this player!";
        return;   // not allowed
    }
    turnPlayer->setMove(change);
    turnPlayer->setReady();
    this->checkers->play();
    this->redraw();

    /*
    if (moved) {
        qDebug() << "IT IS OK";
        this->redraw();
        this->checkers->play();
    } else {
        qDebug() << "WRONG MOVE";
    }
    */


    //GUISquare *cut1 = (GUISquare *) this->grid->itemAt(7-index.x,index.y);

    //cut1->test = true;
    //this->scene->update();
    //qDebug() << this->grid->;
}

/*
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
*/

void GUIBoard::setCheckers(Checkers * ch) {
    this->checkers = ch;
}

Checkers *GUIBoard::getCheckers()
{
    return this->checkers;
}
