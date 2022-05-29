#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "GuiData.h"
#include "MinecraftGame.h"

class Player;

class ClientInstance {
private:
    uintptr_t** VTable;
public:
    auto getGuiData(void) -> GuiData*;
    auto getMinecraftGame(void) -> MinecraftGame*;
public:
    auto getLocalPlayer(void) -> Player*;
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */