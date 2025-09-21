#include <android/log.h>
#include <unistd.h>
#include <thread>
#include <limits>
#include <KittyMemory/KittyMemory.h>
#include <KittyMemory/MemoryPatch.h>
#include <KittyMemory/KittyScanner.h>
#include <KittyMemory/KittyUtils.h>
#include "oxorany/oxorany.h"
#include <xdl.h>
#include <KittyUtils.h>
#include <KittyMemory.h>
#include <Il2Cpp.h>
#include <SubstrateHook.h>
#include <CydiaSubstrate.h>
#include "MANI~999/gui.hpp"
#include "il2cpp.h"
#include "DILJOT~666/Land.hpp"
#include "imgui/imgui.h"
#include "imgui/stb_image.h"
//#include "MANI.h"
//#include "ff.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <Themes.h>
#include "DILJOT~666/Firewall.h"
#include "DILJOT~666/exptime.h"
#include "DILJOT~666/Chams.h"
#include "DILJOT~666/Land.h"
#include "DILJOT~666/CN.h"
#include "DILJOT~666/lundbda.h"
#include "DILJOT~666/fontch.h"
#include "Icon/OPPOSans-H.h"
#include "TBM~SHIVAM/Icon.h"
#include "TBM~SHIVAM/Iconcpp.h"
#include <fstream>
void (*OpenURL)(String *url);
#include "GHr_Ryuuka/Tools/Call_Tools.h"
using json = nlohmann::json;
time_t rng = 0;
std::string g_Token, g_Auth;
#include "MANI~DILJOT~SHIVAM.h"

struct My_Patches {
    MemoryPatch Bypass1;
    MemoryPatch Bypass2;
    MemoryPatch Bypass3;
    MemoryPatch Bypass4;
    MemoryPatch Bypass5;
    MemoryPatch Bypass6;
    MemoryPatch Bypass7;
    MemoryPatch Bypass8;
    MemoryPatch Bypass9;
    MemoryPatch Bypass10;
    MemoryPatch Bypass11;
    MemoryPatch Bypass12;
    MemoryPatch Bypass13;
    MemoryPatch Bypass14;
    MemoryPatch Bypass15;
    
    MemoryPatch Guest;
} hexPatches;
using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;

#define ALPHA    ( ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoBorder )
#define NO_ALPHA ( ImGuiColorEditFlags_NoTooltip    | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoBorder )

void HueText(const char* text, ImVec4 color)
{
    static auto start_time = std::chrono::high_resolution_clock::now();
    auto elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time).count() / 1000.0f; 
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 0.0f)); 
    for (int i = 0; i < strlen(text); i++)
    {
      ImGui::SameLine();
        float t = fmodf(elapsed_seconds + (float)i / (float)strlen(text), 0.65f); 
        ImVec4 currentColor = ImVec4(color.x * t, color.y * t, color.z * t, color.w); 
        ImGui::PushStyleColor(ImGuiCol_Text, currentColor); 
        ImGui::Text("%c", text[i]); 
        ImGui::PopStyleColor(); 
    }
    ImGui::PopStyleColor(); 
}
/*
*/
void hack();
void writeLog(const std::string& logMessage, const std::string& filename = "/storage/emulated/0/Android/data/com.dualspace.multispace.androidx/files/log.txt");


 


class MyModule : public zygisk::ModuleBase {
 public:
  void onLoad(Api *api, JNIEnv *env) override {
    this->api_ = api;
    this->env_ = env;
    genv = env;
   // gEnv = env;

  }

  void preAppSpecialize(AppSpecializeArgs *args) override {
    static constexpr const char *packages[] = {
        "com.dts.freefireth"
    };
    const char *process = env_->GetStringUTFChars(args->nice_name, nullptr);
    for (const auto *package: packages) {
      is_game_ = (strcmp(process, package) == 0);
      if (is_game_) {
        break;
      }
    }
    env_->ReleaseStringUTFChars(args->nice_name, process);
  }

