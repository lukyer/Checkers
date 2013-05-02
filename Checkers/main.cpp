#include <QtGui/QApplication>
#include "checkerswindow.h"
#include <QTime>
#include <QDataStream>

// Pretizene operatory QDataStreamu aby pracovala nativne serializace GameSettings objektu pri posilani po siti
// nesmi se vicekrat definovat, napr. v common.h jinak problem

QDataStream &operator<<( QDataStream &out, const GameSettings &settings ) {
    out << (quint32) settings.color << settings.playerName;
    return out;
}

QDataStream &operator>>( QDataStream &in, GameSettings &settings ) {
    quint32 color;
    in >> color >> settings.playerName;
    settings.color = (PlayerColor) color;
    return in;
}

QDataStream &operator<<( QDataStream &out, Move &move ) {   // const tady delal nejake warningy
    out << (quint32) move.getFrom().x << (quint32) move.getFrom().y << (quint32) move.getTo().x << (quint32) move.getTo().y;
    return out;
}

QDataStream &operator>>( QDataStream &in, Move &move ) {
    quint32 fromX, fromY, toX, toY;
    in >> fromX >> fromY >> toX >> toY;
    move.setFrom({(int)fromX, (int)fromY});
    move.setTo({(int)toX, (int)toY});
    return in;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentMSecsSinceEpoch());

    CheckersWindow w;
    w.show();
    
    return a.exec();
}
