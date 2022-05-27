#ifndef CLIENT_INFERNUS_MODULE_MODULES_VISUALS_CLICKGUI
#define CLIENT_INFERNUS_MODULE_MODULES_VISUALS_CLICKGUI

#include "../../Module.h"

class ClickGui : public Module {
public:
    ClickGui(Category* c) : Module(c, "Click Gui") {
        this->setKey(VK_INSERT);
    };
public:
    virtual auto onRender(void) -> void override;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_VISUALS_CLICKGUI */