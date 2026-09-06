#ifndef STATE_H
#define STATE_H

#include <iostream>

class SongItem;

class State {
public:
  virtual ~State() = default;

  // Core state behaviors
  virtual void addPart(SongItem *context, SongItem *part) = 0;
  virtual void publish(SongItem *context) = 0;
};

class InProductionState : public State {
public:
  virtual ~InProductionState() = default;

  void addPart(SongItem *context, SongItem *part) override;
  void publish(SongItem *context) override;
};

class PublishedState : public State {
public:
  virtual ~PublishedState() = default;

  void addPart(SongItem *context, SongItem *part) override;
  void publish(SongItem *context) override;
};

#endif // STATE_H
