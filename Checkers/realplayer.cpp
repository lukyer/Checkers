#include "realplayer.h"

RealPlayer::RealPlayer(PlayerColor color) : AbstractPlayer(color) {
    name = "Nonamed REAL";
    this->setType(PLAYER_REAL);
}
