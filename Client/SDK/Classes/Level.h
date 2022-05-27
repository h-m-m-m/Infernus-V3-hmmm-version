#ifndef CLIENT_SDK_CLASSES_LEVEL
#define CLIENT_SDK_CLASSES_LEVEL

#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"

class Actor;

class Level {
public:
    uintptr_t** VTable;
public:
    auto getPrimaryLocalPlayer(void) -> Actor*;
    auto fetchEntity(uint64_t, bool) -> Actor*;
};

#endif /* CLIENT_SDK_CLASSES_LEVEL */