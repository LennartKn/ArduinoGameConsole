#include <FastLED.h>
#include <LinkedList.h>

const int LEDDataPin = 8;
const int amountLEDs = 484;

enum Element {ONE, TWO, CURRENTOPTION};
CRGB leds[amountLEDs];

void setupLEDMatrix()
{
  FastLED.addLeds<NEOPIXEL, LEDDataPin>(leds, amountLEDs);
  FastLED.setBrightness(8);
}

void refreshLEDMatrix()
{
   FastLED.show();   
}

void clearLEDMatrix()
{
    FastLED.clear();
}

int getArrayIndexWithCoordinates(int x, int y)
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

void setAllCoordinatesToArrayIndex()
{
  CRGB pufferArray[484];
  for(int i = 0; i < 22; i++)
  {
    for(int j = 0; j < 22; j++)
    {
      Serial.print(leds[i]);
      pufferArray[getArrayIndexWithCoordinates(i,j)] = leds[22*i + j];
      
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

void draw(int element, CRGB color, int startRow, int startCol)
{    
  switch(element)
  {
    case ONE: drawOne(color, startRow, startCol); break;
    case TWO: drawTwo(color, startRow, startCol); break;
    case CURRENTOPTION: drawCurrentOption(color, startRow, startCol); break;
    default: break;
  }
}

void drawOne(CRGB color, int row, int col)
{
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;  
  leds[getArrayIndexWithCoordinates(row+1, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;  
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;  
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;  
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawTwo(CRGB color, int row, int col)
{    
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawCurrentOption(CRGB color, int row, int col)
{  
  for(int i = 0; i < 22; i++)
  {
    leds[getArrayIndexWithCoordinates(row, col+i)] = color;
  }
  
  for(int i = 0; i < 22; i++)
  {
    leds[getArrayIndexWithCoordinates(row + 6, col+i)] = color;
  }
}

void drawSnake(CRGB color, int snakePosition[5][2])
{
  for(int i = 0; i < 5; i++)
  {
    leds[getArrayIndexWithCoordinates(snakePosition[i][0], snakePosition[i][1])] = color;
  }
}

void drawSnake(CRGB color, LinkedList linkedList)
{
  for(int i = 0; i < linkedList.size(); i++)
  {
    leds[getArrayIndexWithCoordinates(linkedList.get(i).xCor, linkedList.get(i).yCor)] = color;
  }
}

