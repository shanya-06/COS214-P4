#ifndef SONGITEM_H
#define SONGITEM_H

#include "State.h"
#include <string>
#include <vector>

// Forward declarations
class State;
class ExportOptions;

// Component (Base Class)
class SongItem {
protected:
  State *currentState;
  double revenue = 0.0;

public:
  SongItem();
  virtual ~SongItem(); // Virtual destructor required for polymorphism

  // State methods
  virtual void setState(State *state);
  State *getState() const;
  void publish();
  virtual void doAdd(SongItem *item) = 0;
  // Montisation state methods
  void stream();
  void upgradeTier();
  void addRevenue(double amount);
  double getRevenue() const;

  // Composite Methods
  virtual void add(SongItem *item) = 0;
  virtual void remove(SongItem *item) = 0;
  virtual void play() = 0;

  // Iterator creation
  virtual ExportOptions *createIterator() = 0;
};

// Composite
class Verse : public SongItem {
private:
  std::vector<SongItem *> parts;

public:
  Verse();
  virtual ~Verse(); // Must explicitly delete all parts in implementation

  // adds to composite tree (called by state)
  void doAdd(SongItem *item) override;

  // delegates adding to State pattern (Can only add onto tree if in Published
  // State)
  void add(SongItem *item) override;
  void remove(SongItem *item) override;
  void play() override;
  ExportOptions *createIterator() override;
};

// Leaf
class Lyric : public SongItem {
private:
  std::string text;

public:
  Lyric(const std::string &text);
  virtual ~Lyric();

  void doAdd(SongItem *item) override;
  void add(SongItem *item) override;
  void remove(SongItem *item) override;
  void play() override;
  ExportOptions *createIterator() override;
};

#endif // SONGITEM_H
