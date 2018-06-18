const int xpin = 0;
const int ypin = 1;
const int SW_pin = 9;

void setup() {
 
  Serial.begin(9600);

  pinMode(SW_pin, INPUT);
  //digitalWrite(SW_pin, HIGH);
  //Test
}

void loop() {
  if(analogRead(xpin) > 700)
    Serial.write('1');
  else if(analogRead(xpin) < 400)
    Serial.write('2');
  else if(analogRead(ypin) > 700)
    Serial.write('3');
  else if(analogRead(ypin) < 400)
    Serial.write('4');
  else if(digitalRead(SW_pin))
    Serial.write('5');
   
  delay(50);

}
