// 2026 TEXTA community - TEXTA music - TEXTA StudioX

#pragma once
#include "View.hpp"
#include <imgui.h>

class MixerView : public View
{
public:
    void render(AppState& state) override
    {
        ImGui::Begin("Mixer");

        for (size_t i = 0; i < state.tracks.size(); ++i)
        {
            ImGui::PushID((int)i);

            ImGui::Text("%s", state.tracks[i].name.c_str());
            ImGui::VSliderFloat("Vol", ImVec2(20, 100), 
                &state.tracks[i].volume, 0.0f, 1.0f);
            ImGui::SliderFloat("Pan", 
                &state.tracks[i].pan, -1.0f, 1.0f);

            ImGui::Separator();
            ImGui::PopID();
        }

        ImGui::End();
    }
};