#include "State.h"
#include "SongItem.h"

void InProductionState::addPart(SongItem *context, SongItem *part) {
  context->doAdd(part);
}

void InProductionState::publish(SongItem *context) {
  context->setState(new PublishedState());
}

void PublishedState::addPart(SongItem *context, SongItem *part) {
  std::cout << "Cannot modify a published song" << std::endl;
}