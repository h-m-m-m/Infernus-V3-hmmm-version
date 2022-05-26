#ifndef CLIENT_INFERNUS_MODULE_MODULES_OTHER_UNINJECT
#define CLIENT_INFERNUS_MODULE_MODULES_OTHER_UNINJECT

#include "../../Module.h"

class Uninject : public Module {
public:
    Uninject(Category* c) : Module(c, "Uninject") {
        //
    };
public:
    virtual auto onEnable(void) -> void override;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_OTHER_UNINJECT */