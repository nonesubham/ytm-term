#pragma once

#include <string>
struct MetaInfo {
    std::string title;
    std::string artist; //aka channel in case of youtube
    std::string duration;
    std::string service_url; // Original URL (youtube.com/watch?v=...)
    std::string audio_url;   // Direct audio URL (rr4...googlevideo.com)
};