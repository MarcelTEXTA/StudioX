// gui.cpp
#include "gui.h"
#include "imgui.h"

void RenderMyGui()
{
    ImGui::Begin("Bienvenue");
    ImGui::Text("Salut MarcelTEXTA, bienvenue dans ton application ImGui !");
    static int counter = 0;
    if (ImGui::Button("Clique moi"))
        ++counter;
    ImGui::SameLine();
    ImGui::Text("Compteur = %d", counter);
    ImGui::End();
}