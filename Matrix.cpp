#include "Matrix.h"

//shift register pins
const byte data      = 3;
const byte clock     = 5;
const byte latch     = 4;

//bitmap for each letter
const byte _A[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100010,
  B00111110,
  B00100010,
  B00100010,
  B00100010};

const byte _B[] = {
  B00000000,
  B00111100,
  B00100010,
  B00100010,
  B00111100,
  B00100010,
  B00100010,
  B00111100};

const byte _C[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100000,
  B00100000,
  B00100000,
  B00100010,
  B00011100};

const byte _D[] = {
  B00000000,
  B00111100,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00111100};

const byte _E[] = {
  B00000000,
  B00111110,
  B00100000,
  B00100000,
  B00111100,
  B00100000,
  B00100000,
  B00111110};

const byte _F[] = {
  B00000000,
  B00111110,
  B00100000,
  B00100000,
  B00111100,
  B00100000,
  B00100000,
  B00100000};

const byte _G[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100000,
  B00101100,
  B00100010,
  B00100010,
  B00011100};

const byte _H[] = {
  B00000000,
  B00100010,
  B00100010,
  B00100010,
  B00111110,
  B00100010,
  B00100010,
  B00100010};

const byte _I[] = {
  B00000000,
  B00111110,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00111110};

const byte _J[] = {
  B00000000,
  B00111110,
  B00001000,
  B00001000,
  B00001000,
  B00101000,
  B00101000,
  B00111000};

const byte _K[] = {
  B00000000,
  B00100010,
  B00100010,
  B00100100,
  B00111100,
  B00100010,
  B00100010,
  B00100010};

const byte _L[] = {
  B00000000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00111110};

const byte _M[] = {
  B00000000,
  B00100010,
  B00110110,
  B00101010,
  B00100010,
  B00100010,
  B00100010,
  B00100010};

const byte _N[] = {
  B00000000,
  B00100010,
  B00110010,
  B00110010,
  B00101010,
  B00100110,
  B00100110,
  B00100010};

const byte _O[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00011100};

const byte _P[] = {
  B00000000,
  B00111100,
  B00100010,
  B00100010,
  B00111100,
  B00100000,
  B00100000,
  B00100000};

const byte _Q[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100010,
  B00100010,
  B00101010,
  B00100110,
  B00011111};

const byte _R[] = {
  B00000000,
  B00111100,
  B00100010,
  B00100010,
  B00111100,
  B00100010,
  B00100010,
  B00100010};

const byte _S[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100000,
  B00011100,
  B00000010,
  B00100010,
  B00011100};

const byte _T[] = {
  B00000000,
  B00111110,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000};

const byte _U[] = {
  B00000000,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00011100};

const byte _V[] = {
  B00000000,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00100010,
  B00010100,
  B00001000};

const byte _W[] = {
  B00000000,
  B00100010,
  B00100010,
  B00100010,
  B00101010,
  B00101010,
  B00101010,
  B00010100};

const byte _X[] = {
  B00000000,
  B00100010,
  B00100010,
  B00010100,
  B00001000,
  B00010100,
  B00100010,
  B00100010};

const byte _Y[] = {
  B00000000,
  B00100010,
  B00100010,
  B00010100,
  B00001000,
  B00001000,
  B00001000,
  B00001000};

const byte _Z[] = {
  B00000000,
  B00111110,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B00111110};

const byte __[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000};

const byte _0[] = {
  B00000000,
  B00011100,
  B00100110,
  B00101010,
  B00101010,
  B00101010,
  B00110010,
  B00011100};

const byte _1[] = {
  B00000000,
  B00001000,
  B00011000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00011100};


const byte _2[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100010,
  B00000100,
  B00001000,
  B00010000,
  B00111110};

const byte _3[] = {
  B00000000,
  B00111100,
  B00100010,
  B00000100,
  B00001100,
  B00000100,
  B00100010,
  B00011100};

const byte _4[] = {
  B00000000,
  B00100000,
  B00100000,
  B00101000,
  B00101000,
  B00111110,
  B00001000,
  B00001000};

const byte _5[] = {
  B00000000,
  B00111110,
  B00100000,
  B00111100,
  B00000010,
  B00100010,
  B00100010,
  B00011100};

