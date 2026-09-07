#include "State.h"
#include "SongItem.h"
#include <iostream>
void InProductionState::addPart(SongItem *context, SongItem *part) {
  context->doAdd(part);
}

void InProductionState::publish(SongItem *context) {
  context->setState(new PublishedState());
}

void InProductionState::stream(SongItem *context) {
  std::cout << "Cannot stream an unreleased song." << std::endl;
}

void InProductionState::upgradeTier(SongItem *context) {
  std::cout << "Access denied! Wait for the song to release first."
            << std::endl;
}

void PublishedState::addPart(SongItem *context, SongItem *part) {
  std::cout << "Cannot modify a published song." << std::endl;
}

void PublishedState::publish(SongItem *context) {
  std::cout << "Song is already published!" << std::endl;
}

void PublishedState::stream(SongItem *context) {
  context->setState(new FreeTierState());
  context->stream();
}

void PublishedState::upgradeTier(SongItem *context) {
  context->setState(new FreeTierState());
}

void FreeTierState::addPart(SongItem *context, SongItem *part) {
  std::cout << "Cannot modify a published song." << std::endl;
}

void FreeTierState::stream(SongItem *context) {
  std::cout << "\n=========================================\n"
            << "|                                       |\n"
            << "|      WANT A BREAK FROM THE ADS?       |\n"
            << "|                                       |\n"
            << "|      ♫ Switch to Premium today! ♫     |\n"
            << "|     No interruptions. Just music.     |\n"
            << "|                                       |\n"
            << "=========================================\n\n";
  context->addRevenue(8.5);
}

void FreeTierState::upgradeTier(SongItem *context) {
  std::cout << "Thank you for upgrading to Premium!!!" << std::endl;
  context->setState(new PremiumState());
}

void FreeTierState::publish(SongItem *context) {
  std::cout << "Song is already published!" << std::endl;
}

void PremiumState::addPart(SongItem *context, SongItem *part) {
  std::cout << "Cannot modify a published song." << std::endl;
}

void PremiumState::publish(SongItem *context) {
  std::cout << "Song is already published!" << std::endl;
}

void PremiumState::stream(SongItem *context) {
  std::cout << "[PREMIUM] No ads, just pure music." << std::endl;
  context->addRevenue(20.82);
}

void PremiumState::upgradeTier(SongItem *context) {
  std::cout << "You are already on the Premium tier!" << std::endl;
}