#include "AirJump.h"

auto AirJump::onGameMode(GameMode* GM) -> void {
    
    GM->player->setOnGround(true);

};