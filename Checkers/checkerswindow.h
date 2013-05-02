#ifndef CHECKERSWINDOW_H
#define CHECKERSWINDOW_H

#include <QMainWindow>
#include "realplayer.h"
#include "checkers.h"

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
    Checkers *checkers;

private slots:
    void on_actionPripoj_server_triggered();
    void on_actionVytvor_server_triggered();
    void on_actionNov_triggered();
};

#endif // CHECKERSWINDOW_H
