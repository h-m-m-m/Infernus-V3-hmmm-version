#include "Player.h"

auto Player::setPlayerGameType(int type) -> void {
    using SetPlayerGameType = void (__thiscall*)(Player*, int);
    static auto _SetPlayerGameType = (SetPlayerGameType)nullptr;

    if(_SetPlayerGameType == nullptr)
        _SetPlayerGameType = (SetPlayerGameType)Mem::findSig("48 89 5C 24 10 48 89 6C 24 18 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 8B");
    
    if(_SetPlayerGameType != nullptr)
        _SetPlayerGameType(this, type);
};