#include <Arduino.h>
#include <Sprites.h>
#include <Print.h>
#include "Font4x6.h"

#define USE_LOWER_CASE

#define FONT4x6_WIDTH 4
#define FONT4x6_HEIGHT 7

#define CHAR_EXCLAMATION 33
#define CHAR_PERIOD 46
#define CHAR_LETTER_A 65
#define CHAR_LETTER_Z 90
#define CHAR_LETTER_A_LOWER 97
#define CHAR_LETTER_Z_LOWER 122
#define CHAR_NUMBER_0 48
#define CHAR_NUMBER_9 57

#ifdef USE_LOWER_CASE
  #define FONT_EXCLAMATION_INDEX 62
  #define FONT_PERIOD_INDEX 63
  #define FONT_NUMBER_INDEX 52
#else
  #define FONT_EXCLAMATION_INDEX 36
  #define FONT_PERIOD_INDEX 37
  #define FONT_NUMBER_INDEX 26
#endif

const uint8_t PROGMEM font_images[] = {
4, 8,
0x3E,	0x09,	0x09,	0x3E,	//A
0x3F,	0x25,	0x25,	0x1A,	
0x1E,	0x21,	0x21,	0x12,	
0x3F,	0x21,	0x21,	0x1E,		
0x3F,	0x25,	0x25,	0x21,	
0x3F,	0x05,	0x05,	0x01,	
0x1E,	0x21,	0x29,	0x3A,		
0x3F,	0x04,	0x04,	0x3F,	
0x21,	0x3F,	0x21,	0x00,	
0x10,	0x21,	0x21,	0x1F,	
0x3F,	0x04,	0x0A,	0x31,		
0x3F,	0x20,	0x20,	0x20,	
0x3F,	0x02,	0x02,	0x3F,	
0x3F,	0x02,	0x04,	0x3F,	
0x1E,	0x21,	0x21,	0x1E,	
0x3F,	0x09,	0x09,	0x06,		
0x1E,	0x21,	0x11,	0x2E,	
0x3F,	0x09,	0x09,	0x36,	
0x22,	0x25,	0x25,	0x19,	
0x01,	0x3F,	0x01,	0x01,	
0x1F,	0x20,	0x20,	0x1F,	
0x0F,	0x10,	0x20,	0x1F,	
0x3F,	0x10,	0x10,	0x3F,		
0x3B,	0x04,	0x04,	0x3B,		
0x03,	0x04,	0x38,	0x07,	
0x31,	0x2D,	0x23,	0x21, // Z
#ifdef USE_LOWER_CASE
0x10,	0x2A,	0x2A,	0x3C,	//a
0x3F,	0x24,	0x24,	0x18,	
0x1C,	0x22,	0x22,	0x14,	
0x18,	0x24,	0x24,	0x3F,	
0x1C,	0x2A,	0x2A,	0x2C,	
0x04,	0x7E,	0x05,	0x01,	
0x4C,	0x52,	0x52,	0x3E,	
0x3F,	0x04,	0x04,	0x38,	
0x24,	0x3D,	0x20,	0x00,	
0x40,	0x40,	0x44,	0x3D,	
0x3F,	0x08,	0x14,	0x22,	
0x21,	0x3F,	0x20,	0x00,	
0x3E,	0x04,	0x04,	0x3E,	
0x3E,	0x04,	0x02,	0x3C,	
0x1C,	0x22,	0x22,	0x1C,	
0x7E,	0x22,	0x22,	0x1C,	
0x1C,	0x22,	0x22,	0x7E,	
0x3E,	0x04,	0x02,	0x04,	
0x24,	0x2A,	0x2A,	0x12,	
0x02,	0x1F,	0x22,	0x20,	
0x1E,	0x20,	0x20,	0x1E,	
0x0E,	0x10,	0x20,	0x1E,	
0x3E,	0x10,	0x10,	0x3E,	
0x36,	0x08,	0x08,	0x36,	
0x4E,	0x50,	0x50,	0x3E,	
0x32,	0x2A,	0x26,	0x22, //z
#endif
0x1E,	0x29,	0x25,	0x1E,	//0
0x22,	0x3F,	0x20,	0x00,	
0x32,	0x29,	0x29,	0x26,	
0x12,	0x21,	0x25,	0x1A,	
0x0C,	0x0A,	0x3F,	0x08,	
0x17,	0x25,	0x25,	0x19,	
0x1E,	0x25,	0x25,	0x18,	
0x01,	0x39,	0x05,	0x03,	
0x1A,	0x25,	0x25,	0x1A,	
0x06,	0x29,	0x29,	0x1E,	//9
0x00,	0x2F,	0x00,	0x00,	//! 
0x00,	0x20,	0x00,	0x00, //.
};


Font4x6::Font4x6(uint8_t lineSpacing) {

  _lineHeight = lineSpacing;
  _letterSpacing = 1;

  _cursorX = _cursorY = _baseX = 0;
  _textColor = 1;

}

size_t Font4x6::write(uint8_t c) {

  if (c == '\n')      { _cursorX = _baseX; _cursorY += _lineHeight; }
  else {

    printChar(c, _cursorX, _cursorY);
    _cursorX += FONT4x6_WIDTH + _letterSpacing;

  }

  return 1;

}

void Font4x6::printChar(const char c, const int8_t x, int8_t y) {

  int8_t idx = -1;

  ++y;
Serial.print(c);
Serial.print(" ");

  switch (c) {
    
    case CHAR_LETTER_A ... CHAR_LETTER_Z:
      idx = c - CHAR_LETTER_A;
      break;

#ifdef USE_LOWER_CASE    
    case CHAR_LETTER_A_LOWER ... CHAR_LETTER_Z_LOWER:
      idx = c - CHAR_LETTER_A_LOWER + 26;
      break;
#endif

    case CHAR_NUMBER_0 ... CHAR_NUMBER_9:
      idx = c - CHAR_NUMBER_0 + FONT_NUMBER_INDEX;
      break;
      
    case CHAR_EXCLAMATION:
      idx = FONT_EXCLAMATION_INDEX;
      break;
      
    case CHAR_PERIOD:
      idx = FONT_PERIOD_INDEX;
      break;

  }

Serial.println(idx);

  if (idx > -1) {
    
    if (_textColor == WHITE) {
      Sprites::drawSelfMasked(x, y, font_images, idx);
    }
    else {
      Sprites::drawErase(x, y, font_images, idx);
    }

  }

}

void Font4x6::setCursor(const int8_t x, const int8_t y) {
  _cursorX = _baseX = x;
  _cursorY = y;
}

void Font4x6::setTextColor(const uint8_t color){
  _textColor = color;
}

void Font4x6::setHeight(const uint8_t color){
  _lineHeight = color;
}
