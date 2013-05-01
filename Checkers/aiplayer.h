#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"
#include <QDebug>
#include <QCoreApplication>
#include <QTime>

class AIPlayer : public Player
{
public:
    AIPlayer();
    bool move() override;
    bool isReady();
    Move getMove();
};

#endif // AIPLAYER_H
