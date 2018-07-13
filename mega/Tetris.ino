void startTetris()
{
  clearLEDMatrix();
  
  createBlock();
  drawActiveBlock();

  refreshLEDMatrix();
}

void createBlock()
{
  long blockNumber = random(0,7);
  Serial.print(blockNumber);
  
  int i = 0;
  
  if (i == 0)
  {
    currentBlock[0][0] = 0; 
    currentBlock[0][1] = 11;
    
    currentBlock[1][0] = 1; 
    currentBlock[1][1] = 11;
    
    currentBlock[2][0] = 0; 
    currentBlock[2][1] = 12;
    
    currentBlock[3][0] = 1; 
    currentBlock[3][1] = 12;
   }
}

void moveBlock(int row, int col)
{   
    delay(200);
  
    for (int i = 0; i <= 3; i++)
    {
      currentBlock[i][0] = currentBlock[i][0] + row;
      currentBlock[i][1] = currentBlock[i][1] + col;
    }

  clearLEDMatrix();
  drawActiveBlock();
  //refreshLEDMatrix();
  FastLED.show();
  
}

void rotate()
{
  
}





