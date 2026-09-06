#include "Producer.h"
#include "SongItem.h"

Producer::Producer() { currentSong = nullptr; }

Producer::~Producer() { delete currentSong; }

void Producer::startNewSong() { currentSong = new Verse(); }

void Producer::addComponentToSong(SongItem *component) {
  if (currentSong != nullptr) {
    currentSong->add(component);
  }
}

void Producer::publishSong() {
  if (currentSong != nullptr) {
    currentSong->publish();
  }
}

SongItem *Producer::getSong() const { return currentSong; }