// (C) 2026 TEXTA community - TEXTA music - TEXTA StudioX

#pragma once
#include <vector>
#include <string>

struct TrackState
{
    std::string name;
    float volume = 0.8f;
    float pan = 0.0f;
};

struct TransportState
{
    bool isPlaying = false;
    float bpm = 120.0f;
};

struct AppState
{
    std::vector<TrackState> tracks;
    TransportState transport;
};