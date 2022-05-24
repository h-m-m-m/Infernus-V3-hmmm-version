#ifndef CLIENT_SDK_MINECRAFT
#define CLIENT_SDK_MINECRAFT

#include "Classes/ClientInstance.h"
#include "Classes/Player.h"

#include "../Utils/Utils.h"
#include "../Mem/Mem.h"

class Minecraft {
public:
    static auto getClientInstance(void) -> ClientInstance*;
    static auto getLocalPlayer(void) -> Player*;
};

#endif /* CLIENT_SDK_MINECRAFT */