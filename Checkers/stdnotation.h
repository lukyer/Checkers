#ifndef STDNOTATION_H
#define STDNOTATION_H

//#include <QString>
#include "notation.h"

class StdNotation : public Notation
{
public:
    StdNotation();
private:
    void convert(QVector<Move>);
    void saveGame(QString);
    QVector<Move> loadGame(QString);
};

#endif // STDNOTATION_H
