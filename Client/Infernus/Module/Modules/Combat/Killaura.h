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
private:
    int msDelay = 0;
    std::chrono::time_point<std::chrono::steady_clock> savedTime = std::chrono::high_resolution_clock::now();
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_COMBAT_KILLAURA */