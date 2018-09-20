int currentChoiceOptions;

void startOptions()
{
  currentChoiceOptions = 0;

  clearLEDMatrix();
  
  draw(B, CRGB::Red, 1, 0);
  draw(R, CRGB::Red, 1, 4);
  drawNumber(brightness, CRGB::Yellow, 1, 8);
  draw(B, CRGB::Red, 8, 0);
  draw(A, CRGB::Red, 8, 4);
  draw(C, CRGB::Red, 8, 8);
  draw(K, CRGB::Red, 8, 12);
  
  draw(CURRENTOPTION, CRGB::Blue, 0, 0);

  refreshLEDMatrix();
}

void currentChoiceOptionNext()
{
  if(currentChoiceOptions == 2)
    return;
  
  currentChoiceOptions++;
  
  clearLEDMatrix();

  draw(B, CRGB::Red, 1, 0);
  draw(R, CRGB::Red, 1, 4);
  drawNumber(brightness, CRGB::Yellow, 1, 8);
  draw(B, CRGB::Red, 8, 0);
  draw(A, CRGB::Red, 8, 4);
  draw(C, CRGB::Red, 8, 8);
  draw(K, CRGB::Red, 8, 12);
  
  draw(CURRENTOPTION, CRGB::Blue, currentChoiceOptions*7, 0);

  refreshLEDMatrix();  
}

void currentChoiceOptionBackward()
{
  if(currentChoiceOptions == 0)
    return;
  
  currentChoiceOptions--;
  
  clearLEDMatrix();
  
  draw(B, CRGB::Red, 1, 0);
  draw(R, CRGB::Red, 1, 4);
  drawNumber(brightness, CRGB::Yellow, 1, 8);
  draw(B, CRGB::Red, 8, 0);
  draw(A, CRGB::Red, 8, 4);
  draw(C, CRGB::Red, 8, 8);
  draw(K, CRGB::Red, 8, 12);
  
  draw(CURRENTOPTION, CRGB::Blue, currentChoiceOptions*7, 0);
  
  refreshLEDMatrix();
}

void optionHigher()
{
  if(brightness == 200)
    return;
  
  if(currentChoiceOptions == 0)
  {
    clearLEDMatrix();
    
    brightness++;    
    FastLED.setBrightness(brightness);

    draw(B, CRGB::Red, 1, 0);
    draw(R, CRGB::Red, 1, 4);
    drawNumber(brightness, CRGB::Yellow, 1, 8);
    draw(B, CRGB::Red, 8, 0);
    draw(A, CRGB::Red, 8, 4);
    draw(C, CRGB::Red, 8, 8);
    draw(K, CRGB::Red, 8, 12);
  
    draw(CURRENTOPTION, CRGB::Blue, currentChoiceOptions*7, 0);
    
    refreshLEDMatrix();
  }
  
}

void optionLower()
{
  if(brightness == 0)
    return;
  
  if(currentChoiceOptions == 0)
  {
    clearLEDMatrix();
    
    brightness--;    
    FastLED.setBrightness(brightness);

    draw(B, CRGB::Red, 1, 0);
    draw(R, CRGB::Red, 1, 4);
    drawNumber(brightness, CRGB::Yellow, 1, 8);
    draw(B, CRGB::Red, 8, 0);
    draw(A, CRGB::Red, 8, 4);
    draw(C, CRGB::Red, 8, 8);
    draw(K, CRGB::Red, 8, 12);
  
    draw(CURRENTOPTION, CRGB::Blue, currentChoiceOptions*7, 0);
    
    refreshLEDMatrix();
  }
}

int selectChoiceOption()
{
  switch(currentChoiceOptions)
  {
    case 1: showMenu(); break;
    default: break;
  }

  return 0;
}


