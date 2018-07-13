const int LEDDataPin = 8;
const int amountLEDs = 484;
CRGB leds[amountLEDs];

void setupLEDMatrix()
{
  FastLED.addLeds<NEOPIXEL, LEDDataPin>(leds, amountLEDs);
  brightness = 10;
  FastLED.setBrightness(brightness);
}

void refreshLEDMatrix()
{
   FastLED.show();   
}

void clearLEDMatrix()
{
   FastLED.clear();
}

int getArrayIndexWithCoordinates(int row, int col)
{
  if(0 > row || row > 21 || 0 > col ||  col > 21)
    return -1;
  
  if(row%2 == 0)
  {
    return row * 21 + row + col;
  }
  else
  {   
     return (row+1) * 21 + row - col;
  }
}

void draw(int element, CRGB color, int startRow, int startCol)
{    
  switch(element)
  {
    case ZERO: drawZero(color, startRow, startCol); break;
    case ONE: drawOne(color, startRow, startCol); break;
    case TWO: drawTwo(color, startRow, startCol); break;
    case THREE: drawThree(color, startRow, startCol); break;
    case FOUR: drawFour(color, startRow, startCol); break;
    case FIVE: drawFive(color, startRow, startCol); break;
    case SIX: drawSix(color, startRow, startCol); break;
    case SEVEN: drawSeven(color, startRow, startCol); break;
    case EIGHT: drawEight(color, startRow, startCol); break;
    case NINE: drawNine(color, startRow, startCol); break;
    case CURRENTOPTION: drawCurrentOption(color, startRow, startCol); break;
    case B: drawB(color, startRow, startCol); break;
    case R: drawR(color, startRow, startCol); break;
    case SNAKE: drawSnake(color, startRow, startCol); break;
    case TETRIS: drawTetris(color, startRow, startCol); break;
    default: QUESTIONMARK: drawQuestionMark(color, startRow, startCol); break;
  }
}

void drawNumber(int number, CRGB color, int startRow, int startCol)
{  
  String score = String(number);
  
  for(int i = 0; i < score.length(); i++)
  {
     String oneValue = String(score.charAt(i));
     int intValue = oneValue.toInt();    
     draw(intValue, color, startRow, startCol +  i * 4);
  }
}

void drawSnake(CRGB color, int row, int col)
{
  
}

void drawTetris(CRGB color, int row, int col)
{
  
}

void drawZero(CRGB color, int row, int col)
{    
  leds[getArrayIndexWithCoordinates(row, col)] = color;
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
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
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawThree(CRGB color, int row, int col)
{    
  leds[getArrayIndexWithCoordinates(row, col)] = color;
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawFour(CRGB color, int row, int col)
{    
  leds[getArrayIndexWithCoordinates(row, col)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawFive(CRGB color, int row, int col)
{ 
  leds[getArrayIndexWithCoordinates(row, col)] = color;   
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawSix(CRGB color, int row, int col)
{    
  leds[getArrayIndexWithCoordinates(row, col)] = color;   
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawSeven(CRGB color, int row, int col)
{ 
  leds[getArrayIndexWithCoordinates(row, col)] = color;   
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
}

void drawEight(CRGB color, int row, int col)
{    
  leds[getArrayIndexWithCoordinates(row, col)] = color;
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawNine(CRGB color, int row, int col)
{    
  leds[getArrayIndexWithCoordinates(row, col)] = color;
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawQuestionMark(CRGB color, int row, int col)
{
  leds[getArrayIndexWithCoordinates(row, col)] = color;  
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;  
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;  
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;  
  leds[getArrayIndexWithCoordinates(row+2, col+2)] = color;  
  leds[getArrayIndexWithCoordinates(row+3, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;

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

void drawB(CRGB color, int row, int col)
{
  leds[getArrayIndexWithCoordinates(row, col)] = color;
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawR(CRGB color, int row, int col)
{
  leds[getArrayIndexWithCoordinates(row, col)] = color;
  leds[getArrayIndexWithCoordinates(row, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col)] = color;
  leds[getArrayIndexWithCoordinates(row+1, col+2)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col)] = color;
  leds[getArrayIndexWithCoordinates(row+2, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col)] = color;
  leds[getArrayIndexWithCoordinates(row+3, col+1)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col)] = color;
  leds[getArrayIndexWithCoordinates(row+4, col+2)] = color;
}

void drawPoint(CRGB color)
{
  leds[getArrayIndexWithCoordinates(pointCoordinate -> row, pointCoordinate -> col)] = color;
}

void drawSnakeList(CRGB color) //LinkedList<Coordinates*> linkedList)
{
  for(int i = 0; i < linkedList.size(); i++)
  {
    leds[getArrayIndexWithCoordinates(linkedList.get(i) -> row, linkedList.get(i) -> col)] = color;
  }
}

void drawTetrisGround(CRGB color) //LinkedList<Coordinates*> linkedList)
{
  for(int i = 0; i < tetrisGround.size(); i++)
  {
    leds[getArrayIndexWithCoordinates(tetrisGround.get(i) -> row, tetrisGround.get(i) -> col)] = color;
  }
}

void showGameOverScreen(int input)
{
   delay(1000);
   clearLEDMatrix();
   drawNumber(points, CRGB::Blue, 5, 5);
   refreshLEDMatrix();
   
   if(input == '5')
    {
       gameover = false;
       startSnake();
    }
}

void drawActiveBlock()
{
  CRGB color = CRGB::Green;
  
  for (int i = 0; i <= 3; i++)
  {
    leds[getArrayIndexWithCoordinates(currentBlock[i][0], currentBlock[i][1])] = color;
  }
}

void drawTetrisBorder()
{
  for(int i = 0; i < 22; i++)
  {
    leds[getArrayIndexWithCoordinates(i, 12)] = CRGB::Blue;
  }
}

