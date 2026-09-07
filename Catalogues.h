// aggregates and concrete aggregates
// interface & creation point for creating iterators

#ifndef  CATALOGUES_H
#define CATALOGUES_H

#include <vector>
#include <memory>

#include "SongItem.h"
#include "Iterator.h"

// aggregate
class Catalog
{
  public:
    virtual ~Catalog();
    virtual std::unique_ptr<iterator> createIterator()=0;
    virtual void addSongItem(SongItem* i)=0;
    virtual void removeSongItem(SongItem* i)=0;
    virtual bool isEmpty()=0;
};

// concrete aggregates

// published tracks do not own the song items, iterate only
// avoid double free during cleanup
class publishedTracks: public Catalog
{
  protected: 
    std::vector<SongItem*> list;
  public:
    publishedTracks();
    ~publishedTracks();

    std::unique_ptr<iterator> createIterator();
    void addSongItem(SongItem* i);
    void removeSongItem(SongItem* i);
    bool isEmpty();
};

// full tracks own all tracks and iterates
class fullTracks: public Catalog
{
  protected: 
    std::vector<SongItem*> list;
  public:
    fullTracks();
    ~fullTracks();

    std::unique_ptr<iterator> createIterator();
    void addSongItem(SongItem* i);
    void removeSongItem(SongItem* i);
    bool isEmpty();
};

#endif