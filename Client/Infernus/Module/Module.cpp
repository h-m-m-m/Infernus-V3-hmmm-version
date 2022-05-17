#include "Module.h"
#include "../Category/Category.h"

Module::Module(Category* category, std::string name) {
    this->category = category;
    this->name = name;

    this->category->modules.push_back(this);
};