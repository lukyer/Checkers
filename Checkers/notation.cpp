#include "notation.h"

Notation::Notation()
{

}

void Notation::convert(QVector<Move>)
{
    qDebug() << "convert from NOTATION";

}

void Notation::saveGame(QString)
{
    qDebug() << "saveGame from NOTATION";
}

QVector<Move> Notation::loadGame(QString)
{
    qDebug() << "loadGame from NOTATION";
}

void Notation::debugNotation()
{
    qDebug() << text;
}

QString Notation::getText()
{
    return text;
}
