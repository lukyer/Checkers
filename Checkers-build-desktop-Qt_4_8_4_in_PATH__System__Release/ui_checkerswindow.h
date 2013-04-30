/********************************************************************************
** Form generated from reading UI file 'checkerswindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKERSWINDOW_H
#define UI_CHECKERSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "guiboard.h"

QT_BEGIN_NAMESPACE

class Ui_CheckersWindow
{
public:
    QWidget *centralWidget;
    GUIBoard *board;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CheckersWindow)
    {
        if (CheckersWindow->objectName().isEmpty())
            CheckersWindow->setObjectName(QString::fromUtf8("CheckersWindow"));
        CheckersWindow->resize(400, 300);
        centralWidget = new QWidget(CheckersWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        board = new GUIBoard(centralWidget);
        board->setObjectName(QString::fromUtf8("board"));
        board->setGeometry(QRect(100, 50, 256, 192));
        CheckersWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CheckersWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 29));
        CheckersWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CheckersWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CheckersWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CheckersWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CheckersWindow->setStatusBar(statusBar);

        retranslateUi(CheckersWindow);

        QMetaObject::connectSlotsByName(CheckersWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CheckersWindow)
    {
        CheckersWindow->setWindowTitle(QApplication::translate("CheckersWindow", "CheckersWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CheckersWindow: public Ui_CheckersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKERSWINDOW_H