  void postAppSpecialize(const AppSpecializeArgs *args) override {
    if (is_game_) {
       genv->GetJavaVM(&jvm);
     //  genv->GetJavaVM(&gJvm);
      std::thread{hack}.detach();
    }
  }

 private:
  Api *api_ = nullptr;
  JNIEnv *env_ = nullptr;
  bool is_game_ = false;
};


uintptr_t il2cpp_base = 0;
void *getRealAddr(ulong offset) {
    return reinterpret_cast<void*>(il2cpp_base + offset);
};



namespace Settings
{
static int Tab = 1;
}

#define ICON_FA_WINDOW_MINIMIZE "\xef\x8a\x96"

void SetupImgui() {
IMGUI_CHECKVERSION();
//InitTexture();
ImGui::CreateContext();
ImGui_ImplOpenGL3_Init("#version 300 es");

            ImGuiIO &io = ImGui::GetIO();
            
            
            ImGui::GetStyle().WindowPadding = ImVec2(8, 8);
// ImGui::GetStyle().WindowRounding = 2.0f;
 ImGui::GetStyle().FramePadding = ImVec2(10, 10);
 ImGui::GetStyle().ItemSpacing = ImVec2(10, 10); 
// ImGui::GetStyle().FrameRounding = 0.0f;
// //ImGui::GetStyle().ChildRounding = 4.5f;
 ImGui::GetStyle().FrameBorderSize = 0.0f;
ImGui::GetStyle().WindowBorderSize = 1.0f;
ImGui::GetStyle().TabBorderSize = 1.0f;
ImGui::GetStyle().ScrollbarSize = 20.0f;
// //style->WindowTitleAlign = ImVec2(0.5, 0.5);
// //style->ButtonTextAlign = ImVec2(0.5,0.5);
// style->Colors[ImGuiCol_TitleBg]= ImVec4(0, 0, 0, 0.95f);
// style->Colors[ImGuiCol_TitleBgActive]= ImVec4(0, 0, 0, 0.95f);
// Setup Platform/Renderer backends

    // (This function remains the same as the previous answer)
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    style.WindowRounding = 8.0f;
    style.FrameRounding = 4.0f;
    style.GrabRounding = 4.0f;
    style.PopupRounding = 4.0f;
    style.TabRounding = 4.0f;
    style.ScrollbarRounding = 4.0f;
    
    colors[ImGuiCol_ChildBg]                    = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
  //colors[ImGuiCol_WindowBg]                    = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    colors[ImGuiCol_Border]                    = ImColor(5, 106, 153, 200);
    colors[ImGuiCol_Tab]                    = ImColor(10, 177, 255, 100);
    colors[ImGuiCol_TabHovered]             = ImColor(10, 177, 255, 200);
    colors[ImGuiCol_TabActive]              = ImColor(10, 177, 255, 200);
    colors[ImGuiCol_TabUnfocused]           = ImVec4(0.20f, 0.20f, 0.20f, 0.40f);
    colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.20f, 0.20f, 0.20f, 0.40f);
 
    colors[ImGuiCol_WindowBg] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.54f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.30f, 0.30f, 0.30f, 0.78f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.40f, 0.40f, 0.40f, 0.67f);
    colors[ImGuiCol_TitleBgActive] = ImColor(10, 177, 255, 255);
    colors[ImGuiCol_CheckMark] = ImColor(10, 177, 255, 255);
    colors[ImGuiCol_SliderGrab] = ImColor(10, 177, 255, 255);
    colors[ImGuiCol_SliderGrabActive] = ImColor(10, 177, 255, 255);
    colors[ImGuiCol_Button] = ImColor(10, 177, 255, 150);
    colors[ImGuiCol_ButtonHovered] = ImColor(10, 177, 255, 250);
    colors[ImGuiCol_ButtonActive] = ImColor(10, 177, 255, 220);
    colors[ImGuiCol_Header] = ImVec4(0.82f, 0.13f, 0.19f, 0.31f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.82f, 0.13f, 0.19f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImColor(10, 177, 255, 255);
    colors[ImGuiCol_Separator] = ImColor(200, 200,200, 200);
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.95f, 0.95f, 1.00f);

            io.ConfigWindowsMoveFromTitleBarOnly = true;
            io.IniFilename = NULL;

            static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
            ImFontConfig icons_config;

            ImFontConfig CustomFont;
            CustomFont.FontDataOwnedByAtlas = false;

            icons_config.MergeMode = true;
            icons_config.PixelSnapH = true;
            icons_config.OversampleH = 2.5;
            icons_config.OversampleV = 2.5;
            
          //io.Fonts->AddFontFromMemoryTTF((void *)BaiduZY_data, BaiduZY_size, 30.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
          io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(itsmkop), sizeof(itsmkop), 30.f, &CustomFont);
                  io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);
                  io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 24.f, &CustomFont);
         // memset(&Config, 0, sizeof(sConfig));
