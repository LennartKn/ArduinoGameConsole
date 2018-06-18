#include <FastLED.h>

const int LEDDataPin = 8;
const int amountLEDs = 484;
CRGB leds[amountLEDs];
char btData;
int currentBlock[4][2];


int matrixRow = 9;
int matrixColumn = 0;

void setup() {
  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL, LEDDataPin>(leds, amountLEDs);
  createBlock(0);
  FastLED.setBrightness(8);
  drawActiveBlock(CRGB::Red);
  FastLED.show();
}
 
void loop() {

  //FastLED.show(); 

  //leds[magicLeonMethod(2,12)] = CRGB::Blue;
  //leds[magicLeonMethod(4,12)] = CRGB::Blue;
  //leds[magicLeonMethod(20,12)] = CRGB::Blue;
  //leds[magicLeonMethod(1,12)] = CRGB::Blue;
  //leds[magicLeonMethod(3,12)] = CRGB::Blue;
  //leds[magicLeonMethod(21,12)] = CRGB::Blue;

  if(Serial.available() > 0)
  {
     btData = Serial.read();
     Serial.print(btData);
     
     switch(btData) {
      case '1': moveBlock(0,1);break;
      case '2': moveBlock(0,-1);break;
      case '3': moveBlock(1,0);break;
      case '4': moveBlock(-1,0);break;
      case '5': rotate(); break;
      default: break;
     }
     FastLED.show(); 
  }

  
   //leds[magicLeonMethod(1,1)] = CRGB::Green;
   //leds[magicLeonMethod(2,1)] = CRGB::Green;
   //leds[magicLeonMethod(3,1)] = CRGB::Green;

  
   //FastLED.show();
 
   delay(5);
}

void createBlock(int i)
{
  if (i == 0)
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 11;
    currentBlock[1][0] = 1; currentBlock[1][1] = 11;
    currentBlock[2][0] = 0; currentBlock[2][1] = 12;
    currentBlock[3][0] = 1; currentBlock[3][1] = 12;
    }
}

void drawActiveBlock(CRGB color)
{
  for (int i = 0; i <= 3; i++)
  {
    leds[magicLeonMethod(currentBlock[i][0], currentBlock[i][1])] = color;
    }
  }

void moveBlock(int distanceX, int distanceY)
{
  drawActiveBlock(CRGB::Black);
    for (int i = 0; i <= 3; i++)
  {
    currentBlock[i][0] = currentBlock[i][0] + distanceX;
    currentBlock[i][1] = currentBlock[i][1] + distanceY;
    }
  drawActiveBlock(CRGB::Red);
  FastLED.show();
}

void rotate()
{
  
}

void mapMatrix()
{
  CRGB pufferArray[484];
  for(int i = 0; i < 22; i++)
  {
    for(int j = 0; j < 22; j++)
    {
      Serial.print(leds[i]);
      pufferArray[magicLeonMethod(i,j)] = leds[22*i + j];
      
      leds[22*i + j] = CRGB::Black;
    }
  }
  
  for(int i = 0; i < 22; i++)
  {
    for(int j = 0; j < 22; j++)
    { 
      leds[22*i+j] = pufferArray[22*i+j]; 
    }
  }
}

int magicLeonMethod(int x, int y)
{
  if(0 > x > 21 || 0 > y > 21)
    return;
  
  if(x%2 == 0)
  {
    return x * 21 + x + y;
  }
  else
  {   
     return (x+1) * 21 + x - y;
  }
}



