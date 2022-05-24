#ifndef CLIENT_INFERNUS_HOOK_HOOKS_KEY_KEY
#define CLIENT_INFERNUS_HOOK_HOOKS_KEY_KEY

#include "../../Hook.h"

class Key_Hook : public Hook {
public:
    Key_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    virtual auto init(void) -> void override;
};

#endif /* CLIENT_INFERNUS_HOOK_HOOKS_KEY_KEY */