int currentBlock[4][2];
int blockNumber;

void startTetris()
{
  randomSeed(analogRead(0));
  clearLEDMatrix();


  //choose block randomly
  blockNumber = random(0, 7);
  Serial.write(blockNumber);
  createBlock(blockNumber);
  drawActiveBlock();
  refreshLEDMatrix();
  
}

void createBlock(int i)
{
  
  if (i == 0) //Quadrat
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 11;
    currentBlock[1][0] = 1; currentBlock[1][1] = 11;
    currentBlock[2][0] = 0; currentBlock[2][1] = 12;
    currentBlock[3][0] = 1; currentBlock[3][1] = 12;
  }
  else if(i == 1) //Balken
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 11;
    currentBlock[1][0] = 1; currentBlock[1][1] = 11;
    currentBlock[2][0] = 2; currentBlock[2][1] = 11;
    currentBlock[3][0] = 3; currentBlock[3][1] = 11;
  }
  else if(i == 2) //L
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 11;
    currentBlock[1][0] = 1; currentBlock[1][1] = 11;
    currentBlock[2][0] = 2; currentBlock[2][1] = 11;
    currentBlock[3][0] = 2; currentBlock[3][1] = 12;
  }
  else if(i == 3) //L gespiegelt
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 11;
    currentBlock[1][0] = 1; currentBlock[1][1] = 11;
    currentBlock[2][0] = 2; currentBlock[2][1] = 11;
    currentBlock[3][0] = 2; currentBlock[3][1] = 10;
  }
  else if(i == 4) //Pyramide
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 11;
    currentBlock[1][0] = 1; currentBlock[1][1] = 11;
    currentBlock[2][0] = 1; currentBlock[2][1] = 10;
    currentBlock[3][0] = 1; currentBlock[3][1] = 12;
  }
  else if(i == 5) //??
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 12;
    currentBlock[1][0] = 0; currentBlock[1][1] = 11;
    currentBlock[2][0] = 1; currentBlock[2][1] = 11;
    currentBlock[3][0] = 1; currentBlock[3][1] = 10;
  }
  else //??
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 11;
    currentBlock[1][0] = 0; currentBlock[1][1] = 12;
    currentBlock[2][0] = 1; currentBlock[2][1] = 12;
    currentBlock[3][0] = 1; currentBlock[3][1] = 13;
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

void moveBlock(int row, int column)
{   
    delay(1000);
    clearLEDMatrix();
    
    for (int i = 0; i <= 3; i++)
    {
    currentBlock[i][0] = currentBlock[i][0] + row;
    currentBlock[i][1] = currentBlock[i][1] + column;
    }
    
  drawActiveBlock();
  FastLED.show();
}

void rotate()
{
  
}

/*void clearFinishedLines(){

  for(int i = 0; i < 22; i++){

    if(lineFinished(i)){
      
    }
  }
  
}*/


/* lineFinished(int lineNumber){

  for(int i = 0; i < 22; i++){
    
    if(leds[getArrayIndexWithCoordinates(lineNumber, i)] == CRGB::Black){
      return false; 
    }    
  }

  return true;
}
*/




