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

auto Actor::setPos(Vec3<float> pos) -> void {
    using SetPos = void (__thiscall*)(Actor*, Vec3<float>*);
    static auto _SetPos = (SetPos)nullptr;

    if(_SetPos == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _SetPos = (SetPos)(this->VTable[19]);
            break;
        };
    };

    if(_SetPos != nullptr)
        _SetPos(this, &pos);
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

auto Actor::getNameTag(void) -> std::string {
    using GetNameTag = std::string* (__thiscall*)(Actor*);
    static auto _GetNameTag = (GetNameTag)nullptr;

    if(_GetNameTag == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _GetNameTag = (GetNameTag)(this->VTable[63]);
            break;
        };
    };

    return (_GetNameTag != nullptr ? *_GetNameTag(this) : "");
};

auto Actor::isAlive(void) -> bool {
    using IsAlive = bool (__thiscall*)(Actor*);
    static auto _IsAlive = (IsAlive)nullptr;

    if(_IsAlive == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _IsAlive = (IsAlive)(this->VTable[102]);
            break;
        };
    };

    return (_IsAlive != nullptr ? _IsAlive(this) : false);
};

auto Actor::canAttack(Actor* e, bool pB) -> bool {
    using CanAttack = bool (__thiscall*)(Actor*, Actor*, bool);
    static auto _CanAttack = (CanAttack)nullptr;

    if(_CanAttack == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _CanAttack = (CanAttack)(this->VTable[111]);
            break;
        };
    };

    return (_CanAttack != nullptr ? _CanAttack(this, e, pB) : false);
};

auto Actor::isJumping(void) -> bool {
    using IsJumping = bool (__thiscall*)(Actor*);
    static auto _IsJumping = (IsJumping)nullptr;

    if(_IsJumping == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _IsJumping = (IsJumping)(this->VTable[128]);
            break;
        };
    };

    return (_IsJumping != nullptr ? IsJumping(this) : false);
};

auto Actor::consumeTotem(void) -> bool {
    using ConsumeTotem = bool (__thiscall*)(Actor*);
    static auto _ConsumeTotem = (ConsumeTotem)nullptr;

    if(_ConsumeTotem == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _ConsumeTotem = (ConsumeTotem)(this->VTable[164]);
            break;
        };
    };

    return (_ConsumeTotem != nullptr ? _ConsumeTotem(this) : false);
};

auto Actor::getEntityTypeId(void) -> uint8_t {
    using GetEntityTypeId = uint8_t (__thiscall*)(Actor*);
    static auto _GetEntityTypeId = (GetEntityTypeId)nullptr;

    if(_GetEntityTypeId == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _GetEntityTypeId = (GetEntityTypeId)(this->VTable[169]);
            break;
        };
    };

    return (_GetEntityTypeId != nullptr ? _GetEntityTypeId(this) : NULL);
};

auto Actor::startSwimming(void) -> void {
    using Swimming = void (__thiscall*)(Actor*);
    static auto _Swimming = (Swimming)nullptr;

    if(_Swimming == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _Swimming = (Swimming)(this->VTable[200]);
            break;
        };
    };

    if(_Swimming != nullptr)
        _Swimming(this);
};

auto Actor::stopSwimming(void) -> void {
    using Swimming = void (__thiscall*)(Actor*);
    static auto _Swimming = (Swimming)nullptr;

    if(_Swimming == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _Swimming = (Swimming)(this->VTable[201]);
            break;
        };
    };

    if(_Swimming != nullptr)
        _Swimming(this);
};

auto Actor::swing(void) -> void {
    using Swing = void (__thiscall*)(Actor*);
    static auto _Swing = (Swing)nullptr;

    if(_Swing == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _Swing = (Swing)(this->VTable[218]);
            break;
        };
    };

    if(_Swing != nullptr)
        _Swing(this);
};

auto Actor::isWorldBuilder(void) -> bool {
    using IsWorldBuilder = bool (__thiscall*)(Actor*);
    static auto _IsWorldBuilder = (IsWorldBuilder)nullptr;

    if(_IsWorldBuilder == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _IsWorldBuilder = (IsWorldBuilder)(this->VTable[228]);
            break;
        };
    };

    return (_IsWorldBuilder != nullptr ? _IsWorldBuilder(this) : false);
};

auto Actor::isInCreative(void) -> bool {
    using IsInCreative = bool (__thiscall*)(Actor*);
    static auto _IsInCreative = (IsInCreative)nullptr;

    if(_IsInCreative == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _IsInCreative = (IsInCreative)(this->VTable[229]);
            break;
        };
    };

    return (_IsInCreative != nullptr ? _IsInCreative(this) : false);
};

auto Actor::isAdventure(void) -> bool {
    using IsAdventure = bool (__thiscall*)(Actor*);
    static auto _IsAdventure = (IsAdventure)nullptr;

    if(_IsAdventure == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _IsAdventure = (IsAdventure)(this->VTable[230]);
            break;
        };
    };

    return (_IsAdventure != nullptr ? _IsAdventure(this) : false);
};

auto Actor::isSurvival(void) -> bool {
    using IsSurvival = bool (__thiscall*)(Actor*);
    static auto _IsSurvival = (IsSurvival)nullptr;

    if(_IsSurvival == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _IsSurvival = (IsSurvival)(this->VTable[231]);
            break;
        };
    };

    return (_IsSurvival != nullptr ? _IsSurvival(this) : false);
};

auto Actor::isSpectator(void) -> bool {
    using IsSpectator = bool (__thiscall*)(Actor*);
    static auto _IsSpectator = (IsSpectator)nullptr;

    if(_IsSpectator == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _IsSpectator = (IsSpectator)(this->VTable[232]);
            break;
        };
    };

    return (_IsSpectator != nullptr ? _IsSpectator(this) : false);
};

