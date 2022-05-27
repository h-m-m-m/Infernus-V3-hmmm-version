#ifndef CLIENT_INFERNUS_MODULE_MODULES_COMBAT_KILLAURA
#define CLIENT_INFERNUS_MODULE_MODULES_COMBAT_KILLAURA

#include "../../Module.h"

class Killaura : public Module {
public:
    Killaura(Category* c) : Module(c, "Killaura") {
        //
    };
public:
    virtual auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_COMBAT_KILLAURA */