#include <QtGui/QApplication>
#include "checkerswindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentMSecsSinceEpoch());

    CheckersWindow w;
    w.show();
    
    return a.exec();
}
