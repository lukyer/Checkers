#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <common.h>


class Player
{
public:
    Player();
    virtual void setName(QString);
    virtual void setType(PlayerType);
    virtual PlayerType getType();
    virtual QString getName();
    virtual bool move() = 0;
    virtual Position getMove();
    virtual bool isReady();
    virtual void setMove(Position);
    virtual void setReady();
    virtual void clearReady();

protected:
    QString name;


private:
    PlayerType type = PLAYER_UNKNOWN;
    bool moveReady = false;
    Position movePosition = {0,0};
};

#endif // PLAYER_H
