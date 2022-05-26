#include "Actor.h"
#include "../Minecraft.h"

auto Actor::getLevel(void) -> Level* {
    static auto result = (Level*)nullptr;

    if(result == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                result = *(Level**)((uintptr_t)(this) + 0x368);
            break;
        };
    };

    return result;
};

auto Actor::getRuntimeId(void) -> uint64_t {
    auto res = (uint64_t)NULL;

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            res = *(uint64_t*)((uintptr_t)(this) + 0x550);
        break;
    };

    return res;
};