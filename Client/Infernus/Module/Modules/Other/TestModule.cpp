#include "TestModule.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto TestModule::onRender(void) -> void {

    auto instance = Minecraft::getClientInstance();
    auto guiData = (instance != nullptr ? instance->getGuiData() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    if(guiData == nullptr || mcGame == nullptr)
        return;
    
    auto displaySize = guiData->screenRes1;
    auto fontSize = 10 * guiData->uiScale;

    auto text = std::string("Infernus V3");
    auto calcPos = RenderUtils::getTextSize(text, fontSize);
    auto textPos = ImVec2(2.f, displaySize.y - calcPos.y);

    if(mcGame->canUseKeys) {
        RenderUtils::fillRect(nullptr, ImVec4(textPos.x - 2.f, textPos.y, calcPos.x + 4.f, textPos.y + calcPos.y), ImColor(21.f, 21.f, 21.f), 1.2f);
        RenderUtils::drawText(nullptr, textPos, text, fontSize, ImColor(232.f, 99.f, 32.f));
    };

    auto mgr = this->category->manager;

    if(ImGui::Begin(this->name.c_str())) {

        for(auto category : mgr->categories) {
            
            if(ImGui::BeginMenu(category->name.c_str())) {

                for(auto mod : category->modules) {

                    if(ImGui::BeginMenu(mod->name.c_str())) {

                        if(ImGui::MenuItem(std::string(mod->isEnabled ? "Disable": "Enable").c_str())) {
                            
                            mod->isEnabled = !mod->isEnabled;

                        };

                        ImGui::EndMenu();

                    };

                };

                ImGui::EndMenu();

            };

        };
        
        ImGui::End();

    };

};