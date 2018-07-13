int blockNumber;
int rowArray[22];
int blockPosition;

void startTetris2()
{
  blockPosition = BLOCKTOP;

  clearLEDMatrix();

  drawTetrisBorder();
  createBlock2();
  drawActiveBlock();

  refreshLEDMatrix();
}

void moveBlock2(int row, int col)
{
  delay(200);
  drawTetrisBorder();

  if (isHit(row, col))
  {
    addCoordinatesToTetrisGround();

    clearLEDMatrix();

    drawTetrisBorder();
    createBlock2();
    drawActiveBlock();
    drawTetrisGround(CRGB::Red);

    refreshLEDMatrix();

    delay(50);

    if (isCompleteRow())
    {
      clearLEDMatrix();

      drawTetrisBorder();
      createBlock2();
      drawActiveBlock();
      drawTetrisGround(CRGB::Red);

      refreshLEDMatrix();
    }

    return;
  }

  for (int i = 0; i <= 3; i++)
  {
    currentBlock[i][0] = currentBlock[i][0] + row;
    currentBlock[i][1] = currentBlock[i][1] + col;
  }

  clearLEDMatrix();

  drawTetrisBorder();
  drawActiveBlock();
  drawTetrisGround(CRGB::Red);

  FastLED.show();
}

void moveBlockHorizontal(int row, int col)
{
  if (isHit(row, col))
  {
    moveBlock2(1, 0);

    return;
  }

  delay(200);

  for (int i = 0; i <= 3; i++)
  {
    currentBlock[i][0] = currentBlock[i][0] + row;
    currentBlock[i][1] = currentBlock[i][1] + col;
  }

  clearLEDMatrix();

  drawTetrisBorder();
  drawActiveBlock();
  drawTetrisGround(CRGB::Red);

  //FastLED.show();
  refreshLEDMatrix();
}

void createBlock2()
{
  blockNumber = random(0, 7168) / 1024 + 1;
  //Serial.print(blockNumber);

  if (blockNumber == 1) //Quadrat
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 5;
    currentBlock[1][0] = 1; currentBlock[1][1] = 5;
    currentBlock[2][0] = 0; currentBlock[2][1] = 6;
    currentBlock[3][0] = 1; currentBlock[3][1] = 6;
  }
  else if (blockNumber == 2) //Balken
  {
    currentBlock[0][0] = 1; currentBlock[0][1] = 5;
    currentBlock[1][0] = 0; currentBlock[1][1] = 5;
    currentBlock[2][0] = 2; currentBlock[2][1] = 5;
    currentBlock[3][0] = 3; currentBlock[3][1] = 5;
  }
  else if (blockNumber == 3) //L
  {
    currentBlock[0][0] = 2; currentBlock[0][1] = 5;
    currentBlock[1][0] = 1; currentBlock[1][1] = 5;
    currentBlock[2][0] = 0; currentBlock[2][1] = 5;
    currentBlock[3][0] = 2; currentBlock[3][1] = 6;
  }
  else if (blockNumber == 4) //L gespiegelt
  {
    currentBlock[0][0] = 2; currentBlock[0][1] = 5;
    currentBlock[1][0] = 1; currentBlock[1][1] = 5;
    currentBlock[2][0] = 0; currentBlock[2][1] = 5;
    currentBlock[3][0] = 2; currentBlock[3][1] = 4;
  }
  else if (blockNumber == 5) //Pyramide
  {
    currentBlock[0][0] = 1; currentBlock[0][1] = 5;
    currentBlock[1][0] = 0; currentBlock[1][1] = 5;
    currentBlock[2][0] = 1; currentBlock[2][1] = 4;
    currentBlock[3][0] = 1; currentBlock[3][1] = 6;
  }
  else if (blockNumber == 6) //S
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 5;
    currentBlock[1][0] = 0; currentBlock[1][1] = 6;
    currentBlock[2][0] = 1; currentBlock[2][1] = 5;
    currentBlock[3][0] = 1; currentBlock[3][1] = 4;
  }
  else //Z
  {
    currentBlock[0][0] = 0; currentBlock[0][1] = 6;
    currentBlock[1][0] = 0; currentBlock[1][1] = 5;
    currentBlock[2][0] = 1; currentBlock[2][1] = 6;
    currentBlock[3][0] = 1; currentBlock[3][1] = 7;
  }
}

void rotate2()
{
  if (blockNumber != 1) {
    int rowCenter = currentBlock[0][0];
    int colCenter = currentBlock[0][1];

    boolean hit = false;

    for (int i = 1; i < 4; i++)
    {
      int newCol = -1 * (currentBlock[i][0] - rowCenter) + colCenter;
      int newRow = 1 * (currentBlock[i][1] - colCenter) + rowCenter;

      if (isHit(newRow - currentBlock[i][0], newCol - currentBlock[i][1])) {
        hit = true;
      }

      currentBlock[i][0] = newRow;
      currentBlock[i][1] = newCol;
    }

    if (hit)
    {
      for (int i = 1; i < 4; i++)
      {
        int newCol = 1 * (currentBlock[i][0] - rowCenter) + colCenter;
        int newRow = -1 * (currentBlock[i][1] - colCenter) + rowCenter;
        currentBlock[i][0] = newRow;
        currentBlock[i][1] = newCol;
      }
    }

    clearLEDMatrix();

    drawTetrisBorder();
    drawActiveBlock();
    drawTetrisGround(CRGB::Red);

    refreshLEDMatrix();
  }

  /* switch(blockNumber)
    {
    case 1: break;
    case 2: rotatePlank(); break;
    case 3: rotateL();break;
    case 4: rotateReverseL();break;
    case 5: rotatePyramide();break;
    case 6: rotateZ();break;
    case 7: rotateReverseZ;break;
    default: break;
    } */
}

