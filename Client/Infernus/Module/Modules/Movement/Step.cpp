#include "Step.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto Step::onDisable(void) -> void {
    
    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);

    if(player != nullptr)
        return player->setStepHeight(0.5625);

};

auto Step::onGameMode(GameMode* GM) -> void {

    GM->player->setStepHeight(2.5625);

};