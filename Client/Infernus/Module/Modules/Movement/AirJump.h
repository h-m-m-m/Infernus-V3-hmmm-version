#ifndef CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_AIRJUMP
#define CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_AIRJUMP

#include "../../Module.h"

class AirJump : public Module {
public:
    AirJump(Category* c) : Module(c, "AirJump", false) {
        //
    };
public:
    virtual auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_AIRJUMP */