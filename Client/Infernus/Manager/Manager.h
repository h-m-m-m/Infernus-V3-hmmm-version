#ifndef CLIENT_INFERNUS_MANAGER_MANAGER
#define CLIENT_INFERNUS_MANAGER_MANAGER

#include "../../Client.h"
#include "../Hook/Hook.h"

class Manager {
public:
    Client* client = nullptr;
    std::vector<Hook*> hooks;
public:
    Manager(Client*);
public:
    auto initHooks(void) -> void;
};

#endif /* CLIENT_INFERNUS_MANAGER_MANAGER */