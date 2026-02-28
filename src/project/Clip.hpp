// 2026 TEXTA community - TEXTA music - TEXTA StudioX

class Clip {
public:
    std::string name;
    double startTime; // en secondes
    double duration;  // en secondes
    std::vector<float> audioData; // données audio brutes
};