const byte _6[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100000,
  B00101100,
  B00110010,
  B00100010,
  B00011100};

const byte _7[] = {
  B00000000,
  B00111110,
  B00100010,
  B00000010,
  B00000100,
  B00001000,
  B00001000,
  B00001000};

const byte _8[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100010,
  B00011100,
  B00100010,
  B00100010,
  B00011100};

const byte _9[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100010,
  B00011110,
  B00000010,
  B00100010,
  B00011100};

const byte _exc[] = {
  B00000000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00000000,
  B00010000};

const byte _prd[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000};

const byte _qmk[] = {
  B00000000,
  B00011100,
  B00100010,
  B00100010,
  B00000100,
  B00001000,
  B00000000,
  B00001000};

const byte _at[] = {
  B00000000,
  B00111100,
  B01000010,
  B01011010,
  B01011010,
  B01011110,
  B01000000,
  B00111100};

const byte _cma[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00001000,
  B00010000};

const byte _apstr[] = {
  B00000000,
  B00011000,
  B00001000,
  B00010000,
  B00000000,
  B00000000,
  B00000000,
  B00000000};

const byte _slsh[] = {
  B00000000,
  B00000100,
  B00000100,
  B00001000,
  B00001000,
  B00010000,
  B00100000,
  B00100000};

const byte _hash[] = {
  B00000000,
  B00010100,
  B00010100,
  B00111110,
  B00010100,
  B00111110,
  B00010100,
  B00010100};

const byte _lftbrc[] = {
  B00000000,
  B00000100,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00000100};

const byte _rtbrc[] = {
  B00000000,
  B00100000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00100000};

const byte _qte[] = {
  B00000000,
  B00101000,
  B00101000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000};

const byte _cln[] = {
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00011000,
  B00011000,
  B00000000};

const byte _smcln[] = {
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00011000,
  B00001000,
  B00010000};

const byte _plus[] = {
  B00000000,
  B00000000,
  B00001000,
  B00001000,
  B00111110,
  B00001000,
  B00001000,
  B00000000};

const byte _minus[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00111110,
  B00000000,
  B00000000,
  B00000000};

const byte _undscr[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00111110};

const byte _eqls[] = {
  B00000000,
  B00000000,
  B00000000,
  B00111110,
  B00000000,
  B00111110,
  B00000000,
  B00000000};

const byte _dlr[] = {
  B00000000,
  B00011100,
  B00101010,
  B00101000,
  B00011100,
  B00001010,
  B00101010,
  B00011100};

const byte _pnd[] = {
  B00000000,
  B00001100,
  B00010010,
  B00010000,
  B00111000,
  B00010000,
  B00010000,
  B00111110};

const byte _pcnt[] = {
  B00000000,
  B00110010,
  B00110100,
  B00000100,
  B00001000,
  B00010000,
  B00010110,
  B00100110};

const byte _carat[] = {
  B00000000,
  B00001000,
  B00010100,
  B00100010,
  B00000000,
  B00000000,
  B00000000,
  B00000000};

const byte _ampsnd[] = {
  B00000000,
  B00011000,
  B00100100,
  B00100000,
  B00010000,
  B00101000,
  B00100100,
  B00011010};

const byte _astrsk[] = {
  B00000000,
  B00001000,
  B00101010,
  B00011100,
  B00101010,
  B00001000,
  B00000000,
  B00000000};

const byte _grtrthn[] = {
  B00000000,
  B00000000,
  B00010000,
  B00001100,
  B00000010,
  B00001100,
  B00010000,
  B00000000};

const byte _lsthn[] = {
  B00000000,
  B00000000,
  B00000100,
  B00011000,
  B00100000,
  B00011000,
  B00000100,
  B00000000};

const byte _tilde[] = {
  B00000000,
  B00000000,
  B00010000,
  B00101010,
  B00101010,
  B00000100,
  B00000000,
  B00000000};

const byte _curlylft[] = {
  B00000000,
  B00000100,
  B00001000,
  B00001000,
  B00010000,
  B00001000,
  B00001000,
  B00000100};

