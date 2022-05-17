#ifndef CLIENT_INFERNUS_MANAGER_MANAGER
#define CLIENT_INFERNUS_MANAGER_MANAGER

#include "../../Client.h"

class Manager {
public:
    Client* client = nullptr;
public:
    Manager(Client*);
};

#endif /* CLIENT_INFERNUS_MANAGER_MANAGER */