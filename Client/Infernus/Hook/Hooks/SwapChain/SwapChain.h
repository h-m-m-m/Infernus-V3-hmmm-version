#ifndef CLIENT_INFERNUS_HOOKS_HOOKS_SWAPCHAIN_SWAPCHAIN
#define CLIENT_INFERNUS_HOOKS_HOOKS_SWAPCHAIN_SWAPCHAIN

#include "../../Hook.h"

#include "../../../../../Includes/imgui/DroidSans.hpp"

class SwapChain_Hook : public Hook {
public:
    SwapChain_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    virtual auto init(void) -> void override;
};

#endif /* CLIENT_INFERNUS_HOOKS_HOOKS_SWAPCHAIN_SWAPCHAIN */