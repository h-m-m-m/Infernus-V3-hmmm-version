#ifndef CLIENT_INFERNUS_MODULE_MODULES_OTHER_TESTMODULE
#define CLIENT_INFERNUS_MODULE_MODULES_OTHER_TESTMODULE

#include "../../Module.h"

class TestModule : public Module {
public:
    TestModule(Category* c) : Module(c, "Test Module") {
        this->setState(true);
    };
public:
    virtual auto onRender(void) -> void override;
    auto hasOptions() -> bool override;
    virtual auto onRenderOptions(void) -> void override;
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> then = std::chrono::high_resolution_clock::now();
    float currFps = 0.f;
private:
    auto updateAlpha(void) -> void;
    float alpha = 0.f;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_OTHER_TESTMODULE */