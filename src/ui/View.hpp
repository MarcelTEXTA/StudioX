// (C) 2026 TEXTA community - TEXTA music - TEXTA StudioX

#pragma once
#include "../state/AppState.hpp"

class View {
public:
    virtual ~View() = default;
    virtual void render(AppState& state) = 0;
};