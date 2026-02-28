// 2026 TEXTA community - TEXTA music - TEXTA StudioX

class AddTrackCommand : public Command {
public:
    void execute(AppState& state) override;
    void undo(AppState& state) override;
};