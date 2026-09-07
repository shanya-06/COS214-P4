#include "Catalogues.h"
#include "Iterator.h"
#include "SongItem.h"

#include <iostream>

void testIterator(){
  // imagine a track records of all songs

  fullTracks allSongs;

  std::cout << "Testing isEmpty: ";
  if(allSongs.isEmpty()) std::cout << "PASSED\n";
  else std::cout << "FAILED\n";

  SongItem* s1 = new Lyric("Chicago");
  SongItem* s2 = new Lyric("Dirty Diana");
  SongItem* s3 = new Lyric("Bad Guy");

  allSongs.addSongItem(s1);
  allSongs.addSongItem(s2);
  allSongs.addSongItem(s3);

  std::cout << "Testing isEmpty: ";
  if(allSongs.isEmpty()) std::cout << "FAILED\n";
  else std::cout << "PASSED\n";

  allSongs.removeSongItem(s1);

  std::unique_ptr<iterator> fullIt = allSongs.createIterator();

  std::cout << "Full catalog track contents:\n";
  for (fullIt->first(); fullIt->hasNext(); fullIt->next()){
    std::cout << "  " << fullIt->current()->getLyric() << "\n";
  }
  

  // imagine a song item - s2 - gets published

  publishedTracks publishedSongs;

  std::cout << "Testing isEmpty (before publish) : ";
  if(allSongs.isEmpty()) std::cout << "PASSED\n";
  else std::cout << "FAILED\n";

  publishedSongs.addSongItem(s2);

  std::cout << "Testing isEmpty (after publish) : ";
  if(allSongs.isEmpty()) std::cout << "FAILED\n";
  else std::cout << "PASSED\n";

  std::unique_ptr<iterator> pubIt = publishedSongs.createIterator();

  std::cout << "Published catalog contents:\n";

  for (pubIt->first(); pubIt->hasNext(); pubIt->next()){
    std::cout << "  " << pubIt->current()->getLyric() << "\n";
  }

  // test invalid removal:
  publishedSongs.removeSongItem(s1);
  std::cout << "Testing invalid song removal: PASSED\n"; // no crash 

  // allSongs destructor removes s1,s2,s3 when it goes out of scope
  // publishedSongs only erases s2 when it goes out of scope (allSongs does the actual deletion)

}

int main(){
  testIterator();
}