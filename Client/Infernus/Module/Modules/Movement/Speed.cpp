#include "Speed.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto Speed::onGameMode(GameMode* GM) -> void {
    
    if(msDelay > 0 && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) <= std::chrono::milliseconds((int)msDelay))
        return;
    
    savedTime = std::chrono::high_resolution_clock::now();

    auto instance = Minecraft::getClientInstance();
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    if(mcGame == nullptr || !mcGame->canUseKeys)
        return;
    
    auto player = GM->player;
    auto bodyRot = player->getRot();

    auto mgr = this->category->manager;

    auto wKey = mgr->isHoldingKey(0x57);
    auto sKey = mgr->isHoldingKey(0x53);
    auto aKey = mgr->isHoldingKey(0x41);
    auto dKey = mgr->isHoldingKey(0x44);

    if(!wKey && !sKey && !dKey && !aKey)
        return;
    
    auto yaw = bodyRot.y;

    if (wKey) {
        if (!aKey && !dKey) {
            yaw += 90.f;
        }
        else if (aKey) {
            yaw += 45.f;
        }
        else if (dKey) {
            yaw += 135.f;
        }
    }
    else if (sKey) {
        if (!aKey && !dKey) {
            yaw -= 90.f;
        }
        else if (aKey) {
            yaw -= 45.f;
        }
        else if (dKey) {
            yaw -= 135.f;
        }
    }
    else if (!wKey && !sKey) {
        if (dKey) yaw += 180.f;
    };
    
    auto currMotion = player->getMotion();
    player->setMotion(Vec3<float>(cos((yaw) * (3.14 / 180.f)) * speed, currMotion.y, sin((yaw) * (3.14 / 180.f)) * speed));

};