#include <FastLED.h>

int currentChoice;

void showMenu()
{
  currentChoice = 0;

  draw(ONE, CRGB::Red, 1, 0);
  draw(TWO, CRGB::Red, 8, 0);
  
  draw(CURRENTOPTION, CRGB::Blue, 0, 0);
  
  refreshLEDMatrix();
}

void currentChoiceNext()
{
  if(currentChoice == 2)
    return;
  
  currentChoice++;
  
  clearLEDMatrix();

  draw(ONE, CRGB::Red, 1, 0);
  draw(TWO, CRGB::Red, 8, 0);
  draw(CURRENTOPTION, CRGB::Blue, currentChoice*7, 0);

  refreshLEDMatrix();  
}

void currentChoiceBackward()
{
  if(currentChoice == 0)
    return;
  
  currentChoice--;
  
  clearLEDMatrix();
  
  draw(ONE, CRGB::Red, 1, 0);
  draw(TWO, CRGB::Red, 8, 0);  
  draw(CURRENTOPTION, CRGB::Blue, currentChoice*7, 0);
  
  refreshLEDMatrix();
}

int selectChoice()
{
  Serial.print(currentChoice);
  switch(currentChoice)
  {
    case 0: startSnake();break;
    case 1: startTetris();break;
    case 2: startOptions();break;
    default: break;
  }
  
  return currentChoice + 1;
}

