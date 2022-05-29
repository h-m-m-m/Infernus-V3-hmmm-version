#include "Hitbox.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto Hitbox::onDisable(void) -> void {
    
    auto mgr = this->category->manager;
    auto entityMap = mgr->entityMap;

    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);

    if(player == nullptr)
        return;
    
    for(auto [runtimeId, entity] : entityMap) {
        
        auto entityTypeId = entity->getEntityTypeId();
        
        if(!this->collisionMap.contains(entityTypeId))
            continue;
        
        auto entitySize = this->collisionMap[entityTypeId];
        entity->setSize(entitySize.x, entitySize.y);

    };

};

auto Hitbox::onGameMode(GameMode* GM) -> void {
    
    auto mgr = this->category->manager;
    auto entityMap = mgr->entityMap;
    auto player = GM->player;

    for(auto [runtimeId, entity] : entityMap) {
        
        auto entityTypeId = entity->getEntityTypeId();
        
        if(!this->collisionMap.contains(entityTypeId))
            this->collisionMap[entityTypeId] = entity->getSize();
        
        entity->setSize(this->width, this->height);

    };

};

auto Hitbox::hasOptions() -> bool {
    return true;
}

auto Hitbox::onRenderOptions(void) -> void {
    
    ImGui::SliderFloat("Width", &this->width, 0.6, 6.f);
    ImGui::SliderFloat("Height", &this->height, 1.8, 6.f);

};