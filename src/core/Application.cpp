// (C) 2026 TEXTA community - TEXTA music - TEXTA StudioX

#include "Application.hpp"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include "../ui/TimelineView.hpp"
#include "../ui/MixerView.hpp"

Application::Application()
{
    initState();    // Initialise l’état de l’application
    initUI();       // Initialise les vues de l'interface utilisateur
}

void Application::initState()
{
    m_state.tracks.push_back({"Drums"});
    m_state.tracks.push_back({"Bass"});
    m_state.tracks.push_back({"Piano"});
}

void Application::initUI()
{
    m_ui.addView(std::make_unique<TimelineView>());
    m_ui.addView(std::make_unique<MixerView>());
}

void Application::run()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1280, 720, "TEXTA StudioX", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        m_ui.render(m_state);

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}