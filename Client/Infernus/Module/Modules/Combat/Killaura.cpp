#include "Killaura.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto Killaura::onGameMode(GameMode* GM) -> void {
    if(msDelay > 0 && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) <= std::chrono::milliseconds((int)msDelay))
        return;
    
    savedTime = std::chrono::high_resolution_clock::now();
    
    auto player = GM->player;
    auto myPos = player->getPos();

    
    auto mgr = this->category->manager;
    auto distances = std::vector<float>();

    for(auto [runtimeId, entity] : mgr->entityMap) {

        if(runtimeId == player->getRuntimeId() || !entity->isAlive() || !entity->isMob() || !player->canAttack(entity, false))
            continue;
        
        auto entPos = entity->getPos();

        auto dX = myPos.x - entPos.x;
        auto dY = myPos.y - entPos.y;
        auto dZ = myPos.z - entPos.z;

        auto dist = sqrt(dX * dX + dY * dY + dZ * dZ);

        if(dist <= 12.f)
            distances.push_back(dist);
        
    };

    std::sort(distances.begin(), distances.end());

    if(distances.empty())
        return;
    
    auto I = 0;
    for(auto [runtimeId, entity] : mgr->entityMap) {

        if(runtimeId == player->getRuntimeId() || !entity->isAlive() || !entity->isMob() || !player->canAttack(entity, false))
            continue;
        
        if(I >= 2)
            break;
        
        auto entPos = entity->getPos();

        auto dX = myPos.x - entPos.x;
        auto dY = myPos.y - entPos.y;
        auto dZ = myPos.z - entPos.z;

        auto dist = sqrt(dX * dX + dY * dY + dZ * dZ);

        if(dist == distances[0] || (distances.size() > 1 ? dist == distances[0] : dist == distances[1]) || (distances.size() > 2 ? dist == distances[1] : dist == distances[2])) {
            GM->attack(entity);
            player->swing();
            I++;
        };
        
    };
};