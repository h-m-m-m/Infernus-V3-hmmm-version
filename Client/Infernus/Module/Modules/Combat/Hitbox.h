#ifndef CLIENT_INFERNUS_MODULE_MODULES_COMBAT_HITBOX
#define CLIENT_INFERNUS_MODULE_MODULES_COMBAT_HITBOX

#include "../../Module.h"

class Hitbox : public Module {
public:
    Hitbox(Category* c) : Module(c, "Hitbox") {
        //
    };
public:
    virtual auto onDisable(void) -> void override;
    virtual auto onGameMode(GameMode*) -> void override;
    virtual auto onRenderOptions(void) -> void override;
private:
    float width = 2.f;
    float height = 2.f;
    std::map<uint8_t, Vec2<float>> collisionMap;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_COMBAT_HITBOX */