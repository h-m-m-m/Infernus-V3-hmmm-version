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
    auto initCategories(void) -> void;
};

#endif /* CLIENT_INFERNUS_MANAGER_MANAGER */