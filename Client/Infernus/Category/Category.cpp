#include "Category.h"
#include "../Manager/Manager.h"

Category::Category(Manager* mgr, std::string name) {
    this->manager = mgr;
    this->name = name;

    mgr->categories.push_back(this);
};