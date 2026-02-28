// (C) 2026 TEXTA community - TEXTA music - TEXTA StudioX

#pragma once
#include "../state/AppState.hpp"
#include "../ui/UIManager.hpp"

class Application
{
public:
    Application();
    void run();

private:
    void initState();
    void initUI();

    AppState m_state;
    UIManager m_ui;
};