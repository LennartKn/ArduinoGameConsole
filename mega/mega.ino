#include <FastLED.h>
#include <LinkedList.h>
#include <MemoryFree.h>

//global variables
class Coordinates {
  public:
    int row;
    int col;
};
int currentBlock[4][2];
LinkedList<Coordinates*> linkedList = LinkedList<Coordinates*>();
LinkedList<Coordinates*> tetrisGround = LinkedList<Coordinates*>();
Coordinates *pointCoordinate = new Coordinates();
boolean gameover;
int points = 0;
typedef  enum snakeDirections {RIGHT, LEFT, TOP, DOWN}; 
int snakeDirection;
typedef enum blockPosition { BLOCKTOP, BLOCKDOWN, BLOCKLEFT, BLOCKRIGHT};

typedef enum Element { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, 
              CURRENTOPTION, QUESTIONMARK, 
              A, B, R, SNAKE, TETRIS, OPT };

int brightness;

//main variables
char btData = '0';
int surface;

void setup() {
  
  Serial.begin(9600);
  setupLEDMatrix();
  surface = 0;
  randomSeed(analogRead(A0));
    
  showMenu();
}
 
void loop() 
{   
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
  if(gameover){
    showGameOverScreen(input);
  }
  else
  {
  
   switch(input) 
   {
        case '0': moveBlock2(1,0); break;
        case '1': moveBlockHorizontal(0,1); break;
        case '2': moveBlockHorizontal(0,-1); break;
        case '5': rotate2(); break;
        default: break;
   }
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



