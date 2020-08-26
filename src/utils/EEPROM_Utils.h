#pragma once

#include "Arduboy2Ext.h"
#include "SaveEntry.h"

namespace EEPROM_Utils {

  constexpr size_t eepromStart = 543;
  constexpr size_t eepromStart_C1 = (eepromStart + 0);
  constexpr size_t eepromStart_C2 = (eepromStart + 1);
  constexpr size_t saveEntriesStart = (eepromStart + 2);
  constexpr size_t saveEntriesCount = 3;

  void initialiseEEPROM();
  void clearEEPROM();

  uint8_t saveScore(uint16_t score);
  void saveChar(uint8_t saveIndex, uint8_t charIdx, char newChar);
  
  void readSaveEntry(SaveEntry & entry, uint8_t saveIndex);
  void readSaveEntryName(char (&name)[SaveEntry::nameSize], uint8_t saveIndex);
  uint16_t readSaveEntryScore(uint8_t saveIndex);
  
  void writeSaveEntry(const SaveEntry & entry, uint8_t saveIndex);
  void writeSaveEntryName(const char (&name)[SaveEntry::nameSize], uint8_t saveIndex);
  void writeSaveEntryScore(uint16_t score, uint8_t saveIndex);
  
  template< size_t size >
  void readSaveEntries(SaveEntry (&entries)[size]) {
    constexpr size_t count = (size <= saveEntriesCount) ? size : saveEntriesCount;
    const SaveEntry * saveEntries = reinterpret_cast<const SaveEntry *>(saveEntriesStart);
    eeprom_read_block(&entries[0], &saveEntries[0], sizeof(SaveEntry) * count);
  }

};

