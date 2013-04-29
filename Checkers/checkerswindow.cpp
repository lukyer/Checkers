#include "checkerswindow.h"
#include "ui_checkerswindow.h"

CheckersWindow::CheckersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckersWindow)
{
    ui->setupUi(this);
}

CheckersWindow::~CheckersWindow()
{
    delete ui;
}
