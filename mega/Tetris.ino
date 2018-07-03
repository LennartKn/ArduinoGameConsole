int currentBlock[4][2];

void startTetris()
{
  clearLEDMatrix();
  
  createBlock(0);
  drawActiveBlock();

  refreshLEDMatrix();
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

void drawActiveBlock()
{
  CRGB color = CRGB::Green;
  
  for (int i = 0; i <= 3; i++)
  {
    leds[getArrayIndexWithCoordinates(currentBlock[i][0], currentBlock[i][1])] = color;
  }
}

void moveBlock(int distanceX, int distanceY)
{   
    for (int i = 0; i <= 3; i++)
    {
    currentBlock[i][0] = currentBlock[i][0] + distanceX;
    currentBlock[i][1] = currentBlock[i][1] + distanceY;
    }
    
  drawActiveBlock();
  FastLED.show();
}

void rotate()
{
  
}





