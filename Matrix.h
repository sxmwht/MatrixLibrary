/* A library for driving an 8x8 LED matrix
 * Created by Sam White (@samwhiteUK) */
 

#ifndef Matrix_h
#define Matrix_h

#define RED 'r'
#define GREEN 'g'
#define ORANGE 'o'
#define OFF 0

#include "Arduino.h"

class Matrix {
  public:
    Matrix();
    void scrollText(char message[], int scrollSpeed, char colour);
    void updateDisplay(int displayLength);
    void clearDisplay();
    void draw(byte x, byte y, char colour);
  private:
    boolean checkNextCharacter(char character);
};

#endif
