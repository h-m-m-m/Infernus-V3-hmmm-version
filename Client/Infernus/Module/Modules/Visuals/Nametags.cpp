#include "Nametags.h"
#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto Nametags::onRender(void) -> void {
    auto mgr = this->category->manager;
    
    auto instance = Minecraft::getClientInstance();
    auto guidata = (instance != nullptr ? instance->getGuiData() : nullptr);
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    if(player == nullptr || guidata == nullptr || mcGame == nullptr)
        return;
    
    if(!mcGame->canUseKeys)
        return;

    for(auto [runtimeId, entity] : mgr->entityMap) {
        
        if(runtimeId == player->getRuntimeId() || entity->getEntityTypeId() != 63)
            continue;
        
        auto pos = entity->getPos();
        pos.y += 1.5f;

        auto name = entity->getNameTag();
        auto textPos = instance->gameToScreenPos(pos);

        if(name.length() <= 0 || name.length() >= 25)
            continue;

        if(textPos.x <= 0 || textPos.y <= 0)
            continue;
        
        if(name.rfind("§") == 0 && name.length() > 2)
            name.erase(0, 3);
        
        auto fontSize = 10.f * guidata->uiScale;
        auto textSize = RenderUtils::getTextSize(name, fontSize);

        textPos.x -= (textSize.x / 2.f);
        RenderUtils::drawText(nullptr, ImVec2(textPos.x, textPos.y), name, fontSize, ImColor(255.f, 255.f, 255.f));

        auto rectPos = ImVec4();

        rectPos.x = textPos.x - 1.f * (fontSize / 10.f);
        rectPos.y = textPos.y - 1.f * (fontSize / 10.f);
        rectPos.z = textPos.x + textSize.x + 1.f * (fontSize / 10.f);
        rectPos.w = textPos.y + textSize.y + 2.f * (fontSize / 10.f);

        RenderUtils::fillRect(nullptr, rectPos, ImColor(50.f, 50.f, 50.f, 0.8f), 4.f);

    };
};