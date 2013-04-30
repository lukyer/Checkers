#ifndef REALPLAYER_H
#define REALPLAYER_H

#include <QDebug>
#include "player.h"

#include <aiplayer.h>


class RealPlayer :  public Player
{

public:
    RealPlayer();
    bool move() override;
    bool canMove();


};


#endif // REALPLAYER_H
