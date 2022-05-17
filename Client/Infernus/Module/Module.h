#ifndef CLIENT_INFERNUS_MODULE_MODULE
#define CLIENT_INFERNUS_MODULE_MODULE

#include "../../Mem/Mem.h"
#include "../../Utils/Utils.h"

#include "../../SDK/Minecraft.h"

class Module {
public:
    class Category* category = nullptr;
public:
    std::string name;
    bool isEnabled = false, wasEnabled = false;
    uint64_t key = NULL;
public:
    Module(Category*, std::string);
public:
    virtual auto onRender(void) -> void {};
};

#endif /* CLIENT_INFERNUS_MODULE_MODULE */