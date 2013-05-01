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
enum Players { NOBODY, PLAYER_W, PLAYER_B };
<<<<<<< HEAD

=======
enum PlayerType { PLAYER_UNKNOWN, PLAYER_REAL, PLAYER_AI, PLAYER_NET };
>>>>>>> c4575145f40a15276eb2ef35cc373413fab07491

#endif // COMMON_H
