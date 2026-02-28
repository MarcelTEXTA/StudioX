// (C) 2026 TEXTA community - TEXTA music - TEXTA StudioX

#pragma once
#include "View.hpp"
#include <imgui.h>

class TimelineView : public View
{
public:
    void render(AppState& state) override
    {
        ImGui::Begin("Timeline");

        if (ImGui::Button(state.transport.isPlaying ? "Stop" : "Play"))
            state.transport.isPlaying = !state.transport.isPlaying;

        ImGui::SliderFloat("BPM", &state.transport.bpm, 40.0f, 240.0f);

        ImGui::Separator();

        for (size_t i = 0; i < state.tracks.size(); ++i)
        {
            ImGui::Text("Track %d: %s", (int)i, state.tracks[i].name.c_str());
        }

        ImGui::End();
    }
};