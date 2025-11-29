#include <string>
#include <vector>

// Playlist interface doesn't make sense at this project that's why concrete class

class PlaylistHandler {
private:
    std::vector<std::pair<std::string, std::string>> tracks;
    int currentIndex = 0;
    
public:
    void loadPlaylist(const std::vector<std::pair<std::string, std::string>>& playlistTracks) {
        tracks = playlistTracks;
        currentIndex = 0;
    }
    
    std::pair<std::string, std::string> next() {
        if (currentIndex < tracks.size() - 1) currentIndex++;
        return tracks[currentIndex];
    }
    
    std::pair<std::string, std::string> previous() {
        if (currentIndex > 0) currentIndex--;
        return tracks[currentIndex];
    }

        std::pair<std::string, std::string> select(const int & toIndex) {
        currentIndex = toIndex;
        return tracks[currentIndex];
    }
    
    std::pair<std::string, std::string> current() const {
        return tracks[currentIndex];
    }
};