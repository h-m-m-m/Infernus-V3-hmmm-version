#include "TestModule.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto TestModule::onRender(void) -> void {

    if(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - then) > std::chrono::seconds(1)) {
        currFps = ImGui::GetIO().Framerate / 1000.f;
        then = std::chrono::high_resolution_clock::now();
    };

    auto instance = Minecraft::getClientInstance();
    auto guiData = (instance != nullptr ? instance->getGuiData() : nullptr);

    if(guiData == nullptr)
        return;
    
    auto displaySize = guiData->screenRes1;
    auto fontSize = 10 * guiData->uiScale;
    
    auto text = std::string("Infernus V3 | FPS: " + std::to_string((int)currFps));
    auto calcPos = RenderUtils::getTextSize(text, fontSize);
    auto textPos = ImVec2(12.f, displaySize.y - (calcPos.y + 12.f));

    RenderUtils::fillRect(nullptr, ImVec4(textPos.x - 2.f, textPos.y - 2.f, calcPos.x + 10.f, (textPos.y + 2.f) + calcPos.y), ImColor(50.f, 50.f, 50.f, .8f), 1.2f);
    RenderUtils::drawText(nullptr, textPos, text, fontSize, ImColor(232.f, 99.f, 32.f));

};

auto TestModule::onRenderOptions(void) -> void {

    auto mgr = this->category->manager;
    
    ImGuiIO& io = ImGui::GetIO();
    auto currFont = ImGui::GetFont();
    
    if(ImGui::BeginCombo("Font Switcher", "Select Font")) {
        
        for(auto [name, font] : mgr->fonts) {

            if(ImGui::Selectable(name.c_str(), currFont == font)) {

                io.FontDefault = font;

            };
            
        };

        ImGui::EndCombo();

    };

};

auto TestModule::onGameMode(GameMode* GM) -> void {
    //
};