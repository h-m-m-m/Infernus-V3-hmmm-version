#ifndef CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_SPEED
#define CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_SPEED

#include "../../Module.h"

class Speed : public Module {
public:
    Speed(Category* c) : Module(c, "Speed") {
        //
    };
public:
    virtual auto onGameMode(GameMode*) -> void override;
public:
    float speed = 0.6f;
    int msDelay = 0;
private:
    std::chrono::time_point<std::chrono::steady_clock> savedTime = std::chrono::high_resolution_clock::now();
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_MOVEMENT_SPEED */