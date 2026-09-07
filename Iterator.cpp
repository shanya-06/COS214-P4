#include "Iterator.h"

publishedOnlyIterator::publishedOnlyIterator(std::vector<SongItem*>* list) : currentPos(0), itList(list) {  }

publishedOnlyIterator::~publishedOnlyIterator(){ }

void publishedOnlyIterator::first(){ currentPos = 0; }

void publishedOnlyIterator::next(){ currentPos++; }

bool publishedOnlyIterator::hasNext(){ return currentPos < itList->size(); }

SongItem* publishedOnlyIterator::current(){ return (*itList)[currentPos]; }

// 

fullTrackListIterator::fullTrackListIterator(std::vector<SongItem*>* list) : currentPos(0), itList(list) {  }

fullTrackListIterator::~fullTrackListIterator(){ }

void fullTrackListIterator::first(){ currentPos = 0; }

void fullTrackListIterator::next(){ currentPos++; }

bool fullTrackListIterator::hasNext(){ return currentPos < itList->size(); }

SongItem* fullTrackListIterator::current(){ return (*itList)[currentPos]; }