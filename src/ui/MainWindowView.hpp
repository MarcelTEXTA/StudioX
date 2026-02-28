// (C) 2026 TEXTA community - TEXTA music - TEXTA StudioX

class MainWindowView {
public:
    MainWindowView() = default;
    ~MainWindowView() = default;

    void render() {
        ImGui::Begin("TEXTA StudioX");
        ImGui::Text("Welcome to TEXTA StudioX!");
        ImGui::End();
    }
};