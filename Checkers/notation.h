#ifndef NOTATION_H
#define NOTATION_H

#include <QString>
#include <QFile>
#include "move.h"

class Notation
{
public:
    Notation();
    virtual void convert(QVector<Move>);
    virtual void saveGame(QString);
    virtual QVector<Move> loadGame(QString);
    void debugNotation();
    QString getText();
protected:
    QString text;

};

#endif // NOTATION_H
