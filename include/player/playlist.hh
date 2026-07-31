#pragma once
#include "track.hh"
#include <string>
#include <vector>
class Playlist {
private:
  std::string name;
  std::vector<track> tracks;
int index;
public:
  std::string getName();
  void appendTrack(track tk);
  void shuffle();
  void next();
  void prev();
  track getTrack();
  
} ;
