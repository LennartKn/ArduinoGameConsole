void startSnake()
{
  linkedList.clear();
  
  points = 0;
  
  Coordinates *coordinate0 = new Coordinates();
  coordinate0 -> row = 2; //(*coordinate0).row = 8;
  coordinate0 -> col = 4;
  Coordinates *coordinate1 = new Coordinates();
  coordinate1 -> row = 2;
  coordinate1 -> col = 5;
  Coordinates *coordinate2 = new Coordinates();
  coordinate2 -> row = 2;
  coordinate2 -> col = 6;
  Coordinates *coordinate3 = new Coordinates();
  coordinate3 -> row = 2;
  coordinate3 -> col = 7;
  Coordinates *coordinate4 = new Coordinates();
  coordinate4 -> row = 2;
  coordinate4 -> col = 8;
  
  linkedList.add(coordinate0);
  linkedList.add(coordinate1);
  linkedList.add(coordinate2);
  linkedList.add(coordinate3);
  linkedList.add(coordinate4);
  
  randomSeed(analogRead(0));

  pointCoordinate -> row = random(0, 22);
  pointCoordinate -> col = random(0, 22);
  
  clearLEDMatrix();
  drawSnakeList(CRGB::Yellow);
  drawPoint(CRGB::Blue);
  refreshLEDMatrix();
  
  snakeDirection = RIGHT;
  gameover = false;

}

void moveSnakeForward()
{
    delay(200);
    
    clearLEDMatrix();    

    Coordinates *newCoordinate = new Coordinates();
    
    switch(snakeDirection)
    {       
      case RIGHT: 
        newCoordinate -> row = (linkedList.get(linkedList.size() - 1) -> row); 
        newCoordinate -> col = ((linkedList.get(linkedList.size() - 1) -> col) + 1);  
        break;
      case LEFT: 
        newCoordinate -> row = (linkedList.get(linkedList.size() - 1) -> row); 
        newCoordinate -> col = ((linkedList.get(linkedList.size() - 1) -> col) - 1);  
        break;
      case TOP: 
        newCoordinate -> row = ((linkedList.get(linkedList.size() - 1) -> row) - 1); 
        newCoordinate -> col = (linkedList.get(linkedList.size() - 1) -> col);  
        break;
      case DOWN: 
        newCoordinate -> row = ((linkedList.get(linkedList.size() - 1) -> row) + 1);
        newCoordinate -> col = (linkedList.get(linkedList.size() - 1) -> col);  
        break;
      default: break;
    }
    
    if(isHiT(newCoordinate))
      gameover = true;        

    Coordinates *delCor = linkedList.get(0);    
    delete delCor;
    
    linkedList.add(newCoordinate);
    linkedList.remove(0);
    drawSnakeList(CRGB::Yellow);
    
    checkForPoint(newCoordinate);
    drawPoint(CRGB::Blue);

    refreshLEDMatrix();

}

void turnSnakeRight()
{
  switch(snakeDirection)
  {
    case RIGHT: snakeDirection = DOWN; break;
    case LEFT: snakeDirection = TOP; break;
    case TOP: snakeDirection = RIGHT;break;
    case DOWN: snakeDirection = LEFT;break;
  }  
}

void turnSnakeLeft()
{
  switch(snakeDirection)
  {
    case RIGHT: snakeDirection = TOP; break;
    case LEFT: snakeDirection = DOWN; break;
    case TOP: snakeDirection = LEFT; break;
    case DOWN: snakeDirection = RIGHT; break;
  }  
}

boolean isHiT(Coordinates *coordinate)
{
  if(coordinate -> row < 0 || coordinate -> row > 21 )
    return true;

  if(coordinate -> col < 0 || coordinate -> col > 21 )
    return true;

  for(int i = 0; i < linkedList.size(); i++)
  {
    if(linkedList.get(i) -> row == coordinate -> row && linkedList.get(i) -> col == coordinate -> col)    
      return true;    
  }

  return false;
}

void checkForPoint(Coordinates *coordinate)
{
  if( (coordinate -> row == pointCoordinate -> row) && (coordinate -> col == pointCoordinate -> col) )
  {
    Coordinates *addedCoordinate = new Coordinates;
    linkedList.unshift(addedCoordinate);  
    
    clearLEDMatrix();
    drawSnakeList(CRGB::Yellow);  

    pointCoordinate -> row = random(0, 22);
    pointCoordinate -> col = random(0, 22);

    points++;
  }
    
}