//

//ImFontConfig CustomFont;
CustomFont.FontDataOwnedByAtlas = false;
//font_cfg.SizePixels = 22.0f;
static const ImWchar vietnamese_chars[] = {
0x0020, 0x00FF, // Basic Latin + Latin Supplement
0x0102, 0x0103, // Â, â
0x0110, 0x0111, // Đ, đ
0x0128, 0x0129, // Ĩ, ĩ
0x0168, 0x0169, // Ũ, ũ
0x01A0, 0x01A1, // Ơ, ơ
0x01AF, 0x01B0, // Ư, ư
0x1EA0, 0x1EF9, // Vietnamese specific characters
0 // null-terminated list
};
}


bool clearMousePos = true;
bool ImGuiOK = false;
bool initImGui = false;


void VerticalTab(const char* label, int tab_index, int* p_selected_tab) {
ImGuiStyle& style = ImGui::GetStyle();
ImVec4* colors = style.Colors;

// Push custom colors for the selected and unselected states
ImVec4 color = ImColor(0, 150, 255, 5);
ImVec4 colorActive = ImColor(0, 150, 255, 5);
ImVec4 colorHovered = ImColor(0, 150, 255, 5);

if (tab_index == *p_selected_tab) {
// This is the selected tab, make it blue like in the image
ImGui::PushStyleColor(ImGuiCol_Button, colorActive);
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, colorActive);
ImGui::PushStyleColor(ImGuiCol_ButtonActive, colorActive);
} else {
// Unselected tabs are dark
ImGui::PushStyleColor(ImGuiCol_Button, color);
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, colorHovered);
ImGui::PushStyleColor(ImGuiCol_ButtonActive, colorActive);
}

if (ImGui::Button(label, ImVec2(200, 50))) { // Button size (width, height)
*p_selected_tab = tab_index;
}

if (tab_index == *p_selected_tab) {
ImDrawList* draw_list = ImGui::GetWindowDrawList();
const ImVec2 p_min = ImGui::GetItemRectMin();
const ImVec2 p_max = ImGui::GetItemRectMax();

ImU32 line_color = IM_COL32(50, 150, 255, 255);
float line_thickness = 8.0f;

draw_list->AddLine(
ImVec2(p_min.x, p_min.y), 
ImVec2(p_min.x, p_max.y), 
line_color, 
line_thickness
);
}

ImGui::PopStyleColor(3);
}

