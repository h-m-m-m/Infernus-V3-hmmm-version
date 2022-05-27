#ifndef CLIENT_SDK_CLASSES_ACTOR
#define CLIENT_SDK_CLASSES_ACTOR

#include "Level.h"

class Actor {
public:
    uintptr_t** VTable;
public:
    auto getLevel(void) -> Level*;
public:
    auto getRuntimeId(void) -> uint64_t;
    auto getPos(void) -> Vec3<float>;
    auto outOfWorld(void) -> bool;
    auto canAttack(Actor*, bool) -> bool;
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */