#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <common.h>
#include "move.h"
#include "checkersgame.h"


class AbstractPlayer
{
public:
    AbstractPlayer(PlayerColor);
    virtual void setName(QString);
    virtual void setType(PlayerType);
    virtual PlayerType getType();
    virtual QString getName();
    virtual Move getMove();
    virtual bool isReady();
    virtual void setMove(Move);
    virtual void setReady();
    virtual void clearReady();
    virtual bool canMove();
    void setCheckersGame(CheckersGame *game);
    PlayerColor getColor();

protected:
    QString name;
    CheckersGame *game;
    PlayerColor color;


private:
    PlayerType type = PLAYER_UNKNOWN;
    bool moveReady = false;
    Move movePosition;
};

#endif // PLAYER_H
