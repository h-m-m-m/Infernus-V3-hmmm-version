#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "GuiData.h"

class ClientInstance {
public:
    auto getGuiData(void) -> GuiData* {
        return *(GuiData**)((uintptr_t)(this) + 0x500);
    };
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */