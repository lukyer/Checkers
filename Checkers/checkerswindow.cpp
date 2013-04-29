#include "checkerswindow.h"
#include "ui_checkerswindow.h"
#include "checkers.h"

CheckersWindow::CheckersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckersWindow)
{
    ui->setupUi(this);



    Checkers abc = Checkers();
}

CheckersWindow::~CheckersWindow()
{
    delete ui;
}
