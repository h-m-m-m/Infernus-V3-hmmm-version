#include "Jetpack.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto Jetpack::onTick(void) -> void {
    auto mgr = this->category->manager;
    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    if(!mgr->isHoldingKey(this->key) || player == nullptr || mcGame == nullptr)
        return this->setState(false);
    
    if(!mcGame->canUseKeys)
        return this->setState(false);
};

auto Jetpack::onGameMode(GameMode* GM) -> void {
    if(!this->category->manager->isHoldingKey(this->key))
        return this->setState(false);
    
    auto player = GM->player;
    auto bodyRot = player->getRot();

    auto angles = Vec2<float>((bodyRot.x) * -(3.14f / 180.f), (bodyRot.y + 90.f) * 3.14f / 180.f);
    player->setMotion(Vec3<float>(cos(angles.y) * cos(angles.x) * speed, sin(angles.x) * speed, sin(angles.y) * cos(angles.x) * speed));
};

auto Jetpack::onRenderOptions(void) -> void {

    ImGui::SliderFloat("Speed", &this->speed, 0.1f, 10.f);

};