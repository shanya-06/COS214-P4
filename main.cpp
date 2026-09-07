#include "Catalogues.h"
#include "Decorator.h"
#include "Iterator.h"
#include "SongItem.h"

#include <iostream>

void testIterator() {
  // imagine a track records of all songs

  fullTracks allSongs;

  std::cout << "Testing isEmpty: ";
  if (allSongs.isEmpty())
    std::cout << "PASSED\n";
  else
    std::cout << "FAILED\n";

  SongItem *s1 = new Lyric("Chicago");
  SongItem *s2 = new Lyric("Dirty Diana");
  SongItem *s3 = new Lyric("Bad Guy");

  allSongs.addSongItem(s1);
  allSongs.addSongItem(s2);
  allSongs.addSongItem(s3);

  std::cout << "Testing isEmpty: ";
  if (allSongs.isEmpty())
    std::cout << "FAILED\n";
  else
    std::cout << "PASSED\n";

  allSongs.removeSongItem(s1);

  std::unique_ptr<iterator> fullIt = allSongs.createIterator();

  std::cout << "Full catalog track contents:\n";
  for (fullIt->first(); fullIt->hasNext(); fullIt->next()) {
    std::cout << "  " << fullIt->current()->getLyric() << "\n";
  }

  // imagine a song item - s2 - gets published

  publishedTracks publishedSongs;

  std::cout << "Testing isEmpty (before publish) : ";
  if (allSongs.isEmpty())
    std::cout << "PASSED\n";
  else
    std::cout << "FAILED\n";

  publishedSongs.addSongItem(s2);

  std::cout << "Testing isEmpty (after publish) : ";
  if (allSongs.isEmpty())
    std::cout << "FAILED\n";
  else
    std::cout << "PASSED\n";

  std::unique_ptr<iterator> pubIt = publishedSongs.createIterator();

  std::cout << "Published catalog contents:\n";

  for (pubIt->first(); pubIt->hasNext(); pubIt->next()) {
    std::cout << "  " << pubIt->current()->getLyric() << "\n";
  }

  // test invalid removal:
  publishedSongs.removeSongItem(s1);
  std::cout << "Testing invalid song removal: PASSED\n"; // no crash

  // allSongs destructor removes s1,s2,s3 when it goes out of scope
  // publishedSongs only erases s2 when it goes out of scope (allSongs does the
  // actual deletion)
}

void testDecorator() {
  SongItem *base = new Lyric("Something Good");
  SongItem *baseDeco = new fadeout(new autotune(base));

  baseDeco->playSong();

  delete baseDeco;
}

void Scenario1() { // state's main
  std::cout << "=========================================================\n";
  std::cout << "   TaskForge: The Journey of a Hit Song\n";
  std::cout << "=========================================================\n\n";

  std::cout << "-> Michael Jackson enters the studio to record a new hit.\n";
  SongItem *thrillerVerse = new Verse();

  std::cout << "-> Michael records the first few lines of the verse.\n";
  SongItem *lyric1 = new Lyric("It's close to midnight,");
  SongItem *lyric2 = new Lyric("And something evil's lurking in the dark...");
  SongItem *lyric3 = new Lyric("Under the moonlight,");
  SongItem *lyric4 = new Lyric("You see a sight that almost stops your heart.");

  thrillerVerse->add(lyric1);
  thrillerVerse->add(lyric2);
  thrillerVerse->add(lyric3);
  thrillerVerse->add(lyric4);

  std::cout << "-> The studio engineer tries to leak the unfinished track to a "
               "streaming platform...\n";
  thrillerVerse->stream();

  std::cout << "-> An impatient fan tries to buy a Premium version of the "
               "unreleased song...\n";
  thrillerVerse->upgradeTier();

  std::cout << "\n-> Michael Jackson is satisfied and publishes the song to "
               "the world!\n";
  thrillerVerse->publish();

  std::cout << "\n-> A producer tries to sneak in an unwanted auto-tune edit "
               "after the release...\n";
  SongItem *badEdit = new Lyric("Auto-tune YEAH!");
  thrillerVerse->add(badEdit);

  std::cout << "\n-> The fans are loving it! The song gets streamed heavily on "
               "the Free Tier.\n";
  thrillerVerse->stream();
  thrillerVerse->stream();
  thrillerVerse->stream();

  std::cout << "\n-> Let's hear what the fans are listening to!\n";
  thrillerVerse->play();

  std::cout << "\n-> Current Artist Revenue from free streams: $"
            << thrillerVerse->getRevenue() << "\n";

  std::cout << "\n-> Michael's fans get tired of the ads and he upgrades his "
               "song to Premium "
               "\n";
  thrillerVerse->upgradeTier();

  std::cout << "\n-> The superfans stream the song repeatedly on Premium.\n";
  thrillerVerse->stream();
  thrillerVerse->stream();
  thrillerVerse->stream();
  thrillerVerse->stream();

  std::cout << "\n=========================================================\n";
  std::cout << "-> End of the Journey. Total Revenue Earned: $"
            << thrillerVerse->getRevenue() << "\n";
  std::cout << "=========================================================\n";

  // Cleanup
  delete thrillerVerse; // Deletes the Verse, which deletes all attached lyrics
  delete badEdit;       // Deletes the edit that was rejected and never attached
}

// function used to get full coverage
void testCoverageStats() {
  // Decorator & Lyric missing edges
  SongItem *leaf = new Lyric("Test Leaf");
  SongItem *deco = new autotune(leaf);

  deco->doAdd(nullptr);
  deco->add(nullptr);
  deco->remove(nullptr);
  deco->play();
  deco->getLyric();
  deco->addSpecialEffect(leaf);

  leaf->doAdd(nullptr);
  leaf->add(nullptr);
  leaf->remove(nullptr);
  leaf->addSpecialEffect(nullptr);

  delete deco;

  // State missing edges
  SongItem *dummy = new Verse();
  dummy->publish(); // Transitions to PublishedState
  dummy->publish(); // Hits PublishedState::publish

  dummy->upgradeTier(); // Hits PublishedState::upgradeTier (Transitions to
                        // FreeTier)
  dummy->publish();     // Hits FreeTierState::publish
  dummy->add(nullptr);  // Hits FreeTierState::addPart

  dummy->upgradeTier(); // Transitions to PremiumState
  dummy->publish();     // Hits PremiumState::publish
  dummy->add(nullptr);  // Hits PremiumState::addPart
  dummy->upgradeTier(); // Hits PremiumState::upgradeTier

  delete dummy;
}

int main() {
  testIterator();
  testDecorator();
  Scenario1();

  return 0;
}