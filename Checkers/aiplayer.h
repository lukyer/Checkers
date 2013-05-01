#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"
#include <QDebug>

class AIPlayer : public Player
{
public:
    AIPlayer();
    bool move() override;
    bool isReady();
    Position getMove();
};

#endif // AIPLAYER_H
