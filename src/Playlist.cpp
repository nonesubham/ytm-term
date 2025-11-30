#include "ytm-term/Playlist.hh"
#include <stdexcept>

Playlist::Playlist(const std::vector<std::pair<std::string, std::string>>& playlistTracks ={}) {
    tracks = playlistTracks;
    currentIndex = 0;
}




// Get next track
std::pair<std::string, std::string> Playlist::next() {
    if (tracks.empty()) {
        throw std::runtime_error("Playlist is empty");
    }
    
    if (currentIndex < static_cast<int>(tracks.size()) - 1) {
        currentIndex++;
    }
    return tracks[currentIndex];
}

// Get previous track
std::pair<std::string, std::string> Playlist::previous() {
    
    if (currentIndex > 0) {
        currentIndex--;
    }
    return tracks[currentIndex];
}


std::pair<std::string, std::string> Playlist::select(const int& toIndex) {
    if (tracks.empty()) {
        throw std::runtime_error("Playlist is empty");
    }
    
    if (toIndex < 0 || toIndex >= static_cast<int>(tracks.size())) {
        throw std::out_of_range("Invalid track index");
    }
    
    currentIndex = toIndex;
    return tracks[currentIndex];
}


std::pair<std::string, std::string> Playlist::current() const {
    if (tracks.empty()) {
        throw std::runtime_error("Playlist is empty");
    }
    return tracks[currentIndex];
}


size_t Playlist::size() const {
    return tracks.size();
}


int Playlist::getCurrentIndex() const {
    return currentIndex;
}


bool Playlist::isEmpty() const {
    return tracks.empty();
}

void Playlist::appendTrack(std::pair<std::string, std::string> track){
tracks.push_back(std::move(track));
}
 void Playlist::appendPlaylist(std::vector<std::pair<std::string, std::string>> plist){
    tracks.reserve(tracks.size() + plist.size());
    tracks.insert(tracks.end(), std::make_move_iterator(plist.begin()), std::make_move_iterator(plist.end()));
 }