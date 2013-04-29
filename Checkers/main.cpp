#include <QtGui/QApplication>
#include "checkerswindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CheckersWindow w;
    w.show();
    
    return a.exec();
}
