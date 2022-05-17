#include "TestModule.h"

auto TestModule::onRender(void) -> void {

    /*auto draw = ImGui::GetBackgroundDrawList();
    auto style = ImGui::GetFont();
    
    auto displaySize = ImGui::GetIO().DisplaySize;
    auto text = std::string("Infernus V3");
    auto calcPos = ImGui::CalcTextSize(text.c_str());

    style->Scale = 1.8f;

    auto textPos = ImVec2(2.f, displaySize.y - (calcPos.y * 3.f));
    
    draw->AddRectFilled(textPos, ImVec2(calcPos.x + 2.f, textPos.y + calcPos.y), ImColor(0.08235f, 0.08235f, 0.08235f));
    draw->AddText(textPos, ImColor(0.65f, 0.31f, 0.31f), text.c_str());*/

    auto displaySize = ImGui::GetIO().DisplaySize;
    auto fontSize = 24.f;

    Utils::debugLog(std::to_string(displaySize.y));

    auto text = std::string("Infernus V3");
    auto calcPos = RenderUtils::getTextSize(text, fontSize);
    auto textPos = ImVec2(2.f, displaySize.y - (calcPos.y * 3.f));

    RenderUtils::fillRect(nullptr, ImVec4(textPos.x - 2.f, textPos.y, calcPos.x + 4.f, textPos.y + calcPos.y), ImColor(21.f, 21.f, 21.f), 1.2f);
    RenderUtils::drawText(nullptr, textPos, text, fontSize, ImColor(232.f, 99.f, 32.f));

};