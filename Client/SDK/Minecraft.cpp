#include "Minecraft.h"

auto Minecraft::getClientInstance(void) -> ClientInstance* {
    return (ClientInstance*)Mem::findMultiLvlPtr(0x05473C38, { 0x0, 0x48, 0x0 });
};