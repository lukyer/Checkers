#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "abstractplayer.h"
#include <QDebug>
#include <QCoreApplication>

class AIPlayer : public AbstractPlayer
{
public:
    AIPlayer(PlayerColor color);
    bool isReady();
    Move getMove();    
};

#endif // AIPLAYER_H
