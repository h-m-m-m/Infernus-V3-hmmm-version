#include "Killaura.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto Killaura::onGameMode(GameMode* GM) -> void {
    auto player = GM->player;
    auto myPos = player->getPos();

    
    auto mgr = this->category->manager;
    for(auto [runtimeId, entity] : mgr->entityMap) {

        if(runtimeId == player->getRuntimeId())
            continue;
        
        auto entPos = entity->getPos();

        auto dX = myPos.x - entPos.x;
        auto dY = myPos.y - entPos.y;
        auto dZ = myPos.z - entPos.z;

        auto dist = sqrt(dX * dX + dY * dY + dZ * dZ);

        if(dist <= 12.f) {
            GM->attack(entity);
        };

    };
};