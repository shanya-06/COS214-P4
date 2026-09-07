#ifndef STATE_H
#define STATE_H

class SongItem;

class State {
public:
  virtual ~State() = default;

  // Core state behaviors
  virtual void addPart(SongItem *context, SongItem *part) = 0;
  virtual void publish(SongItem *context) = 0;
  virtual void stream(SongItem *context) = 0;
  virtual void upgradeTier(SongItem *context) = 0;
};

class InProductionState : public State {
public:
  virtual ~InProductionState() = default;

  void addPart(SongItem *context, SongItem *part) override;
  void publish(SongItem *context) override;
  void stream(SongItem *context) override;
  void upgradeTier(SongItem *context) override;
};

class PublishedState : public State {
public:
  virtual ~PublishedState() = default;

  void addPart(SongItem *context, SongItem *part) override;
  void publish(SongItem *context) override;
  void stream(SongItem *context) override;
  void upgradeTier(SongItem *context) override;
};

class FreeTierState : public State {
public:
  void addPart(SongItem *context, SongItem *part) override;
  void publish(SongItem *context) override;
  void stream(SongItem *context) override;
  void upgradeTier(SongItem *context) override;
};

class PremiumState : public State {
public:
  void addPart(SongItem *context, SongItem *part) override;
  void publish(SongItem *context) override;
  void stream(SongItem *context) override;
  void upgradeTier(SongItem *context) override;
};

#endif // STATE_H
