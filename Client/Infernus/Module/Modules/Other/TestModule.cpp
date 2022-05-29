#include "TestModule.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto TestModule::onRender(void) -> void {

    if(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - then) > std::chrono::seconds(1)) {
        currFps = ImGui::GetIO().Framerate / 1000.f;
        then = std::chrono::high_resolution_clock::now();
    };

    this->updateAlpha();

    auto instance = Minecraft::getClientInstance();
    auto guiData = (instance != nullptr ? instance->getGuiData() : nullptr);

    if(guiData == nullptr)
        return;
    
    auto displaySize = guiData->screenRes1;
    auto fontSize = 10 * guiData->uiScale;
    
    auto textA = std::string("Infernus V3 | FPS: " + std::to_string((int)currFps));
    auto calcPosA = RenderUtils::getTextSize(textA, fontSize);
    auto textPosA = ImVec2(12.f, displaySize.y - (calcPosA.y + 12.f));

    RenderUtils::fillRect(nullptr, ImVec4(textPosA.x - 2.f, textPosA.y - 2.f, calcPosA.x + 12.f, (textPosA.y + 2.f) + calcPosA.y), ImColor(50.f, 50.f, 50.f, alpha - 0.2f), 3.f);
    RenderUtils::drawText(nullptr, textPosA, textA, fontSize, ImColor(232.f, 99.f, 32.f, alpha));

    auto player = instance->getLocalPlayer();

    if(player == nullptr)
        return;
    
    auto myPos = player->getPos();
    
    auto textB = std::string(player->getNameTag() + " | " + std::to_string((int)myPos.x) + ", " + std::to_string((int)myPos.y - 2) + ", " + std::to_string((int)myPos.z));
    auto calcPosB = RenderUtils::getTextSize(textB, fontSize);
    auto textPosB = ImVec2(12.f, textPosA.y - (calcPosB.y + 12.f));

    RenderUtils::fillRect(nullptr, ImVec4(textPosB.x - 2.f, textPosB.y - 2.f, calcPosB.x + 12.f, (textPosB.y + 2.f) + calcPosB.y), ImColor(50.f, 50.f, 50.f, alpha - 0.2f), 3.f);
    RenderUtils::drawText(nullptr, textPosB, textB, fontSize, ImColor(232.f, 99.f, 32.f, alpha));
};

auto TestModule::hasOptions() -> bool {
    return true;
}

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

auto TestModule::updateAlpha(void) -> void {
    auto reachOff = [&](float* value, float target, float modifier) {
        if(*value < target)
            *value += modifier;
        else
            *value -= modifier;
    };

    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);
    auto modifier = 0.04f;
    
    if(mcGame == nullptr || player == nullptr)
        return reachOff(&alpha, 1.f, modifier);
    
    if(mcGame->canUseKeys)
        return reachOff(&alpha, 1.f, modifier);
    else
        return reachOff(&alpha, .0f, modifier);
};