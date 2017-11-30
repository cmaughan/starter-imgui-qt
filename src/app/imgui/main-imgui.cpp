// ImGui - standalone example application for SDL2 + OpenGL
// If you are new to ImGui, see examples/README.txt and documentation at the top of imgui.cpp.
#include "mcommon.h"
#include <imgui.h>
#include "imgui/examples/sdl_opengl3_example/imgui_impl_sdl_gl3.h"
#include <stdio.h>
#include <imgui/examples/libs/gl3w/GL/gl3w.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <SDL.h>

#undef max

#include "animation/timer.h"
#include "display_imgui.h"
#include "controller.h"

using namespace StarterKit;

class MainWindow : public IControllerOwner
{
public:
    MainWindow()
        : m_controller(this, std::static_pointer_cast<Display>(std::make_shared<ImGuiDisplay>()))
    {

    }

    Controller& GetController() { return m_controller; }
    bool GetRefreshRequired() const { return m_refreshRequired; }
    virtual void Render(const Rect4f& rc)
    {
        m_controller.Render(rc);
        m_refreshRequired = false;
    }

    // IControllerOwner
    virtual void RequestRedraw() override
    {
        m_refreshRequired = true;
    }


private:
    Controller m_controller;
    bool m_refreshRequired = false;
};

int main(int, char**)
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Setup window
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
    SDL_Window *sdlWindow = SDL_CreateWindow("Main-ImGui", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 250, 200, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
    SDL_GLContext glcontext = SDL_GL_CreateContext(sdlWindow);
    gl3wInit();

    SDL_GL_SetSwapInterval(1);

    // Setup ImGui binding
    ImGui_ImplSdlGL3_Init(sdlWindow);

    bool show_test_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.45f, 0.60f, 1.00f);

    MainWindow mainWin;

    // Main loop
    bool done = false;
    while (!done)
    {
        SDL_Event event;
        if (SDL_WaitEventTimeout(&event, 50))
        {
            ImGui_ImplSdlGL3_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
        }
        else
        {
            if (!mainWin.GetRefreshRequired())
            {
                continue;
            }
        }

        ImGui_ImplSdlGL3_NewFrame(sdlWindow);

        // Draw an empty window to get a full frame area
        bool open = true;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(.1f, .1f, .1f, 1.0f));

        auto size = ImGui::GetIO().DisplaySize;
        ImGui::SetNextWindowSize(size, ImGuiCond_Always);
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
        ImGui::Begin("StarterKit", &open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

        mainWin.Render(Rect4f(ImGui::GetCursorScreenPos().x, ImGui::GetCursorScreenPos().y, ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y));

        ImGui::End();
        ImGui::PopStyleColor(1);
        ImGui::PopStyleVar(2);

        // Rendering
        glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        SDL_GL_SwapWindow(sdlWindow);
    }

    // Cleanup
    ImGui_ImplSdlGL3_Shutdown();
    SDL_GL_DeleteContext(glcontext);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();

    return 0;
}
