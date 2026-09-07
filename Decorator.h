#ifndef SPECIAL_EFFECTS_H
#define SPECIAL_EFFECTS_H

#include "SongItem.h"

// decorator
class specialEffects : public SongItem
{
  protected: 
    SongItem* baseSong; // wrapped component
  public:
    specialEffects();
    virtual ~specialEffects();

    SongItem* addSpecialEffect(SongItem* i) override;
    virtual void playSong() override;
    
//delegation allows decorated song items behave equally
    void doAdd(SongItem* item) override;
    void add(SongItem* item) override;
    void remove(SongItem* item) override;
    void play() override;
    ExportOptions* createIterator() override;
    std::string getLyric() override;
};

// concrete decorator
class autotune: public specialEffects
{
  public:
    autotune(SongItem* i);
    void playSong();
};

class fadeout: public specialEffects
{
  protected:
    std::string duration(int t);
  public:
    fadeout(SongItem* i);
    void playSong(); 
};

#endif
