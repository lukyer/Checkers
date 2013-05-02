#ifndef TESTNOTATION_H
#define TESTNOTATION_H

#include "notation.h"

class TestNotation : public Notation
{
public:
    TestNotation();
private:
    void convert(QVector<Move>);
};

#endif // TESTNOTATION_H
