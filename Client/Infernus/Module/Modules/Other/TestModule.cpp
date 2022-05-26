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
    auto textPos = ImVec2(2.f, displaySize.y - calcPos.y);

    RenderUtils::fillRect(nullptr, ImVec4(textPos.x - 2.f, textPos.y, calcPos.x + 4.f, textPos.y + calcPos.y), ImColor(21.f, 21.f, 21.f), 1.2f);
    RenderUtils::drawText(nullptr, textPos, text, fontSize, ImColor(232.f, 99.f, 32.f));

};