static int selected_tab = 0;
inline EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
inline EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    
        eglQuerySurface(dpy, surface, EGL_WIDTH, &g_GlWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &g_GlHeight);
    
    


    if (!g_IsSetup) {
        prevWidth = g_GlWidth;
        prevHeight = g_GlHeight;
        SetupImgui();
        
        g_IsSetup = true;
    }
    
 // Window background = black

    ImGuiIO &io = ImGui::GetIO();
        //Darkness();
        // Thiết lập màu chủ đề
        //ImVec4* colors = ImGui::GetStyle().Colors;


    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(g_GlWidth, g_GlHeight);
    ImGui::NewFrame();
        if (ImGuiOK) {
            int touchCount = (((int (*)())(Class_Input__get_touchCount))());
    if (touchCount > 0) {
        UnityEngine_Touch_Fields touch = ((UnityEngine_Touch_Fields(*)(int))(Class_Input__GetTouch))(0);
        float reverseY = io.DisplaySize.y - touch.m_Position.fields.y;
        switch (touch.m_Phase) {
            case TouchPhase::Began:
            case TouchPhase::Stationary:
                io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);
                io.MouseDown[0] = true;
                break;
            case TouchPhase::Ended:
            case TouchPhase::Canceled:
                io.MouseDown[0] = false;
                clearMousePos = true;
                break;
            case TouchPhase::Moved:
                io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);
                break;
            default:
                break;
        }
    }
        }
        
        DrawESP(g_GlWidth, g_GlHeight);
        
        ImDrawList*draw = ImGui::GetBackgroundDrawList();
/*      
        //DILJOT~MANI~AIMKILL~HOOK
// @MANIx999 @DILJOT666         
// If you give credit to your father, if you don't give credit to your father, then you will be my son, okay my son.
*/
// Premium DEXX-TER PRO - Compact Vertical Design
static int selectedTab = 0;

// Tab icon textures - declare as static so they persist
static GLuint aimIconTexture = 0;
static GLuint espIconTexture = 0; 
static GLuint brutalIconTexture = 0;
static bool iconsLoaded = false;

// Function to load texture from memory/assets
GLuint LoadTextureFromFile(const char* filename) {
    // This would normally load from assets, but for mod menu we'll use simple colored rectangles
    // as actual file loading in Android mod environment can be complex
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // Create simple colored icon data (32x32 pixels)
    unsigned char iconData[32 * 32 * 4]; // RGBA
    
    // Different colors for each icon
    unsigned char r = 0, g = 0, b = 0;
    if (strstr(filename, "AIM")) {
        r = 150; g = 75; b = 200; // Purple for AIM
    } else if (strstr(filename, "ESP")) {
        r = 120; g = 60; b = 180; // Darker purple for ESP  
    } else {
        r = 180; g = 90; b = 255; // Lighter purple for BRUTAL
    }
    
    // Fill with solid color
    for (int i = 0; i < 32 * 32; i++) {
        iconData[i * 4 + 0] = r;     // R
        iconData[i * 4 + 1] = g;     // G
        iconData[i * 4 + 2] = b;     // B
        iconData[i * 4 + 3] = 255;   // A
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, iconData);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    return textureID;
}

// Compact optimized window
ImGui::SetNextWindowSize(ImVec2(420, 320), ImGuiCond_Once);
ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_Once);

// Premium purple styling - fully purple design
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.5f);
ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.08f, 0.05f, 0.15f, 0.96f)); // Dark purple
ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.55f, 0.25f, 0.85f, 1.0f)); // Bright purple border
ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.45f, 0.20f, 0.75f, 1.0f)); // Purple title bar
ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.55f, 0.25f, 0.85f, 1.0f)); // Active purple title
ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed, ImVec4(0.35f, 0.15f, 0.65f, 1.0f)); // Collapsed purple

