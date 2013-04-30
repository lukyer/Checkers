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


     this->setScene(scene);

}

void GUIBoard::redraw() {

    /* Zde jsme resili velky problem jak vykreslit po cele herni plose mrizku a pres ni pripadne figurky tak, at jsou figurky
       zvlaste selektovatelne objekty ... nakonec pomohlo spravne dedeni, volani parent konstruktoru A SPOJENI OBJEKTU
       PRI VYTVARENI PRES PARENT UKAZATEL.
       Nicmene stejne se musi udelat nejake pomocne objekty, viz nize
    */

    QGraphicsWidget *form = new QGraphicsWidget;

    for (int x = 0 ; x < 8 ; x++) {
        for (int y = 0; y < 8 ; y++) {
            BoardTypes squareType = checkers->getBoard(x,y);
            GUISquare *square = new GUISquare();  // reprezentuje graficky policko prazdne (obrys + drop eventy)
            square->setIndex({x,y});

            GUIFigure *fig;

            if (squareType == NONE) {
                // Na tomto policku neni NIC, takze pridame pouze empty GUISquare (kvuli obrysu ktery tvori mrizku + drop eventu)
            } else {
                // Je tam figurka, takze pridame objekt figurky a NASTAVIME PARENT na prazdne policko
                fig = new GUIFigure(square);    // DULEZITE: square je PARENT a tudiz se bude vykreslovat DO NEJ
                fig->setType(squareType);
                fig->setParent(square); // musime nastavit rodice, at muzeme pote na nej odkazovat. KONSTRUKTOR NESTACI
            }


            grid->addItem(square, 7-x, y); // 7-x protoze kreslime zvrchu dolu, ale pole mame zdola nahoru
            // Aby figurka nemusela mit pristup k pianu (top objekt Checkers), tak jen od ni vyzvedavame signaly v pripade interakce
            connect(fig, SIGNAL(wantMove(Position,QPointF)), this, SLOT(figureMove(Position,QPointF)));


        }
    }



    form->setLayout(grid);


    scene->addItem(form);

}



void GUIBoard::figureMove(Position index, QPointF to)
{
    qDebug() << "some figure moving " << index.x << "x" << index.y << " to " << to;
    GUISquare *cut1 = (GUISquare *) this->grid->itemAt(7-index.x,index.y);

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
