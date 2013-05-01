#ifndef COMMON_H
#define COMMON_H

#define null 0

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
enum PlayerType { PLAYER_UNKNOWN, PLAYER_REAL, PLAYER_AI, PLAYER_NET };


#endif // COMMON_H
