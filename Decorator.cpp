#include "Decorator.h"



specialEffects::specialEffects(): baseSong(nullptr) { }

specialEffects::~specialEffects(){ delete baseSong; }

SongItem* specialEffects::addSpecialEffect(SongItem* i){ 
  baseSong = i;
  return this;
 }

void specialEffects::playSong(){ if(baseSong) baseSong->playSong(); }

void specialEffects::doAdd(SongItem* item){
  if (baseSong) baseSong->doAdd(item);
}

void specialEffects::add(SongItem* item){
  if (baseSong) baseSong->add(item);
}

void specialEffects::remove(SongItem* item){
  if (baseSong) baseSong->remove(item);
}

void specialEffects::play(){
  if (baseSong) baseSong->play();
}

ExportOptions* specialEffects::createIterator(){
  return baseSong ? baseSong->createIterator() : nullptr;
}

std::string specialEffects::getLyric(){
  return baseSong ? baseSong->getLyric() : "";
}

autotune::autotune(SongItem* i){ addSpecialEffect(i); }

void autotune::playSong(){
  specialEffects::playSong(); // let wrapped parts go first
  std::cout << "AuToTuNe APpLiEd ('autotune applied') \n";
}

fadeout::fadeout(SongItem* i){ addSpecialEffect(i); }

std::string fadeout::duration(int t){ return std::to_string(t) + "s"; }

void fadeout::playSong(){
  specialEffects::playSong();
  std::cout << "Applying fadeout effect for " << duration(5) << ".\n";
}