const byte _curlyrt[] = {
  B00000000,
  B00100000,
  B00010000,
  B00010000,
  B00001000,
  B00010000,
  B00010000,
  B00100000}; 

const byte _sqrlft[] = {
  B00000000,
  B00001100,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001100};

const byte _sqrrt[] = {
  B00000000,
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00110000};

const byte _bkslsh[] = {
  B00000000,
  B00100000,
  B00100000,
  B00010000,
  B00010000,
  B00001000,
  B00000100,
  B00000100};

const byte _hook[] = {
  B00000000,
  B00000000,
  B00000000,
  B00111110,
  B00000010,
  B00000010,
  B00000000,
  B00000000};

const byte _othrapstr[] = {
  B00000000,
  B00011000,
  B00010000,
  B00001000,
  B00000000,
  B00000000,
  B00000000,
  B00000000};

const byte _pipe[] = {
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000};

byte redGrid[8] = {
  0};

byte greenGrid[8] = {
  0};

const byte *letters[] = {
  _A,_B,_C,_D,_E,_F,_G,_H,_I,_J,_K,_L,_M,_N,_O,_P,_Q,_R,_S,_T,_U,_V,_W,_X,_Y,_Z,__,
  _0, _1,_2,_3,_4,_5,_6,_7,_8,_9, _prd, _exc, _qmk, _at, _cma, _apstr, _slsh, _hash,
  _lftbrc, _rtbrc, _qte, _cln, _smcln, _plus, _minus, _undscr, _eqls, _dlr, _pnd, _pcnt,
  _carat, _ampsnd, _astrsk, _grtrthn, _lsthn, _tilde, _curlylft, _curlyrt, _sqrlft, _sqrrt,
  _bkslsh, _hook, _othrapstr, _pipe};


const byte* oldChar;
const byte* newChar;

int charNo = 0;

Matrix::Matrix(){
  for(int j=3;j<6;j++){
    pinMode(j, OUTPUT);
  }
  oldChar = letters[26];
  
}

void Matrix::draw(byte x, byte y, char colour){;
  
  if (x > 8)
	x -= 8;
	
  if (y > 8)
	y -= 8;
	
  if (colour == 'r'){
    redGrid[8-y] |= 1<<8-x;
    greenGrid[8-y] &= ~(1<<8-x);
  }
  else if (colour == 'g'){
    redGrid[8-y] &= ~(1<<8-x);
    greenGrid[8-y] |= 1<<8-x;
  }
  else if (colour == 'o'){
    redGrid[8-y] |= 1<<8-x;
    greenGrid[8-y] |= 1<<8-x;
  }

  else if (colour == 0){
    redGrid[8-y] &= ~(1<<8-x);
    greenGrid[8-y] &= ~(1<<8-x);
  }
}

void Matrix::clearDisplay(){
  for (int i = 0; i < 8; i++){
    redGrid[i] = 0;
    greenGrid[i] = 0;
  }
  updateDisplay(1);
}

void Matrix::updateDisplay(int displayLength){
  unsigned long time = millis();
  while (millis() - time < displayLength){
    for (int column = 0; column < 8; column++){    // work down each row
      digitalWrite(latch, LOW);

      shiftOut(data,clock,MSBFIRST, redGrid[column]);
      shiftOut(data,clock,MSBFIRST, 1<<column);
      shiftOut(data,clock,MSBFIRST, 0);  


      digitalWrite(latch, HIGH);
    }
    for (int column = 0; column < 8; column++){    // work down each row
      digitalWrite(latch, LOW);

      shiftOut(data,clock,MSBFIRST, greenGrid[column]);
      shiftOut(data,clock,MSBFIRST, 0);
      shiftOut(data,clock,MSBFIRST, 1<<column);  


      digitalWrite(latch, HIGH);
      
    }  
  }
} 