auto Actor::isAttackableGamemode(void) -> bool {
    using IsAttackableGamemode = bool (__thiscall*)(Actor*);
    static auto _IsAttackableGamemode = (IsAttackableGamemode)nullptr;

    if(_IsAttackableGamemode == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _IsAttackableGamemode = (IsAttackableGamemode)(this->VTable[233]);
            break;
        };
    };

    return (_IsAttackableGamemode != nullptr ? _IsAttackableGamemode(this) : false);
};

auto Actor::setSize(float width, float height) -> void {
    using SetSize = void (__thiscall*)(Actor*, float, float);
    static auto _SetSize = (SetSize)nullptr;

    if(_SetSize == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _SetSize = (SetSize)(this->VTable[239]);
            break;
        };
    };

    if(_SetSize != nullptr)
        _SetSize(this, width, height);
};

auto Actor::setSprinting(bool state) -> void {
    using SetSprinting = void (__thiscall*)(Actor*, bool);
    static auto _SetSprinting = (SetSprinting)nullptr;

    if(_SetSprinting == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _SetSprinting = (SetSprinting)(this->VTable[281]);
            break;
        };
    };

    if(_SetSprinting != nullptr)
        _SetSprinting(this, state);
};

auto Actor::isMob(void) -> bool {
    auto currType = this->getEntityTypeId();

    switch(currType) {
        case EntityType::Dropped_Item:
            return false;
        break;
        case EntityType::Experience_Orb:
            return false;
        break;
        case EntityType::TNT:
            return false;
        break;
        case EntityType::Falling_Block:
            return false;
        break;
        case EntityType::Moving_Block:
            return false;
        break;
        case EntityType::Armor_Stand:
            return false;
        break;
        case EntityType::Bottle_Of_Enchanting:
            return false;
        break;
        case EntityType::Eye_Of_Ender:
            return false;
        break;
        case EntityType::Ender_Crystal:
            return false;
        break;
        case EntityType::Fireworks_Rocket:
            return false;
        break;
        case EntityType::Thrown_Trident:
            return false;
        break;
        case EntityType::Shulker_Bullet:
            return false;
        break;
        case EntityType::Fishing_Hook:
            return false;
        break;
        case EntityType::Dragon_Fireball:
            return false;
        break;
        case EntityType::Arrow:
            return false;
        break;
        case EntityType::Snowball:
            return false;
        break;
        case EntityType::Egg:
            return false;
        break;
        case EntityType::Painting:
            return false;
        break;
        case EntityType::Minecart:
            return false;
        break;
        case EntityType::Fireball:
            return false;
        break;
        case EntityType::Splash_Potion:
            return false;
        break;
        case EntityType::Ender_Pearl:
            return false;
        break;
        case EntityType::Leash_Knot:
            return false;
        break;
        case EntityType::Wither_Skull:
            return false;
        break;
        case EntityType::Boat:
            return false;
        break;
        case EntityType::Wither_Skull_Dangerous:
            return false;
        break;
        case EntityType::Lightning_Bolt:
            return false;
        break;
        case EntityType::Small_Fireball:
            return false;
        break;
        case EntityType::Area_Effect_Cloud:
            return false;
        break;
        case EntityType::Hopper_Minecart:
            return false;
        break;
        case EntityType::TNT_Minecart:
            return false;
        break;
        case EntityType::Chest_Minecart:
            return false;
        break;
        case EntityType::Command_Block_Minecart:
            return false;
        break;
        case EntityType::Lingering_Potion:
            return false;
        break;
        case EntityType::Llama_Spit:
            return false;
        break;
        case EntityType::Evocation_Fang:
            return false;
        break;
        case EntityType::Ice_Bomb:
            return false;
        break;
        case EntityType::Balloon:
            return false;
        break;
    };
    
    return true;
};

auto Actor::isOnGround(void) -> bool {
    auto res = false;

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            res = *(bool*)((uintptr_t)(this) + 0x1D8);
        break;
    };

    return res;
};

auto Actor::setOnGround(bool state) -> void {
    auto onGroundPtr = (bool*)nullptr;

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            onGroundPtr = (bool*)((uintptr_t)(this) + 0x1D8);
        break;
    };

    if(onGroundPtr != nullptr)
        *onGroundPtr = state;
};

auto Actor::setStepHeight(float f) -> void {
    auto stepHeightPtr = (float*)nullptr;

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            stepHeightPtr = (float*)((uintptr_t)(this) + 0x238);
        break;
    };

    if(stepHeightPtr != nullptr)
        *stepHeightPtr = f;
};

auto Actor::getSize(void) -> Vec2<float> {
    auto res = Vec2<float>();

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            res = *(Vec2<float>*)((uintptr_t)(this) + 0x4D0);
        break;
    };

    return res;
};

auto Actor::getRot(void) -> Vec2<float> {
    auto res = Vec2<float>();

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            res = *(Vec2<float>*)((uintptr_t)(this) + 0x138);
        break;
    };

    return res;
};

auto Actor::getMotion(void) -> Vec3<float> {
    auto res = Vec3<float>();

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            res = *(Vec3<float>*)((uintptr_t)(this) + 0x4F0);
        break;
    };

    return res;
};

auto Actor::setMotion(Vec3<float> motion) -> void {
    auto motionPtr = (Vec3<float>*)nullptr;
    
    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            motionPtr = (Vec3<float>*)((uintptr_t)(this) + 0x4F0);
        break;
    };

    if(motionPtr != nullptr)
        *motionPtr = motion;

};

auto Actor::getXboxGamertag(void) -> std::string {
    auto gamertag = std::string();

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            gamertag = *(std::string*)((uintptr_t)(this) + 0x8B8);
        break;
    };
    
    return gamertag;
};