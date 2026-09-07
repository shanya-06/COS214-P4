#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

#include "SongItem.h"

// abstract iterator
class iterator
{
  public:
    virtual ~iterator();
    virtual void first()=0;
    virtual void next()=0;
    virtual bool hasNext()=0;
    virtual SongItem* current()=0;
};

// concrete iterator
class publishedOnlyIterator: public iterator
{
  protected:
    int currentPos;
    std::vector<SongItem*>* itList; // ptr to vector for live iteration & updates
    publishedOnlyIterator(std::vector<SongItem*>* list);
  public:
    ~publishedOnlyIterator();

    void first();
    void next();
    bool hasNext();
    SongItem* current();
};

class fullTrackListIterator: public iterator
{
  protected:
    int currentPos;
    std::vector<SongItem*>* itList;
    fullTrackListIterator(std::vector<SongItem*>* list);
  public:
    ~fullTrackListIterator();

    void first();
    void next();
    bool hasNext();
    SongItem* current();
};
#endif
