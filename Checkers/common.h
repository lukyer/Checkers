#ifndef COMMON_H
#define COMMON_H

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
enum Players { NOBODY, PLAYER_W, PLAYER_B };


#endif // COMMON_H
