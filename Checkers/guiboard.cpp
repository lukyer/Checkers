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
             connect(square, SIGNAL(wantMove(Position,Position)), this, SLOT(figureMove(Position,Position)));

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
            BoardTypes squareType = checkers->getBoard(x,y);
            GUISquare *square = (GUISquare *)grid->itemAt(7-x, y);
            square->delFigure();    // uvolni figurku ktera je na policku ted, pokud nejaka

            if (squareType != NONE) {
                square->addFigure(squareType);  // pridej novou s timto typem
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



void GUIBoard::figureMove(Position from, Position to)
{
    qDebug() << "some figure moving " << from.x << "x" << from.y << " to " << to.x << "x" << to.y;
    Move change = Move(from, to);

    //bool moved = this->checkers->moveFigure(change);
    Player *turnPlayer = this->checkers->getPlayerOnTurn();
    if (turnPlayer == null) throw "No player on turn!!!";
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
