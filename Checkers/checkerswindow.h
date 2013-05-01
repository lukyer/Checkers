#ifndef CHECKERSWINDOW_H
#define CHECKERSWINDOW_H

#include <QMainWindow>
#include "realplayer.h"

namespace Ui {
class CheckersWindow;
}

class CheckersWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CheckersWindow(QWidget *parent = 0);
    ~CheckersWindow();
    
private:
    Ui::CheckersWindow *ui;
};

#endif // CHECKERSWINDOW_H
