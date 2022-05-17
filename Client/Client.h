#ifndef CLIENT_CLIENT
#define CLIENT_CLIENT

#include "Mem/Mem.h"
#include "Utils/Utils.h"

class Client {
public:
    class Manager* manager = nullptr;
public:
    std::string name, ver;
public:
    Client(std::string, std::string);
};

#endif /* CLIENT_CLIENT */