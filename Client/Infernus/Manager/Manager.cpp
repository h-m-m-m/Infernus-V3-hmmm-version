#include "Manager.h"

Manager::Manager(Client* client) {
    this->client = client;

    this->initHooks();
    this->initCategories();
};

#include "../Hook/Hooks/SwapChain/SwapChain.h"
#include "../Hook/Hooks/GameMode/GameMode.h"
#include "../Hook/Hooks/Mouse/Mouse.h"

auto Manager::initHooks(void) -> void {

    if(!this->hooks.empty())
        return;
    
    if(MH_Initialize() != MH_OK)
        return Utils::debugLog("Failed to initialize MinHook!");
    
    new SwapChain_Hook(this);
    new GameMode_Hook(this);
    new Mouse_Hook(this);

};

auto Manager::initCategories(void) -> void {

    if(!this->categories.empty())
        return;
    
    new Category(this, "Combat");
    new Category(this, "Movement");
    new Category(this, "Player");
    new Category(this, "Visuals");
    new Category(this, "World");
    new Category(this, "Other");

    this->initModules();

};

#include "../Module/Modules/Other/TestModule.h"

auto Manager::initModules(void) -> void {

    auto combat = this->getCategory("Combat");
    auto movement = this->getCategory("Movement");
    auto player = this->getCategory("Player");
    auto visuals = this->getCategory("Visuals");
    auto world = this->getCategory("World");
    auto other = this->getCategory("Other");

    
    /* Other */

    if(other != nullptr && other->modules.empty()) {

        new TestModule(other);

    };

	this->baseTick();

};

auto Manager::baseTick(void) -> void {

	while(this->isRunning) {
		for(auto category : this->categories)
			for(auto module : category->modules)
				module->baseTick();
	};
	
	kiero::shutdown();
	MH_Uninitialize();
	Sleep(100);
	FreeLibraryAndExitThread(Utils::GetDll(), 1);

};

auto Manager::getCategory(std::string name) -> Category* {
    
    for(auto category : this->categories)
        if(category->name == name)
            return category;
    
    return nullptr;

};

auto Manager::setImGuiStyles(void) -> void {

	auto style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(8, 6);
	//style->WindowRounding = 5.0f;
	style->FramePadding = ImVec2(6, 6);
	//style->FrameRounding = 5.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(0, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	//style->GrabRounding = 3.0f;
 
	style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	
};