if (ImGui::Begin(OBFUSCATE("DEXX-TER PRO"), 0, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize)) {
    
    // Load tab icons if not already loaded
    if (!iconsLoaded) {
        aimIconTexture = LoadTextureFromFile("AIM_icon");
        espIconTexture = LoadTextureFromFile("ESP_icon");  
        brutalIconTexture = LoadTextureFromFile("BRUTAL_icon");
        iconsLoaded = true;
    }
    
    // Compact layout with vertical tabs on left
    ImGui::Columns(2, "MainLayout", false);
    ImGui::SetColumnWidth(0, 60); // Left column for vertical tabs
    
    // === LEFT COLUMN - VERTICAL IMAGE TABS ===
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 6.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 6));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(6, 6));
    
    // AIM Tab - Image Button
    if (selectedTab == 0) {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.65f, 0.30f, 0.90f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.70f, 0.35f, 0.95f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.75f, 0.40f, 1.0f, 1.0f));
    } else {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.25f, 0.12f, 0.35f, 0.8f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.35f, 0.18f, 0.45f, 0.9f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.45f, 0.22f, 0.55f, 1.0f));
    }
    if (ImGui::ImageButton((void*)(intptr_t)aimIconTexture, ImVec2(32, 32))) selectedTab = 0;
    ImGui::PopStyleColor(3);
    
    // ESP Tab - Image Button
    if (selectedTab == 1) {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.65f, 0.30f, 0.90f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.70f, 0.35f, 0.95f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.75f, 0.40f, 1.0f, 1.0f));
    } else {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.25f, 0.12f, 0.35f, 0.8f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.35f, 0.18f, 0.45f, 0.9f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.45f, 0.22f, 0.55f, 1.0f));
    }
    if (ImGui::ImageButton((void*)(intptr_t)espIconTexture, ImVec2(32, 32))) selectedTab = 1;
    ImGui::PopStyleColor(3);
    
    // BRUTAL Tab - Image Button
    if (selectedTab == 2) {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.65f, 0.30f, 0.90f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.70f, 0.35f, 0.95f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.75f, 0.40f, 1.0f, 1.0f));
    } else {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.25f, 0.12f, 0.35f, 0.8f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.35f, 0.18f, 0.45f, 0.9f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.45f, 0.22f, 0.55f, 1.0f));
    }
    if (ImGui::ImageButton((void*)(intptr_t)brutalIconTexture, ImVec2(32, 32))) selectedTab = 2;
    ImGui::PopStyleColor(3);
    
    ImGui::PopStyleVar(3);
    
    // === RIGHT COLUMN - CONTENT AREA ===
    ImGui::NextColumn();
    
    // Compact content styling
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 4));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(6, 3));
    
    // Purple styling for all elements
    ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(0.85f, 0.45f, 1.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.65f, 0.30f, 0.90f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.85f, 0.45f, 1.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.20f, 0.10f, 0.30f, 0.8f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.30f, 0.15f, 0.40f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.40f, 0.20f, 0.50f, 1.0f));
    
    // Title for current tab
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.85f, 0.50f, 1.0f, 1.0f));
    switch (selectedTab) {
        case 0: ImGui::Text("AIM"); break;
        case 1: ImGui::Text("ESP"); break;
        case 2: ImGui::Text("BRUTAL"); break;
    }
    ImGui::PopStyleColor();
    ImGui::Separator();
    
    // Tab content - optimized and compact
    switch (selectedTab) {
        case 0: // AIM Tab
            ImGui::Checkbox("Aimbot", &Aimbot);
            ImGui::Checkbox("Silent", &SilentAim);
            ImGui::Text("FOV:");
            ImGui::SameLine();
            ImGui::SetNextItemWidth(120);
            ImGui::SliderFloat("##FOV", &Fov_Aim, 0.0f, 360.0f, "%.0f°", ImGuiSliderFlags_AlwaysClamp);
            ImGui::Checkbox("Aimkill", &AimKill1);
            break;
            
        case 1: // ESP Tab
            ImGui::Checkbox("Enable", &Enable);
            ImGui::Checkbox("Line", &Config.ESP.Line);
            ImGui::Checkbox("Box", &Config.ESP.Box);
            ImGui::Checkbox("Distance", &Config.ESP.Health);
            ImGui::Checkbox("Health", &Config.ESP.Health);
            break;
            
        case 2: // BRUTAL Tab
            ImGui::Checkbox("Speed", &speedrun);
            ImGui::Checkbox("Reset", &Reset);
            break;
    }
    
    // Footer
    ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 25);
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.60f, 0.30f, 0.80f, 0.7f));
    ImGui::Text("v3.2 Pro");
    ImGui::PopStyleColor();
    
    ImGui::PopStyleColor(6);
    ImGui::PopStyleVar(3);
    ImGui::Columns(1); // Reset columns
}

ImGui::PopStyleColor(5);
ImGui::PopStyleVar(3);

        
    


    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        return old_eglSwapBuffers(dpy, surface);
}
//}
typedef unsigned long DWORD;
static uintptr_t libBase;

