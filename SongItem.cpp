#include "SongItem.h"

SongItem::SongItem() { currentState = new InProductionState(); }

std::string SongItem::getLyric(){ }

void SongItem::setState(State *state) {
  if (currentState != nullptr) {
    delete currentState;
  }

  currentState = state;
}

void Verse::add(SongItem *item) { currentState->addPart(this, item); }

void Lyric::add(SongItem *item) { return; }

void SongItem::publish() { currentState->publish(this); }

void Verse::doAdd(SongItem *item) { parts.push_back(item); }

void Lyric::doAdd(SongItem *item) { return; }

void SongItem::stream() { currentState->stream(this); }

void SongItem::upgradeTier() { currentState->upgradeTier(this); }

void SongItem::addRevenue(double amount) { revenue += amount; }

double SongItem::getRevenue() const { return revenue; }

std::string Lyric::getLyric(){ return text; }
