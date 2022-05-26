#ifndef CLIENT_INFERNUS_HOOKS_HOOKS_SWAPCHAIN_SWAPCHAIN
#define CLIENT_INFERNUS_HOOKS_HOOKS_SWAPCHAIN_SWAPCHAIN

#include "../../Hook.h"

#include "../../../../../Includes/imgui/DroidSans.hpp"
#include "../../../../../Includes/imgui/Minecraft.hpp"
#include "../../../../../Includes/imgui/DejaVuSerif.hpp"

class SwapChain_Hook : public Hook {
public:
    SwapChain_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    virtual auto init(void) -> void override;
};

#endif /* CLIENT_INFERNUS_HOOKS_HOOKS_SWAPCHAIN_SWAPCHAIN */