void Matrix::scrollText(char message[], int scrollSpeed, char colour){
  boolean endReached;
  do {
    endReached = checkNextCharacter(message[charNo]);

    // each letter will make 5 steps
    for (int i = 1; i<7; i++){
      unsigned long time = millis(); //next two lines define the speed of the letters
      while(millis() - time < scrollSpeed){

        if (colour == 'g' || colour == 'o'){
          for (int column = 0; column < 8; column++){    // work down each row
            digitalWrite(latch, LOW);
            shiftOut(data,clock,MSBFIRST, (oldChar[column]<<i)+(newChar[column]>>6-i));      
            //for each increment of i, move the old letter one more LED to the left and the new letter one LESS LED to the right
            shiftOut(data,clock,MSBFIRST, 0);    //move to the next column (1<<column is used to create powers of 2 to avoid rounding errors due to casting floats as ints)
            shiftOut(data,clock,LSBFIRST, 1<<column);
            digitalWrite(latch, HIGH);
          }
        }
        if (colour == 'r' || colour == 'o'){
          for (int column = 0; column < 8; column++){    // work down each row
            digitalWrite(latch, LOW);
            shiftOut(data,clock,MSBFIRST, (oldChar[column]<<i)+(newChar[column]>>6-i));      
            //for each increment of i, move the old letter one more LED to the left and the new letter one LESS LED to the right
            shiftOut(data,clock,MSBFIRST, 1<<column);    //move to the next column (1<<column is used to create powers of 2 to avoid rounding errors due to casting floats as ints)
            shiftOut(data,clock,MSBFIRST, 0);
            digitalWrite(latch, HIGH);
          }
        }
      }
    } 


    oldChar = newChar;
    charNo++;

  }
  while (!endReached);
  
  //clearDisplay();
  updateDisplay(200);

  //delay(200);

}

boolean Matrix::checkNextCharacter(char character){
  boolean endOfLineFlag = 0;
  switch (character){
  case '\0':
    charNo = -1;
    newChar = letters[26];
    endOfLineFlag = 1;
    break;

  case ' ': 
    newChar = letters[26];
    break;

  case '0':
    newChar = letters[27];
    break;

  case '1':
    newChar = letters[28];
    break;

  case '2':
    newChar = letters[29];
    break;

  case '3':
    newChar = letters[30];
    break;

  case '4':
    newChar = letters[31];
    break;

  case '5':
    newChar = letters[32];
    break;

  case '6':
    newChar = letters[33];
    break;

  case '7':
    newChar = letters[34];
    break;

  case '8':
    newChar = letters[35];
    break;

  case '9':
    newChar = letters[36];
    break;

  case '.':
    newChar = letters[37];
    break;  

  case '!':
    newChar = letters[38];
    break;

  case '?':
    newChar = letters[39];
    break;

  case '@':
    newChar = letters[40];
    break;

  case ',':
    newChar = letters[41];
    break;

  case '\'':
    newChar = letters[42];
    break;

  case '/':
    newChar = letters[43];
    break;

  case '#':
    newChar = letters[44];
    break;

  case '(':
    newChar = letters[45];
    break;

  case ')':
    newChar = letters[46];
    break;

  case '"':
    newChar = letters[47];
    break;

  case ':':
    newChar = letters[48];
    break;

  case ';':
    newChar = letters[49];
    break;

  case '+':
    newChar = letters[50];
    break;

  case '-':
    newChar = letters[51];
    break;

  case '_':
    newChar = letters[52];
    break; 

  case '=':
    newChar = letters[53];
    break;

  case '$':
    newChar = letters[54];
    break;

  case '£':
    newChar = letters[55];
    break;

  case '%':
    newChar = letters[56];
    break;

  case '^':
    newChar = letters[57];
    break;

  case '&':
    newChar = letters[58];
    break;

  case '*':
    newChar = letters[59];
    break;

  case '>':
    newChar = letters[60];
    break;

  case '<':
    newChar = letters[61];
    break;

  case '~':
    newChar = letters[62];
    break;

  case '{':
    newChar = letters[63];
    break;

  case '}':
    newChar = letters[64];
    break;

  case '[':
    newChar = letters[65];
    break;

  case ']':
    newChar = letters[66];
    break;

  case '\\':
    newChar = letters[67];
    break;

  case '¬':
    newChar = letters[68];
    break;

  case '`':
    newChar = letters[69];
    break;

  case '|':
    newChar = letters[70];
    break;

  default:
    newChar = letters[character-65];
  }
  
  return endOfLineFlag;
}

