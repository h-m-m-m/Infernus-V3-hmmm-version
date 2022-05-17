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
    Manager(Client*);
public:
    auto initHooks(void) -> void;
public:
    auto initCategories(void) -> void;
    auto initModules(void) -> void;
public:
    auto getCategory(std::string) -> Category*;
};

#endif /* CLIENT_INFERNUS_MANAGER_MANAGER */