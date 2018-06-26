const int xpin = 0;
const int ypin = 1;
const int SW_pin = 9;

void setup() {
 
  Serial.begin(9600);

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH); 
}

void loop() {
  if(analogRead(xpin) > 700)
    Serial.write('1'); //Right
  else if(analogRead(xpin) < 300)
    Serial.write('2'); //Left
  else if(analogRead(ypin) <300)
    Serial.write('3'); //Top
  else if(analogRead(ypin) > 700)
    Serial.write('4'); //Down
  else if(!digitalRead(SW_pin))
    Serial.write('5'); //Button
  
  delay(200);
}
