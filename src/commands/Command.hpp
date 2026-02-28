// 2026 TEXTA community - TEXTA music - TEXTA StudioX

class Command {
public:
    virtual void execute(AppState& state) = 0;
    virtual void undo(AppState& state) = 0;

    virtual void execute() {
        // Implémentation par défaut (peut être vide)
    }
};