#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <common.h>
#include "move.h"


class Player
{
public:
    Player();
    virtual void setName(QString);
    virtual void setType(PlayerType);
    virtual PlayerType getType();
    virtual QString getName();
    virtual bool move() = 0;
    virtual Move getMove();
    virtual bool isReady();
    virtual void setMove(Move);
    virtual void setReady();
    virtual void clearReady();
    virtual bool canMove();

protected:
    QString name;


private:
    PlayerType type = PLAYER_UNKNOWN;
    bool moveReady = false;
    Move movePosition;
};

#endif // PLAYER_H
