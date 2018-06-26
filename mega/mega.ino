#include <FastLED.h>

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
  Serial.print(btData);
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
  switch(input) 
   {   
      case '0': moveSnakeForward();break;     
      case '1': turnSnakeRight();break;
      case '2': turnSnakeLeft();break;
      default: break;
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
   }
}





