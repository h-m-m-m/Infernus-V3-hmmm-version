#ifndef CLIENT_SDK_CLASSES_ACTOR
#define CLIENT_SDK_CLASSES_ACTOR

#include "Level.h"

enum  ActorLocation;

class Actor {
public:
    auto getLevel(void) -> Level*;
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */