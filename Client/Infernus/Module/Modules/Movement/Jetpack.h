#ifndef CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_JETPACK
#define CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_JETPACK

#include "../../Module.h"

class Jetpack : public Module {
public:
    Jetpack(Category* c) : Module(c, "Jetpack") {
        this->setKey(0x46); /* F */
    };
public:
    virtual auto onTick(void) -> void override;
    virtual auto onGameMode(GameMode*) -> void override;
    virtual auto onRenderOptions(void) -> void override;
private:
    float speed = 1.4f;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_JETPACK */