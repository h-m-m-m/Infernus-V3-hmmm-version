#include "Minecraft.h"

auto Minecraft::getClientInstance(void) -> ClientInstance* {
    static uintptr_t sig = NULL;

    if(!sig)
        sig = Mem::findSig("48 8B 15 ? ? ? ? 4C 8B 02 4C 89 06 40 84 FF ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8B C6 48 8B 4C 24 ? 48 33 CC E8 ? ? ? ? 48 8B 5C 24 ? 48 8B 74 24 ? 48 83 C4 ? 5F C3 E8 ? ? ? ? 90 CC CC CC CC CC CC CC CC CC 48 89 5C 24 ? 48 89 6C 24");
    
    auto offset = *reinterpret_cast<int*>(sig + 3);
    auto basePtr = (uintptr_t)(sig + offset + 7) - Mem::getGameModule();

    return (ClientInstance*)Mem::findMultiLvlPtr(basePtr, { 0x0, 0x48, 0x0 });
};

auto Minecraft::getLocalPlayer(void) -> Player* {
    auto player = (Player*)Mem::findMultiLvlPtr(0x0549E798, { 0x8, 0x20, 0xC8, 0x0 });
    auto level = (player != nullptr ? player->getLevel() : nullptr);
    return level != nullptr ? (Player*)level->getPrimaryLocalPlayer() : nullptr;
};