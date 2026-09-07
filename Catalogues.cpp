#include "Catalogues.h"
#include <algorithm>

publishedTracks::publishedTracks(){}

publishedTracks::~publishedTracks(){
  list.clear();
}

iterator* publishedTracks::createIterator(){ return new fullTrackListIterator(&list); } // storage not ownership, delegates ownership to fullTrackListIterator

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
  for(int i = 0; i < list.size(); i++) delete list[i]; // full ownership of all tracks, responsible for deleting
  list.clear();
}
iterator* fullTracks::createIterator(){ return new fullTrackListIterator(&list); }

void fullTracks::addSongItem(SongItem* i){ list.push_back(i);} 

void fullTracks::removeSongItem(SongItem* i){
  std::vector<SongItem*>::iterator it = std::find(list.begin(), list.end(), i);
  if(it != list.end()){
    delete *it;
    list.erase(it);
  }
}

bool fullTracks::isEmpty(){ return list.empty(); }

