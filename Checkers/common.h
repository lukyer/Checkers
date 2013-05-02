#ifndef COMMON_H
#define COMMON_H

#include <QDataStream>


#define null 0


//QDataStream &operator>>(QDataStream &in, GameSettings &painting);


struct Position {
    int x;
    int y;
    bool operator==(const Position & pos) {
        if (x==pos.x && y == pos.y) {
            return true;
        } else {
            return false;
        }
    }
};

enum BoardTypes { NONE, FIGURE_W, FIGURE_B, QUEEN_W, QUEEN_B };
enum PlayerColor { NOBODY, PLAYER_W, PLAYER_B };
enum PlayerType { PLAYER_UNKNOWN, PLAYER_REAL, PLAYER_AI, PLAYER_NETWORK };
enum NetworkType { NETWORK_SERVER, NETWORK_CLIENT };
enum NetworkState { NETWORK_NONE, NETWORK_CONNECTED, NETWORK_SETUP_SENT, NETWORK_SETUP_RECEIVED, NETWORK_PLAYING, NETWORK_DONE };

struct GameSettings {
    PlayerColor color;
    QString playerName;
    // startovaci rozmisteni hry (moves[])
};

// Definice, deklarace je v main
QDataStream &operator<<(QDataStream &out, const GameSettings &settings);
QDataStream &operator>>(QDataStream &in, GameSettings &settings);

#endif // COMMON_H
