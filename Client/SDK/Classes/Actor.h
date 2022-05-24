#ifndef CLIENT_SDK_CLASSES_ACTOR
#define CLIENT_SDK_CLASSES_ACTOR

#include "Level.h"

class Actor {
private:
    char pad_0008[304];    //0x0008
public:
	Vec2<float> bodyRot;   //0x0138
private:
	char pad_0140[152];    //0x0140
public:
	bool onGround;         //0x01D8
private:
	char pad_01D9[759];    //0x01D9
public:
	Vec2<float> collision; //0x04D0
    Vec3<float> pos;       //0x04D8
private:
	char pad_04E4[12];     //0x04E4
public:
	Vec3<float> velocity;  //0x04F0
private:
	char pad_04FC[84];     //0x04FC
public:
	uint64_t runtimeId;    //0x0550
public:
    auto getLevel(void) -> Level*;
private:
    virtual auto Function0(void) -> void;
    virtual auto Function1(void) -> void;
    virtual auto Function2(void) -> void;
    virtual auto Function3(void) -> void;
    virtual auto Function4(void) -> void;
    virtual auto Function5(void) -> void;
    virtual auto Function6(void) -> void;
public:
    virtual auto outOfWorld(void) -> bool;
private:
    virtual auto Function8(void) -> void;
    virtual auto Function9(void) -> void;
    virtual auto Function10(void) -> void;
    virtual auto Function11(void) -> void;
    virtual auto Function12(void) -> void;
    virtual auto Function13(void) -> void;
    virtual auto Function14(void) -> void;
public:
    virtual auto reset(void) -> void;
    virtual auto getOnDeathExperience(void) -> __int64;
    virtual auto getOwnerEntityType(void) -> int;
    virtual auto remove(void) -> void;
    virtual auto setPos(Vec3<float>*) -> void;
private:
    virtual auto Function20(void) -> void;
    virtual auto Function21(void) -> void;
public:
    virtual auto getPos(void) -> Vec3<float>*;
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */