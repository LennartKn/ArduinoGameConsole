#include <FastLED.h>
#include <LinkedList.h>

enum snakeDirections {RIGHT, LEFT, TOP, DOWN}; 
int snakeDirection;
int snakeLength;

struct Coordinates {
  int row = 0;
  int col = 0;
};

int arr[5][2];
LinkedList<Coordinates> *linkedList;

struct Coordinates coordinate0 = {8,8};
struct Coordinates coordinate1 = {8,7};
struct Coordinates coordinate2 = {8,6};
struct Coordinates coordinate3 = {8,5};
struct Coordinates coordinate4 = {8,4};

int snakePosition[5][2] =
{
  {8,8},
  {8,7},
  {8,6},
  {8,5},
  {8,4}
};

void startSnake()
{
  linkedList = new LinkedList<Coordinates>();
  linkedList.add(coordinate0);
  linkedList.add(coordinate1);
  linkedList.add(coordinate2);
  linkedList.add(coordinate3);
  linkedList.add(coordinate4);
  
  clearLEDMatrix();
  drawSnake(CRGB::Yellow, linkedList);
  refreshLEDMatrix();
  
  snakeDirection = DOWN; 
  //snakeLength = 5;
}

void moveSnakeForward()
{
    delay(500);
    
    clearLEDMatrix();
    //setNewSnakeCoordinatesExceptFirst();    
    struct Coordinates newCoordinate;
    
    switch(snakeDirection)
    {
      case RIGHT: newCoordinate =  { linkedList.get(linkedList.size() - 1).row, linkedList.get(linkedList.size() - 1).col + 1 }; break;
      case LEFT: newCoordinate = { linkedList.get(linkedList.size() - 1).row, linkedList.get(linkedList.size() - 1).col - 1 };break;
      case TOP: newCoordinate = { linkedList.get(linkedList.size() - 1).row + 1, linkedList.get(linkedList.size() - 1).col };break;
      case DOWN: newCoordinate = { linkedList.get(linkedList.size() - 1).row - 1, linkedList.get(linkedList.size() - 1).col };break;
      default: break;
    }
     
    linkedList.add(newCoordinate);
    linkedList.remove(0);
    drawSnake(CRGB::Yellow, *linkedList);
    refreshMatrix();
    
    //switch(snakeDirection)
    //{
    //  case RIGHT: snakePosition[0][1] = snakePosition[0][1] + 1; break;
    //  case LEFT: snakePosition[0][1] = snakePosition[0][1] - 1;break;
    //  case TOP: snakePosition[0][0] = snakePosition[0][0] - 1;break;
    //  case DOWN: snakePosition[0][0] = snakePosition[0][0] + 1;break;
    //  default: break;
    //} 

    //drawSnake(CRGB::Yellow, snakePosition);
    //refreshLEDMatrix();

}

void setNewSnakeCoordinatesExceptFirst()
{
    int pufferArray[5][2];
  
    for(int i = 0; i < 5; i++)
    {
       pufferArray[i][0] = snakePosition[i][0];   
       pufferArray[i][1] = snakePosition[i][1];   
    }

     for(int i = 1; i < 5; i++)
     {
      snakePosition[i][0] = pufferArray[i - 1][0];
      snakePosition[i][1] = pufferArray[i - 1][1];
     }    
}

void turnSnakeRight()
{
  switch(snakeDirection)
  {
    case RIGHT: snakeDirection = DOWN;break;
    case LEFT: snakeDirection = TOP;break;
    case TOP: snakeDirection = RIGHT;break;
    case DOWN: snakeDirection = LEFT;break;
  }  
}

void turnSnakeLeft()
{
  switch(snakeDirection)
  {
    case RIGHT: snakeDirection = TOP;break;
    case LEFT: snakeDirection = DOWN;break;
    case TOP: snakeDirection = LEFT;break;
    case DOWN: snakeDirection = RIGHT;break;
  }  
}

