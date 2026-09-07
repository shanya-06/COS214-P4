#include "SongItem.h"

SongItem::SongItem() { currentState = new InProductionState(); }

SongItem::~SongItem() { delete currentState; }

void SongItem::setState(State *state) {
  if (currentState != nullptr) {
    delete currentState;
  }

  currentState = state;
}

State *SongItem::getState() const { return currentState; }

std::string SongItem::getLyric() {
  return ""; // base default
}

void SongItem::publish() { currentState->publish(this); }

void SongItem::stream() { currentState->stream(this); }

void SongItem::upgradeTier() { currentState->upgradeTier(this); }

void SongItem::addRevenue(double amount) { revenue += amount; }

double SongItem::getRevenue() const { return revenue; }

// verse

Verse::Verse() {}

Verse::~Verse() {
  for (SongItem *part : parts)
    delete part;
  parts.clear();
}

void Verse::doAdd(SongItem *item) { parts.push_back(item); }

void Verse::add(SongItem *item) { currentState->addPart(this, item); }

void Verse::remove(SongItem *item) {
  auto it = std::find(parts.begin(), parts.end(), item);
  if (it != parts.end()) {
    delete *it;
    parts.erase(it);
  }
}

void Verse::play() {
  for (SongItem *part : parts)
    part->play(); // recruse into children
}

std::string Verse::getLyric() {
  std::string result;
  for (SongItem *part : parts) {
    result += part->getLyric() + " ";
  }
  return result;
}

SongItem *Verse::addSpecialEffect(SongItem *i) { return this; }

void Verse::playSong() { play(); } // delegates to the existing method

// lyric

Lyric::Lyric(const std::string &t) : text(t) {}

Lyric::~Lyric() {}

void Lyric::doAdd(SongItem *item) { return; }

void Lyric::add(SongItem *item) { return; }

void Lyric::remove(SongItem *item) { return; }

void Lyric::play() { std::cout << "..." << text << "...\n"; }

SongItem *Lyric::addSpecialEffect(SongItem *i) { return this; }

std::string Lyric::getLyric() { return text; }

void Lyric::playSong() { play(); }
