#include "TabGui.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto TabGui::onRender(void) -> void {
    
    auto instance = Minecraft::getClientInstance();
    auto guiData = (instance != nullptr ? instance->getGuiData() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    if(guiData == nullptr || mcGame == nullptr)
        return;
    
    auto mgr = this->category->manager;
    auto client = mgr->client;

    auto fontSize = (guiData->uiScale > 1 ? 8.6f * guiData->uiScale : 15 * guiData->uiScale);
    auto startPos = ImVec2(15.f, 10.f);
    
    auto logoTextSize = RenderUtils::getTextSize(client->name, fontSize);
    auto catWidth = logoTextSize.x;
    auto catYOff = logoTextSize.y;

    for(auto cat : mgr->categories) {
        auto currWidth = RenderUtils::getTextSize(cat->name + " >", fontSize);

        if(currWidth.x > catWidth)
            catWidth = currWidth.x;
        
        catYOff += currWidth.y;
    };

    RenderUtils::fillRect(nullptr, ImVec4(startPos.x - 8.f, startPos.y - 2.f, startPos.x + (catWidth + 8.f), startPos.y + (catYOff + 2.f)), ImColor(50.f, 50.f, 50.f, .8f), 0.f);
    RenderUtils::drawText(nullptr, startPos, client->name, fontSize, ImColor(255.f, 110.f, 30.f));

    auto I = 0;
    for(auto cat : mgr->categories) {
        RenderUtils::drawText(nullptr, ImVec2(startPos.x + 2.f, (startPos.y + logoTextSize.y) + (I * fontSize)), selectedCat && catIndex == I ? cat->name + " >" : cat->name, fontSize, selectedCat && catIndex == I ? ImColor(66.f, 245.f, 138.f) : ImColor(245.f, 118.f, 70.f));
        I++;
    };

};

auto TabGui::onKey(uint64_t key, bool isDown, bool* cancel) -> void {

    if(key != VK_LEFT && key != VK_RIGHT && key != VK_DOWN && key != VK_UP || !isDown)
        return;
    
    *cancel = true;
    
    auto mgr = this->category->manager;
    auto categories = mgr->categories;
    
    auto category = categories.at(catIndex);

    if(key == VK_RIGHT) {
        if(!selectedCat) {
            selectedCat = true;
        } else {
            if(!selectedMod) {
                selectedMod = true;
            } else {
                /* Toggle selected Module */
            };
        };
    } else if(key == VK_LEFT) {
        if(selectedMod) {
            selectedMod = false;
        } else if(selectedCat) {
            selectedCat = false;
        };
    } else if(key == VK_DOWN) {
        if(selectedCat && !selectedMod) {
            catIndex++;
            
            if(catIndex >= categories.size())
                catIndex = 0;
            
        } else if(selectedMod) {
            modIndex++;

            if(modIndex >= category->modules.size())
                modIndex = 0;
        };
    } else if(key == VK_UP) {
        if(selectedCat && !selectedMod) {
            if(catIndex <= 0)
                catIndex = categories.size();
            
            catIndex--;
        } else if(selectedMod) {
            if(modIndex <= 0)
                modIndex = categories.size();
            
            modIndex--;
        };
    };

};