#ifndef CLIENT_INFERNUS_MODULE_MODULES_OTHER_TESTMODULE
#define CLIENT_INFERNUS_MODULE_MODULES_OTHER_TESTMODULE

#include "../../Module.h"

class TestModule : public Module {
public:
    TestModule(Category* c) : Module(c, "Test Module") {
        this->isEnabled = true;
    };
public:
    virtual auto onRender(void) -> void override;
    virtual auto onRenderOptions(void) -> void override;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_OTHER_TESTMODULE */