#include "Nametags.h"
#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto sanitize(std::string text) -> std::string { // https://github.com/horionclient/Horion/blob/cb636b579c27388c59c44705549263a4f9407573/Utils/Utils.cpp#L34
	std::string out;
	bool wasValid = true;

    auto invalidChar = [](char c) {
        return !(c >= 0 && *reinterpret_cast<unsigned char*>(&c) < 128);
    };
	
    for (char c : text) {
		bool isValid = !invalidChar(c);
		if (wasValid) {
			if (!isValid) {
				wasValid = false;
			} else {
				out += c;
			}
		} else {
			wasValid = isValid;
		}
	};

	return out;
};

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
        
        if(runtimeId == player->getRuntimeId())
            continue;
        
        auto pos = entity->getPos();
        pos.y += 1.5f;

        auto name = sanitize(entity->getNameTag());
        auto textPos = instance->gameToScreenPos(pos);

        if(name.length() <= 0 || name.length() >= 25)
            continue;

        if(textPos.x <= 0 || textPos.y <= 0)
            continue;

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