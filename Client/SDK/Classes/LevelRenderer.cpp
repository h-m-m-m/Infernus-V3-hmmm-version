#include "LevelRenderer.h"
#include "../Minecraft.h"

auto LevelRenderer::getOrigin(void) -> Vec3<float> {
    auto origin = Vec3<float>();

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            origin = *(Vec3<float>*)((uintptr_t)(this) + 0x888);
        break;
    };
    
    return origin;
};