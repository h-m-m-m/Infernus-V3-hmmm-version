#include "Category.h"
#include "../Manager/Manager.h"

Category::Category(Manager* mgr) {
    this->manager = mgr;

    mgr->categories.push_back(this);
};