#ifndef CLIENT_INFERNUS_MODULE_MODULES_PLAYER_AUTOSPRINT
#define CLIENT_INFERNUS_MODULE_MODULES_PLAYER_AUTOSPRINT

#include "../../Module.h"

class AutoSprint : public Module {
public:
    AutoSprint(Category* c) : Module(c, "AutoSprint", false) {
        //
    };
public:
    virtual auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_PLAYER_AUTOSPRINT */