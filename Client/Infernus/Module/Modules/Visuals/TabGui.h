#ifndef CLIENT_INFERNUS_MODULE_MODULES_VISUALS_TABGUI
#define CLIENT_INFERNUS_MODULE_MODULES_VISUALS_TABGUI

#include "../../Module.h"

class TabGui : public Module {
public:
    TabGui(Category* c) : Module(c, "TabGui") {
        this->setKey(VK_TAB);
        this->setState(true);
    };
public:
    virtual auto onRender(void) -> void override;
    virtual auto onKey(uint64_t, bool, bool*) -> void override;
private:
    int catIndex = 0, modIndex = 0;
    bool selectedCat = false, selectedMod = false;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_VISUALS_TABGUI */