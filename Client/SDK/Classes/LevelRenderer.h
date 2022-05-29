#ifndef CLIENT_SDK_CLASSES_LEVELRENDERER
#define CLIENT_SDK_CLASSES_LEVELRENDERER

#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"

class LevelRenderer {
public:
    auto getOrigin(void) -> Vec3<float>;
};

#endif /* CLIENT_SDK_CLASSES_LEVELRENDERER */