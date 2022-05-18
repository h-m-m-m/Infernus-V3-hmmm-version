#ifndef CLIENT_INFERNUS_HOOK_HOOKS_MOUSE_MOUSE
#define CLIENT_INFERNUS_HOOK_HOOKS_MOUSE_MOUSE

#include "../../Hook.h"

class Mouse_Hook : public Hook {
public:
    Mouse_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    virtual auto init(void) -> void override;
};

#endif /* CLIENT_INFERNUS_HOOK_HOOKS_MOUSE_MOUSE */
