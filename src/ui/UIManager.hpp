// (C) 2026 TEXTA community - TEXTA music - TEXTA StudioX

#pragma once
#include <vector>
#include <memory>
#include "View.hpp"

class UIManager
{
public:
    void addView(std::unique_ptr<View> view)
    {
        m_views.push_back(std::move(view));
    }

    void render(AppState& state)
    {
        for (auto& view : m_views)
            view->render(state);
    }

private:
    std::vector<std::unique_ptr<View>> m_views;
};