uintptr_t string2Offset(const char *c) {
    int base = 16;
    // See if this function catches all possibilities.
    // If it doesn't, the function would have to be amended
    // whenever you add a combination of architecture and
    // compiler that is not yet addressed.
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
                  || sizeof(uintptr_t) == sizeof(unsigned long long),
                  "Please add string to handle conversion for this architecture.");

    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, base);
}


inline void hack_injec();
inline void StartGUI() {
    void *ptr_eglSwapBuffer = DobbySymbolResolver("/system/lib/libEGL.so", "eglSwapBuffers");
    if (NULL != ptr_eglSwapBuffer) {
        DobbyHook((void *)ptr_eglSwapBuffer, (void*)hook_eglSwapBuffers, (void**)&old_eglSwapBuffers);
            LOGD("Gui Started");
                        hack_injec();
        }
    }

bool libLoaded = false;

DWORD findLibrary(const char *library) {
    char filename[0xFF] = {0},
            buffer[1024] = {0};
    FILE *fp = NULL;
    DWORD address = 0;

    sprintf(filename, OBFUSCATE("/proc/self/maps"));

    fp = fopen(filename, OBFUSCATE("rt"));
    if (fp == NULL) {
        perror(OBFUSCATE("fopen"));
        goto done;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, library)) {
            address = (DWORD) strtoul(buffer, NULL, 16);
            goto done;
        }
    }

    done:

    if (fp) {
        fclose(fp);
    }

    return address;
}

DWORD getAbsoluteAddress(const char *libraryName, DWORD relativeAddr) {
    libBase = findLibrary(libraryName);
    if (libBase == 0)
        return 0;
    return (reinterpret_cast<DWORD>(libBase + relativeAddr));
}
ProcMap unityMap, anogsMap, il2cppMap;
using KittyScanner::RegisterNativeFn;



    
    
void hack() {
     LOGD("Inject Ok");
    //std::thread thread_hack(hack_thread, getpid());
    //thread_hack.detach();
    
}
uintptr_t get_symbol_addr_in_pid(pid_t pid, const char* libname, uintptr_t offset_in_lib) {
    char maps_path[64];
    snprintf(maps_path, sizeof(maps_path), "/proc/%d/maps", pid);

    FILE* fp = fopen(maps_path, "r");
    if (!fp) return 0;

    char line[512];
    uintptr_t base = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, libname)) {
            sscanf(line, "%lx-%*lx", &base);
            break;
        }
    }
    fclose(fp);

    if (base == 0) return 0;
    return base + offset_in_lib;
}

pid_t get_pid_by_name(const char* process_name) {
    DIR* proc_dir = opendir("/proc");
    if (!proc_dir) return -1;

    struct dirent* entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type != DT_DIR) continue;

        pid_t pid = atoi(entry->d_name);
        if (pid <= 0) continue;

        char cmdline_path[256];
        snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/cmdline", pid);

        FILE* fp = fopen(cmdline_path, "r");
        if (!fp) continue;

        char cmdline[256];
        fgets(cmdline, sizeof(cmdline), fp);
        fclose(fp);

        if (strstr(cmdline, process_name)) {
            closedir(proc_dir);
            return pid;
        }
    }

    closedir(proc_dir);
    return -1;
}

void writeLog(const std::string& logMessage, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app); // Mở file ở chế độ append (thêm)
    if (outFile.is_open()) {
        outFile << logMessage << std::endl;
        outFile.close();
    } else {
        std::cerr << "Không thể mở file log: " << filename << std::endl;
    }
}

bool is_current_process(const char* target_name) {
    char cmdline_path[64];
    snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/cmdline", getpid());

    FILE* fp = fopen(cmdline_path, "r");
    if (!fp) return false;

    char cmdline[256] = {0};
    fgets(cmdline, sizeof(cmdline), fp);
    fclose(fp);

    return strcmp(cmdline, target_name) == 0;
}




