#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;  //four rows
const byte COLS = 3;  //three columns

char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte rowPins[ROWS] = { 43, 44, 45, 46 };
byte colPins[COLS] = { 42, 41, 40 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


char key;
String c = "";

void setup() {
  Serial.begin(9600);   
}

void loop() {
  key = keypad.getKey();
  if(key){
    c = c + key;
    Serial.println(c);
    c = "";
  }
//  Serial.print("SEND.");
}
