#ifndef PRODUCER_H
#define PRODUCER_H

#include "SongItem.h"
#include "State.h"

class SongItem;
class State;

// Manager (Middleman for State Transitions)
class Producer {
private:
  SongItem *currentSong;

public:
  Producer();
  ~Producer(); // Explicit destruction of the currentSong needed here

  // Lifecycle Management Methods
  void startNewSong();
  void publishSong();

  // Interactions
  void addComponentToSong(SongItem *component);

  // Allows Main/TaskForge to get the song without dealing with its state
  // directly
  SongItem *getSong() const;
};

#endif // PRODUCER_H