boolean isHit(int row, int col)
{
  int nextRow = 0;
  int nextCol = 0;

  for (int i = 0; i <= 3; i++)
  {
    nextRow = currentBlock[i][0] + row;
    nextCol = currentBlock[i][1] + col;

    if (nextRow > 21 || nextCol < 0 || nextCol > 11 || hitTetrisGround(nextRow, nextCol))
      return true;
  }

  return false;
}

void addCoordinatesToTetrisGround()
{
  for (int i = 0; i <= 3; i++)
  {
    Coordinates *coordinate = new Coordinates();
    coordinate -> row = currentBlock[i][0];
    coordinate -> col = currentBlock[i][1];

    tetrisGround.add(coordinate);
  }
}

boolean hitTetrisGround(int nextRow, int nextCol)
{
  for (int i = 0; i < tetrisGround.size(); i++)
  {
    if (tetrisGround.get(i) -> row == nextRow && tetrisGround.get(i) -> col == nextCol)
      return true;
  }

  return false;
}

boolean isCompleteRow()
{
  boolean isComplete = false;

  for (int i = 0; i < 22; i++)
  {
    rowArray[i] = 0;
  }

  for (int i = 0; i < tetrisGround.size(); i++)
  {
    rowArray[tetrisGround.get(i) -> row] = rowArray[tetrisGround.get(i) -> row] + 1;
  }

  for (int i = 0; i < 22; i++)
  {
    if (rowArray[i] == 12)
    {
      removeRow(i);
      isComplete = true;
    }
  }

  return isComplete;
}

void removeRow(int rowNumber)
{
  for (int i = 0; i < tetrisGround.size(); i++)
  {
    if (tetrisGround.get(i) -> row == rowNumber)
    {
      Coordinates *delCor = tetrisGround.get(i);
      delete delCor;

      tetrisGround.remove(i);
      i--;
    }
  }

  for (int i = 0; i < tetrisGround.size(); i++)
  {
    if (tetrisGround.get(i) -> row < rowNumber)
    {
      tetrisGround.get(i) -> row = tetrisGround.get(i) -> row + 1;
    }
  }
}

void printArray()
{
  for (int i = 0; i < 22; i++)
  {
    Serial.print(rowArray[i]);

  }
  Serial.println("");
}

void rotatePlank()
{
  currentBlock[0][0] = currentBlock[0][0] + 2;
  currentBlock[0][1] = currentBlock[0][1] + 2;

  currentBlock[1][0] = 1;
  currentBlock[1][1] = 5;

  currentBlock[2][0] = currentBlock[2][0];
  currentBlock[2][1] = currentBlock[2][1];

  currentBlock[3][0] = 3;
  currentBlock[3][1] = 5;
}

void rotateL()
{
  currentBlock[0][0] = 0; currentBlock[0][1] = 5;
  currentBlock[1][0] = 1; currentBlock[1][1] = 5;
  currentBlock[2][0] = 2; currentBlock[2][1] = 5;
  currentBlock[3][0] = 2; currentBlock[3][1] = 6;
}

void rotateReverseL()
{
  currentBlock[0][0] = 0; currentBlock[0][1] = 5;
  currentBlock[1][0] = 1; currentBlock[1][1] = 5;
  currentBlock[2][0] = 2; currentBlock[2][1] = 5;
  currentBlock[3][0] = 2; currentBlock[3][1] = 4;
}

void rotatePyramide()
{
  currentBlock[0][0] = 0; currentBlock[0][1] = 5;
  currentBlock[1][0] = 1; currentBlock[1][1] = 5;
  currentBlock[2][0] = 1; currentBlock[2][1] = 4;
  currentBlock[3][0] = 1; currentBlock[3][1] = 6;
}

void rotateZ()
{
  currentBlock[0][0] = 0; currentBlock[0][1] = 6;
  currentBlock[1][0] = 0; currentBlock[1][1] = 5;
  currentBlock[2][0] = 1; currentBlock[2][1] = 5;
  currentBlock[3][0] = 1; currentBlock[3][1] = 4;
}

void rotateReverseZ()
{
  currentBlock[0][0] = 0; currentBlock[0][1] = 5;
  currentBlock[1][0] = 0; currentBlock[1][1] = 6;
  currentBlock[2][0] = 1; currentBlock[2][1] = 6;
  currentBlock[3][0] = 1; currentBlock[3][1] = 7;
}

