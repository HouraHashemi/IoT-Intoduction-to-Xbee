#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'c','0','=','+'}
};
byte rowPins[ROWS] = {50, 51, 52, 53}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {23, 24, 25, 26}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//-----------------------------------------------------


void setup() {
  Serial.begin(9600);
}

char key;
String input="";

void loop() {

  key = keypad.getKey();
  if(key){
      input = input + key;
      Serial.print(input);
      input = "";
  }
}
