#ifndef CLIENT_INFERNUS_CATEGORY_CATEGORY
#define CLIENT_INFERNUS_CATEGORY_CATEGORY

#include "../../Mem/Mem.h"
#include "../../Utils/Utils.h"

#include "../Module/Module.h"

class Category {
public:
    class Manager* manager = nullptr;
public:
    std::string name;
    std::vector<Module*> modules;
public:
    Category(Manager*);
};

#endif /* CLIENT_INFERNUS_CATEGORY_CATEGORY */