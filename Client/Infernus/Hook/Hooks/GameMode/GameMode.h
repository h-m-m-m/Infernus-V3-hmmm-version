#ifndef CLIENT_INFERNUS_HOOKS_HOOKS_GAMEMODE_GAMEMODE
#define CLIENT_INFERNUS_HOOKS_HOOKS_GAMEMODE_GAMEMODE

class GameMode; /* Temporary */

#include "../../Hook.h"

class GameMode_Hook : public Hook {
public:
    GameMode_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    virtual auto init(void) -> void override;
};

#endif /* CLIENT_INFERNUS_HOOKS_HOOKS_GAMEMODE_GAMEMODE */