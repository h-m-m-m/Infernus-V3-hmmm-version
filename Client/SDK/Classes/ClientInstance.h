#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "GuiData.h"
#include "MinecraftGame.h"

class ClientInstance {
public:
    auto getGuiData(void) -> GuiData* {
        return *(GuiData**)((uintptr_t)(this) + 0x500);
    };
public:
    auto getMinecraftGame(void) -> MinecraftGame* {
        return *(MinecraftGame**)((uintptr_t)(this) + 0xA8);
    };
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */