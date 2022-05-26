#ifndef CLIENT_SDK_MINECRAFT
#define CLIENT_SDK_MINECRAFT

#include "Classes/ClientInstance.h"
#include "Classes/Player.h"

#include "../Utils/Utils.h"
#include "../Mem/Mem.h"

enum class MC_VER {
    Unknown,
    v1_18_31
};

class Minecraft {
private:
    static MC_VER mcVer;
public:
    static auto getVersion(void) -> std::pair<std::string, MC_VER>;
    static auto getVersion(std::string) -> MC_VER;
    static auto getVersion(MC_VER) -> std::string;
public:
    static auto setVersion(void) -> void;
public:
    static auto getClientInstance(void) -> ClientInstance*;
    static auto getLocalPlayer(void) -> Player*;
};

#endif /* CLIENT_SDK_MINECRAFT */