#ifndef CLIENT_INFERNUS_MODULE_MODULES_VISUALS_NAMETAGS
#define CLIENT_INFERNUS_MODULE_MODULES_VISUALS_NAMETAGS

#include "../../Module.h"

class Nametags : public Module {
public:
    Nametags(Category* c) : Module(c, "Nametags", false) {
        this->setState(true);
    };
public:
    virtual auto onRender(void) -> void override;
};

#endif /* CLIENT_INFERNUS_MODULE_MODULES_VISUALS_NAMETAGS */