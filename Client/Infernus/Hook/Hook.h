#ifndef CLIENT_INFERNUS_HOOKS_HOOK
#define CLIENT_INFERNUS_HOOKS_HOOK

#include "../../Mem/Mem.h"
#include "../../Utils/Utils.h"

class Hook {
public:
    class Manager* manager = nullptr;
public:
    Hook(Manager*);
public:
    virtual auto init(void) -> void {};
};

#endif /* CLIENT_INFERNUS_HOOKS_HOOK */