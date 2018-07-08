#include <Keypad.h>;

const int xpin = 0;
const int ypin = 1;
const int SW_pin = 9;

const byte COLS = 2; 
const byte ROWS = 2; 

char hexaKeys[ROWS][COLS]={
  {'9','8'}, // 5,4
  {'7','6'}  // 2,1
};

byte colPins[COLS] = { 4, 5 };
byte rowPins[ROWS] = { 6, 7 };

int last = 0;

char pressedKey;

Keypad myKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
 
  Serial.begin(9600);

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH); 
}

void loop() {

  if(analogRead(xpin) > 700)
  {
    if (last != 1) Serial.write('1'); //Right
    last = 1;
  }
  else if(analogRead(xpin) < 300)
  {
    if (last != 2) Serial.write('2'); //Left
    last = 2;
  }
  else if(analogRead(ypin) <300)
  {
    if (last != 3) Serial.write('3'); //Top
    last = 3;
  }
  else if(analogRead(ypin) > 700)
  {
    if (last != 4) Serial.write('4'); //Down
    last = 4;
  }
  else if(!digitalRead(SW_pin))
  {
   if (last != 5) Serial.write('5'); //Button
    last = 5;
  }
  else 
    last = 0;

  pressedKey = myKeypad.getKey();

  if(pressedKey)
  {
    Serial.println(pressedKey);
    
    //if(pressedKey == '1') 
    //   Serial.write('6'); //1
    //else if(pressedKey == '2')
    //   Serial.write('7'); //2
    //else if(pressedKey == '4')
    //   Serial.write('8'); //4
    //else if(pressedKey == '5')
    //   Serial.write('9'); //5
       
  }
  
  delay(10);
}
