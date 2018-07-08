#include <FastLED.h>
#include <LinkedList.h>
#include <MemoryFree.h>;

//global variables
class Coordinates {
  public:
    int row;
    int col;
};
LinkedList<Coordinates*> linkedList = LinkedList<Coordinates*>();
Coordinates *pointCoordinate = new Coordinates();
boolean gameover;
int points = 0;
typedef  enum snakeDirections {RIGHT, LEFT, TOP, DOWN}; 
int snakeDirection;

enum Element { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, 
              CURRENTOPTION, QUESTIONMARK, 
              A, B, R, SNAKE, TETRIS, OPT };

int brightness;

//main variables
char btData = '0';
int surface;

void setup() {
  
  Serial.begin(9600);
  setupLEDMatrix();

  showMenu();
  surface = 0;
}
 
void loop() 
{   
    Serial.print("Mem");
    Serial.print(freeMemory());
  
    switch(surface)
    {
      case 0: inputMenu(btData);break; //Menu
      case 1: inputSnake(btData);break; //Snake
      case 2: inputTetris(btData);break; //Tetris
      case 3: inputOptions(btData);break; //Options
    }

    btData = '0';
    delay(5);
}

void serialEvent()
{
  btData = Serial.read();
  //Serial.print(btData);
}

void inputMenu(int input)
{
  switch(input) 
  {
    case '3': currentChoiceBackward(); break;
    case '4': currentChoiceNext(); break;
    case '5': surface = selectChoice(); break;
    default: break;
  }    
}

void inputSnake(int input)
{
  if(gameover)
    showGameOverScreen(input);
  else
  {
    switch(input) 
     {   
        case '0': moveSnakeForward();break;     
        case '1': turnSnakeRight();break;
        case '2': turnSnakeLeft();break;
        case '6': turnSnakeLeft();break;
        case '7': turnSnakeRight();break;
        default: break;
     }    
   }
}

void inputTetris(int input)
{
   switch(input) 
   {
      case '1': moveBlock(0,1);break;
      case '2': moveBlock(0,-1);break;
      case '3': moveBlock(1,0);break;
      case '4': moveBlock(-1,0);break;
      case '5': rotate(); break;
      default: break;
   }   
}

void inputOptions(int input)
{
   switch(btData) 
   {
        case '1': optionHigher();break;
        case '2': optionLower();break;
        case '3': currentChoiceOptionBackward(); break;
        case '4': currentChoiceOptionNext(); break;
        case '5': surface = selectChoiceOption(); break;
        default: break;
   }
}





