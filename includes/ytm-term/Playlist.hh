#pragma once

#include <vector>
#include <utility> 
#include <string>

class Playlist {
private:
    std::vector<std::pair<std::string, std::string>> tracks;
    int currentIndex;

public:
   
    Playlist(const std::vector<std::pair<std::string, std::string>>& playlistTracks);
    
 
    std::pair<std::string, std::string> next();
    std::pair<std::string, std::string> previous();
    std::pair<std::string, std::string> select(const int& toIndex);
    std::pair<std::string, std::string> current() const;
    void appendTrack(std::pair<std::string, std::string> track);
    void appendPlaylist(std::vector<std::pair<std::string, std::string>> plist);    

    size_t size() const;
    int getCurrentIndex() const;
    bool isEmpty() const;

};

