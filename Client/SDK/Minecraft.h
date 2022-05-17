#ifndef CLIENT_SDK_MINECRAFT
#define CLIENT_SDK_MINECRAFT

#include "Classes/ClientInstance.h"
#include "../Utils/Utils.h"
#include "../Mem/Mem.h"

class Minecraft {
public:
    static auto getClientInstance(void) -> ClientInstance*;
};

#endif /* CLIENT_SDK_MINECRAFT */