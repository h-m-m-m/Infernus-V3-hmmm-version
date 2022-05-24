#ifndef CLIENT_SDK_CLASSES_PLAYER
#define CLIENT_SDK_CLASSES_PLAYER

#include "Actor.h"
#include "GameMode.h"

class Player : public Actor {
public:
    auto setPlayerGameType(int) -> void;
};

#endif /* CLIENT_SDK_CLASSES_PLAYER */