#ifndef CLIENT_SDK_CLASSES_ACTOR
#define CLIENT_SDK_CLASSES_ACTOR

#include "Level.h"

class Actor {
public:
    uintptr_t** VTable;
public:
    auto getLevel(void) -> Level*;
public:
    auto getRuntimeId(void) -> uint64_t;
    auto setPos(Vec3<float>) -> void;
    auto getPos(void) -> Vec3<float>;
    auto outOfWorld(void) -> bool;
    auto isAlive(void) -> bool;
    auto canAttack(Actor*, bool) -> bool;
    auto isJumping(void) -> bool;
    auto consumeTotem(void) -> bool;
    auto getEntityTypeId(void) -> uint8_t;
    auto startSwimming(void) -> void;
    auto stopSwimming(void) -> void;
    auto swing(void) -> void;
    auto isWorldBuilder(void) -> bool;
    auto isInCreative(void) -> bool;
    auto isAdventure(void) -> bool;
    auto isSurvival(void) -> bool;
    auto isSpectator(void) -> bool;
    auto isAttackableGamemode(void) -> bool;
    auto setSize(float, float) -> void;
    auto setSprinting(bool) -> void;
public:
    auto isMob(void) -> bool;
    auto setStepHeight(float) -> void;
    auto getSize(void) -> Vec2<float>;
    auto getRot(void) -> Vec2<float>;
    auto getMotion(void) -> Vec3<float>;
    auto setMotion(Vec3<float>) -> void;
};

enum EntityType {
    /* Drops */
    
    Dropped_Item = 64,
    Experience_Orb = 69,
    
    /* Blocks */
    
    TNT = 65,
    Falling_Block = 66,
    Moving_Block = 67,
    
    /* Immobile and Projectiles */
    
    Armor_Stand = 61,
    Bottle_Of_Enchanting = 68,
    Eye_Of_Ender = 70,
    Ender_Crystal = 71,
    Fireworks_Rocket = 72,
    Thrown_Trident = 73,
    Shulker_Bullet = 76,
    Fishing_Hook = 77,
    Dragon_Fireball = 79,
    Arrow = 80,
    Snowball = 81,
    Egg = 82,
    Painting = 83,
    Minecart = 84,
    Fireball = 85,
    Splash_Potion = 86,
    Ender_Pearl = 87,
    Leash_Knot = 88,
    Wither_Skull = 89,
    Boat = 90,
    Wither_Skull_Dangerous = 91,
    Lightning_Bolt = 93,
    Small_Fireball = 94,
    Area_Effect_Cloud = 95,
    Hopper_Minecart = 96,
    TNT_Minecart = 97,
    Chest_Minecart = 98,
    Command_Block_Minecart = 100,
    Lingering_Potion = 101,
    Llama_Spit = 102,
    Evocation_Fang = 103,
    Ice_Bomb = 106,
    Balloon = 107,
    
    /* Hostile Mobs */

    Zombie = 32,
    Creeper = 33,
    Skeleton = 34,
    Spider = 35,
    Zombie_Pigman = 36,
    Slime = 37,
    Enderman = 38,
    Silverfish = 39,
    Cave_Spider = 40,
    Ghast = 41,
    Magma_Cube = 42,
    Blaze = 43,
    Zombie_Villager = 44,
    Witch = 45,
    Stray = 46,
    Husk = 47,
    Wither_Skeleton = 48,
    Guardian = 49,
    Elder_Guardian = 50,
    Wither = 52,
    Ender_Dragon = 53,
    Shulker = 54,
    Endermite = 55,
    Vindicator = 57,
    Phantom = 58,
    Ravager = 59,
    Evocation_Villager = 104,
    Vex = 105,
    Drowned = 110,
    Pillager = 114,
    Zombie_Villager_V2 = 116,
    Piglin = 123,
    Hoglin = 124,
    Zoglin = 126,
    Piglin_Brute = 127,

    /* Passive and Neutral Mobs */

    Chicken = 10,
    Cow = 11,
    Pig = 12,
    Sheep = 13,
    Wolf = 14,
    Villager = 15,
    Mooshroom = 16,
    Squid = 17,
    Rabbit = 18,
    Bat = 19,
    Iron_Golem = 20,
    Snow_Golem = 21,
    Ocelot = 22,
    Horse = 23,
    Donkey = 24,
    Mule = 25,
    Skeleton_Horse = 26,
    Zombie_Horse = 27,
    Polar_Bear = 28,
    Llama = 29,
    Parrot = 30,
    Dolphin = 31,
    Turtle = 74,
    Cat = 75,
    Pufferfish = 108,
    Salmon = 109,
    Tropical_Fish = 111,
    Cod = 112,
    Panda = 113,
    Villager_V2 = 115,
    Wandering_Trader = 118,
    Fox = 121,
    Bee = 122,
    Strider = 125,
    Goat = 128,

    /* Other */

    Client_Player = 63,
    Shield = 117,
    
    Elder_Guardian_Ghost = 120,
    NPC = 51,
    Agent = 56,
    Tripod_Camera = 62,
    Chalkboard = 78
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */