#ifndef CLIENT_SDK_CLASSES_LEVEL
#define CLIENT_SDK_CLASSES_LEVEL

#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"

class Level {
public:
    uintptr_t** VTable;
public:
    auto getPrimaryLocalPlayer(void) -> class Actor*;
};

#endif /* CLIENT_SDK_CLASSES_LEVEL */