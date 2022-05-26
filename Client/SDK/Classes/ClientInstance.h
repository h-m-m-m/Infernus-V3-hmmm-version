#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "GuiData.h"
#include "MinecraftGame.h"

class Player;

class ClientInstance {
public:
    auto getGuiData(void) -> GuiData* {
        return *(GuiData**)((uintptr_t)(this) + 0x500);
    };
public:
    auto getMinecraftGame(void) -> MinecraftGame* {
        return *(MinecraftGame**)((uintptr_t)(this) + 0xA8);
    };
public:
    inline Player* getLocalPlayer(void) {
        return (*(Player*(__fastcall**)(ClientInstance*))(*(__int64*)this + 192i64))(this);
    };
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */