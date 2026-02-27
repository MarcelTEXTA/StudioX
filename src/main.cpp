// src/main.cpp
#include <cstdio>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description)
{
    // Maintenant stderr est connu grâce à <cstdio>
    fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

int main()
{
    // -------------------------------------------------
    // Initialisation de GLFW
    // -------------------------------------------------
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Mon appli ImGui", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);                 // V‑sync

    // -------------------------------------------------
    // Initialisation d’ImGui
    // -------------------------------------------------
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;   // (évite le warning inutilisé)
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");   // version GLSL compatible avec le pilote OpenGL

    // -------------------------------------------------
    // Boucle principale
    // -------------------------------------------------
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Démarrage d’un nouveau frame ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ---- UI personnalisée ----
        ImGui::Begin("Bonjour");
        ImGui::Text("Salut MarcelTEXTA ! Bienvenue dans ImGui.");
        static int counter = 0;
        if (ImGui::Button("Clique moi"))
            ++counter;
        ImGui::SameLine();
        ImGui::Text("Compteur = %d", counter);
        ImGui::End();
        // --------------------------

        // Rendu
        ImGui::Render();
        int w, h;
        glfwGetFramebufferSize(window, &w, &h);
        glViewport(0, 0, w, h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // -------------------------------------------------
    // Nettoyage
    // -------------------------------------------------
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}