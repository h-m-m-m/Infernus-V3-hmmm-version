#include "Minecraft.h"

MC_VER Minecraft::mcVer = MC_VER::Unknown;

auto Minecraft::getVersion(void) -> std::pair<std::string, MC_VER> {
    auto res = std::pair<std::string, MC_VER>(Minecraft::getVersion(mcVer), mcVer);

    if(Minecraft::mcVer == MC_VER::Unknown) {
        std::vector<uintptr_t> versions = {
            
            /* 1.18.31 */
            
            Mem::findSig("31 2E 31 38 2E 33 31 00")

            /* :D */

        };

        for(auto ptr : versions) {
            if(ptr == NULL)
                continue;
            
            auto ver = (std::string*)ptr;
            auto curr = Minecraft::getVersion(*ver);
            
            if(curr != MC_VER::Unknown)
                res = std::pair<std::string, MC_VER>(Minecraft::getVersion(curr), curr);
        };
    };

    return res;
};

auto Minecraft::getVersion(std::string ver) -> MC_VER {
    auto res = MC_VER::Unknown;

    if(ver.rfind("1.18.31") != std::string::npos)
        res = MC_VER::v1_18_31;
    
    return res;
};

auto Minecraft::getVersion(MC_VER ver) -> std::string {
    auto res = std::string("Unknown");

    switch(ver) {
        case MC_VER::v1_18_31:
            res = "1.18.31";
        break;
    };

    return res;
};

auto Minecraft::setVersion(void) -> void {
    auto result = Minecraft::getVersion();

    if(mcVer == MC_VER::Unknown && result.second != MC_VER::Unknown) {
        Utils::debugLog("Minecraft SDK version: " + result.first);
        mcVer = result.second;
    };
};

auto Minecraft::getClientInstance(void) -> ClientInstance* {
    static uintptr_t sig = NULL;

    if(!sig)
        sig = Mem::findSig("48 8B 15 ? ? ? ? 4C 8B 02 4C 89 06 40 84 FF ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8B C6 48 8B 4C 24 ? 48 33 CC E8 ? ? ? ? 48 8B 5C 24 ? 48 8B 74 24 ? 48 83 C4 ? 5F C3 E8 ? ? ? ? 90 CC CC CC CC CC CC CC CC CC 48 89 5C 24 ? 48 89 6C 24");
    
    auto offset = *reinterpret_cast<int*>(sig + 3);
    auto basePtr = (uintptr_t)(sig + offset + 7) - Mem::getGameModule();

    return (ClientInstance*)Mem::findMultiLvlPtr(basePtr, { 0x0, 0x48, 0x0 });
};