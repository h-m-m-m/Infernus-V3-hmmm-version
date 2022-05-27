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

auto Actor::getPos(void) -> Vec3<float> {
    auto res = Vec3<float>();

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            res = *(Vec3<float>*)((uintptr_t)(this) + 0x4D8);
        break;
    };

    return res;
};

auto Actor::outOfWorld(void) -> bool {
    using OutOfWorld = bool (__thiscall*)(Actor*);
    static auto _OutOfWorld = (OutOfWorld)nullptr;

    if(_OutOfWorld == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _OutOfWorld = (OutOfWorld)(this->VTable[7]);
            break;
        };
    };

    return (_OutOfWorld != nullptr ? _OutOfWorld(this) : false);
};

auto Actor::canAttack(Actor* e, bool pB) -> bool {
    using CanAttack = bool (__thiscall*)(Actor*, Actor*, bool);
    static auto _CanAttack = (CanAttack)nullptr;

    if(_CanAttack == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _CanAttack = (CanAttack)(this->VTable[110]);
            break;
        };
    };

    return (_CanAttack != nullptr ? _CanAttack(this, e, pB) : false);
};