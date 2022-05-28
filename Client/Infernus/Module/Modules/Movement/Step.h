#ifndef CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_STEP
#define CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_STEP

#include "../../Module.h"

class Step : public Module {
public:
    Step(Category* c) : Module(c, "Step") {
        //
    };
public:
    auto onDisable(void) -> void override;
    auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_STEP */