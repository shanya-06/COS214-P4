#include "SongItem.h"
#include <iostream>

int main() {
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

  std::cout << "\n-> A superfan gets tired of the ads and upgrades to Premium "
               "to support Michael.\n";
  thrillerVerse->upgradeTier();

  std::cout << "\n-> The superfan streams the song repeatedly on Premium.\n";
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

  return 0;
}
