#ifndef CLIENT_INFERNUS_HOOK_HOOKS_ENTITY_ENTITY
#define CLIENT_INFERNUS_HOOK_HOOKS_ENTITY_ENTITY

#include "../../Hook.h"

class Entity_Hooks : public Hook {
public:
    Entity_Hooks(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    virtual auto init(void) -> void override;
};

#endif /* CLIENT_INFERNUS_HOOK_HOOKS_ENTITY_ENTITY */