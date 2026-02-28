// (C) 2026 TEXTA community - TEXTA music - TEXTA StudioX

class Node {
public:
    virtual void process() = 0;
};

class AudioNode {
public:
    virtual void process(AudioBuffer& buffer) = 0;
};