void hack_injec() {
        while (!unityMap.isValid()) {
        unityMap = KittyMemory::getLibraryBaseMap("libunity.so");
                anogsMap = KittyMemory::getLibraryBaseMap("libanogs.so");
                il2cppMap = KittyMemory::getLibraryBaseMap("libil2cpp.so");
                
        sleep(6);
        }
    
 sleep(5);
    Il2CppAttach();
    
    if (mlovinit()) {
        setShader("_AlphaMask"); //Varies according to game
        LogShaders();
        Wallhack();
    }
    
        

         
        
        //aim silent v2
 DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Weapon"), OBFUSCATE("OnCalcDamageOrHealing"), 1), (void *) BLAGCMCGEJG1,(void **) &old_BLAGCMCGEJG1);
        
        
DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("UpdateBehavior"), 2), (void *) _LateUpdate, (void **) &LateUpdate);
        //aimsilent
        DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("TakeDamage"), 9), (void *) &hook_PlayerNetwork_TakeDamage, (void **) &orig_PlayerNetwork_TakeDamage);
        // Speed Run
       // Speed Run
   DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("IsFoldWingGliding"), 0), (void *) _IsFoldWingGliding, (void **)& IsFoldWingGliding);
        DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("message"), OBFUSCATE("ProtoUtil"), OBFUSCATE("MappingFromPhysXState"), 1), (void *) _LEBIPIGPEEP, (void **)& LEBIPIGPEEP);
    // ResetGuest
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameConfig") , OBFUSCATE("get_ResetGuest"), 0), (void *) ResetGuest, (void **) &_ResetGuest);
    
         // Cam Xa
        DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("FollowCamera"), OBFUSCATE("get_OffsetForNormal"), 0),(void *)_GetCameraHeightRateValue, (void **)&GetCameraHeightRateValue);
    
        
        
    // Bypass
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("AndroidJNI"), OBFUSCATE("IsInstanceOf"), 2), (void *) &_Bypass, (void **) &Bypass);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("JPPGAJBAAKK"), OBFUSCATE("IsOnlineGame"), 2), (void *) &_Bypass, (void **) &Bypass);
   // DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("AnoSDKNamespace"), OBFUSCATE("IOPOOHPNCKH"), OBFUSCATE("LBABEMNOJAJ"), 8), (void *) &_Bypass, (void **) &Bypass);

    //Fix Game
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("mscorlib.dll"), OBFUSCATE("System"), OBFUSCATE("SerializableAttribute"), OBFUSCATE(".ctor"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("GarenaMSDK"), OBFUSCATE("GarenaMSDKMgr"), OBFUSCATE("IsPlatformInstalled"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("System.dll"), OBFUSCATE("System.Net"), OBFUSCATE("WebProxy"), OBFUSCATE("IsBypassed"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("System.dll"), OBFUSCATE("System.Net"), OBFUSCATE("IWebProxy"), OBFUSCATE("IsBypassed"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("System.dll"), OBFUSCATE("System.Net"), OBFUSCATE("WebProxy"), OBFUSCATE(".ctor"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("System.dll"), OBFUSCATE("System.Net"), OBFUSCATE("WebProxy"), OBFUSCATE("CheckBypassList"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("EventLogger"), OBFUSCATE("LogReportCheatInHistory"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("EventLogger"), OBFUSCATE("LogReportCheat"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("MobileReplayManager"), OBFUSCATE("GetGameTimeMS"), 0), (void *) &_FixGame, (void **) &FixGame);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("CreditPunishManager"), OBFUSCATE("ShowPunishWindow"), 0), (void *) &_FixGame, (void **) &FixGame);

        
        
    // Bypass Esp
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("SceneGraphicsQuality"), OBFUSCATE("SetGraphicsQuality"), 0), (void *) _BypassESP, (void **) &BypassESP);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Screen"), OBFUSCATE("SetResolution"), 0), (void *) _BypassESP, (void **) &BypassESP);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("QualitySettings"), OBFUSCATE("GetQualityLevel"), 0), (void *) _BypassESP, (void **) &BypassESP);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("SceneGraphicsQuality"), OBFUSCATE("SetGraphicsQuality"), 0), (void *) _BypassESP, (void **) &BypassESP);

    // Bypass New
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("GCommon"), OBFUSCATE("PlatformUtility_Android"), OBFUSCATE("IsPackageInstalled"), 0), (void *) _Set_Aim, (void **) &Set_Aim);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("GCommon"), OBFUSCATE("PlatformUtility_Android"), OBFUSCATE("CheckFileExists"), 0), (void *) _Set_Aim, (void **) &Set_Aim);
//BLACKLIST FIX BYPASS
        
        
        
        MemoryPatch::createWithHex((uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("AnoSDKNamespace"), OBFUSCATE("IOPOOHPNCKH"), OBFUSCATE("DPLMGOJKKCM"), 1), OBFUSCATE("C0 03 5F D6")).Modify();
    MemoryPatch::createWithHex((uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("AnoSDKNamespace"), OBFUSCATE("IOPOOHPNCKH"), OBFUSCATE("LBABEMNOJAJ"), 2), OBFUSCATE("C0 03 5F D6")).Modify();
    MemoryPatch::createWithHex((uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("AnoSDKNamespace"), OBFUSCATE("IOPOOHPNCKH"), OBFUSCATE("HEKHGDOAMIN"), 3), OBFUSCATE("C0 03 5F D6")).Modify();
    MemoryPatch::createWithHex((uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("AnoSDKNamespace"), OBFUSCATE("IOPOOHPNCKH"), OBFUSCATE("ANMKMIKMELA"), 0), OBFUSCATE("C0 03 5F D6")).Modify();
    MemoryPatch::createWithHex((uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("AnoSDKNamespace"), OBFUSCATE("IOPOOHPNCKH"), OBFUSCATE("AGEDBKLEADA"), 0), OBFUSCATE("C0 03 5F D6")).Modify();
    MemoryPatch::createWithHex((uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("AnoSDKNamespace"), OBFUSCATE("IOPOOHPNCKH"), OBFUSCATE("MKABAAFEIEE"), 4), OBFUSCATE("C0 03 5F D6")).Modify();
    MemoryPatch::createWithHex((uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("AnoSDKNamespace"), OBFUSCATE("IOPOOHPNCKH"), OBFUSCATE("KPEAJPJOEAD"), 2), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
    
    ////DILJOT~MANI~AIMKILL~HOOK
// @MANIx999 @DILJOT666         
// If you give credit to your father, if you don't give credit to your father, then you will be my son, okay my son.
    
    
MemoryPatch::createWithHex((uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameConfig"), OBFUSCATE("get_ResetGuest"), 0), OBFUSCATE("20 00 80 D2 C0 03 5F D6")).Modify();
        // DobbyHook((void *) (uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("UpdateBehavior"), 2), (void *) hook_LateUpdate, (void **) &orig_LateUpdate);
    //hexPatches.Guest = MemoryPatch::createWithHex(getAbsoluteAddress("libil2cpp.so", 0x5ed140c),"20 00 80 D2 C0 03 5F D6");
        OpenURL = (void (*)(String *))Il2CppGetMethodOffset("UnityEngine.CoreModule.dll","UnityEngine","Application","OpenURL",1);

    ImGuiOK = true;
    
}


void hack_thread(pid_t pid) {
        
        StartGUI();
        while(pid == -1){pid = get_pid_by_name("com.dts.freefireth");} 
        remote_inject(pid);
        writeLog(to_string(pid));
    
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void * reserved) {
jvm = vm;
JNIEnv *env;
vm->GetEnv((void **) &env, JNI_VERSION_1_6); 
return JNI_VERSION_1_6;
}

__attribute__((constructor))
void lib_main()
{
    std::thread thread_hack(hack_thread, get_pid_by_name("com.dts.freefireth"));
    thread_hack.detach();
}
//REGISTER_ZYGISK_MODULE(MyModule)

