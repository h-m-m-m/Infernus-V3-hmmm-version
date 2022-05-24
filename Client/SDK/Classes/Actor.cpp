#include "Actor.h"

auto Actor::getLevel(void) -> Level* {
    return *(Level**)((uintptr_t)(this) + 0x368);
};