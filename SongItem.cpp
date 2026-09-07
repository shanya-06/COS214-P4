#include "SongItem.h"
#include "State.h"
#include <iostream>

// SongItem 
SongItem::SongItem() : currentState(new InProductionState()), revenue(0.0) {}
SongItem::~SongItem() { delete currentState; }

void SongItem::setState(State* state) {
    if (currentState != nullptr) {
        delete currentState;
    }
    currentState = state;
}

State* SongItem::getState() const { return currentState; }

void SongItem::publish() { currentState->publish(this); }
void SongItem::stream() { currentState->stream(this); }
void SongItem::upgradeTier() { currentState->upgradeTier(this); }

void SongItem::addRevenue(double amount) { revenue += amount; }
double SongItem::getRevenue() const { return revenue; }

// Verse 
Verse::Verse() {}
Verse::~Verse() {
    for (auto* part : parts) {
        delete part;
    }
    parts.clear();
}

void Verse::doAdd(SongItem* item) {
    parts.push_back(item);
}

void Verse::add(SongItem* item) {
    currentState->addPart(this, item);
}

void Verse::remove(SongItem* item) {
    for (auto it = parts.begin(); it != parts.end(); ++it) {
        if (*it == item) {
            delete *it;
            parts.erase(it);
            break;
        }
    }
}

void Verse::play() {
    std::cout << "Playing verse with " << parts.size() << " parts.\n";
    for (auto* part : parts) {
        part>play();
    }
}

ExportOptions* Verse::createIterator() {
    //implement iterator when iterator class done
    return nullptr;
}

// Lyric 
Lyric::Lyric(const std::string& text) : text(text) {}
Lyric::~Lyric() {}

void Lyric::doAdd(SongItem* item) {}

void Lyric::add(SongItem* item) {}

void Lyric::remove(SongItem* item) {/*leaf can't remove*/}

void Lyric::play() {
    std::cout << "Playing lyric: " << text << "\n";
}

ExportOptions* Lyric::createIterator() {
    return nullptr;
}
