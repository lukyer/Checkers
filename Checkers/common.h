#ifndef COMMON_H
#define COMMON_H

#define null 0

struct Position {
    int x;
    int y;
};

enum BoardTypes { NONE, FIGURE_W, FIGURE_B, QUEEN_W, QUEEN_B };
enum Players { NOBODY, PLAYER_W, PLAYER_B };
enum PlayerType { PLAYER_UNKNOWN, PLAYER_REAL, PLAYER_AI, PLAYER_NET };

#endif // COMMON_H
