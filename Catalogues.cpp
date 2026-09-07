#include "Catalogues.h"
#include <algorithm>

Catalog::~Catalog(){}

publishedTracks::publishedTracks(){}

publishedTracks::~publishedTracks(){
  list.clear();
}

std::unique_ptr<iterator> publishedTracks::createIterator(){ 
  return std::unique_ptr<fullTrackListIterator>(
    new fullTrackListIterator(&list)); 
} // storage not ownership, delegates ownership to fullTrackListIterator

void publishedTracks::addSongItem(SongItem* i){ list.push_back(i); }

void publishedTracks::removeSongItem(SongItem* i){
  std::vector<SongItem*>::iterator it = std::find(list.begin(), list.end(), i);
  if(it != list.end()){
    list.erase(it);
  }
}

bool publishedTracks::isEmpty(){ return list.empty(); }

fullTracks::fullTracks(){}

fullTracks::~fullTracks(){
  for(size_t i = 0; i < list.size(); i++) delete list[i]; // full ownership of all tracks, responsible for deleting
  list.clear();
}

std::unique_ptr<iterator> fullTracks::createIterator(){ 
  return std::unique_ptr<fullTrackListIterator>(
    new fullTrackListIterator(&list)); 
}

void fullTracks::addSongItem(SongItem* i){ list.push_back(i);} 

void fullTracks::removeSongItem(SongItem* i){
  std::vector<SongItem*>::iterator it = std::find(list.begin(), list.end(), i);
  if(it != list.end()){
    delete *it;
    list.erase(it);
  }
}

bool fullTracks::isEmpty(){ return list.empty(); }

