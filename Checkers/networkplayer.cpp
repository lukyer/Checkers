#include "networkplayer.h"


NetworkPlayer::NetworkPlayer(PlayerColor color) : AbstractPlayer(color) {
    name = "Nonamed NETWORK";
    this->setType(PLAYER_NETWORK);
}
