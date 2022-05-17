#ifndef CLIENT_UTILS_RENDERUTILS
#define CLIENT_UTILS_RENDERUTILS

#include "../../../Includes/imgui/imgui.h"

#include "../../../Includes/imgui/imgui_impl_win32.h"

#include "../../../Includes/imgui/imgui_impl_dx12.h"
#include "../../../Includes/imgui/imgui_impl_dx11.h"

#include <initguid.h>
#include <string>

#include <dxgi.h>
#include <d3d11.h>
#include <d3d12.h>
#include <d2d1_1.h>
#include <dxgi1_4.h>
#include <dwrite_1.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dwrite.lib")

enum ID3D_Device_Type { INVALID_DEVICE_TYPE, D3D11, D3D12 };

class RenderUtils {
public:
    static ID3D_Device_Type deviceType;
public:
    static auto drawText(ImDrawList*, ImVec2, std::string, float, ImColor) -> void;
    static auto getTextSize(std::string, float) -> ImVec2;
public:
    static auto fillRect(ImDrawList*, ImVec4, ImColor, float) -> void;
};

#endif /* CLIENT_UTILS_RENDERUTILS */