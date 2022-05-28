#ifndef CLIENT_INFERNUS_MANAGER_MANAGER
#define CLIENT_INFERNUS_MANAGER_MANAGER

#include "../../Client.h"
#include "../Hook/Hook.h"
#include "../Category/Category.h"

class Manager {
public:
    Client* client = nullptr;
    std::vector<Hook*> hooks;
    std::vector<Category*> categories;
public:
    std::map<uint64_t, bool> keyMap;
public:
    std::map<std::string, ImFont*> fonts;
public:
    std::map<uint64_t, Actor*> entityMap;
public:
    bool isRunning = true;
public:
    Manager(Client*);
public:
    auto initHooks(void) -> void;
public:
    auto initCategories(void) -> void;
    auto initModules(void) -> void;
    auto baseTick(void) -> void;
public:
    auto getCategory(std::string) -> Category*;
    auto isHoldingKey(uint64_t) -> bool;
public:
    auto setImGuiStyles(void) -> void;
public:
    auto cleanEntityMap(void) -> void;
};

#endif /* CLIENT_INFERNUS_MANAGER_MANAGER */