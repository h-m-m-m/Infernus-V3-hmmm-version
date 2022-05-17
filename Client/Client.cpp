#include "Client.h"
#include "Infernus/Manager/Manager.h"

Client::Client(std::string name, std::string ver) {
    this->name = name;
    this->ver = ver;

    this->manager = new Manager(this);
};