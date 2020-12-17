void setup() {
  // put your setup code here, to run once:

}
#include <LiquidCrystal.h>


#define PIN_BUTTON 2

#define CAR_POSITION 1

#define CAR_LEFT 1
#define CAR_RIGHT 2

#define R_ROAD_WIDTH 16
#define R_ROAD_EMPTY 0

#define CAR_LEFT
#define ROAD_EMPTY ' '      
#define ROAD_SOLID 5
#define ROAD_SOLID_RIGHT 6
#define ROAD_SOLID_LEFT 7


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
static char upperSide[ROAD_WIDTH +1];
static char lowerSide[ROAD_WIDTH +1];
static bool buttonPushed = false;

void moveRoad(char* road, byte newRoad){
  for(int i=0; i<ROAD_WIDTH; ++i){
    char x = road[i];
    char next = (i == ROAD_WIDTH-1) ? newRoad : road[i+1];
    switch(x){
      case ROAD_EMPTY:
          road[i] = (next == ROAD_SOLID) ? ROAD_SOLID_RIGHT : ROAD_EMPTY;
          break;
        case ROAD_SOLID:
          road[i] = (next == ROAD_EMPTY) ? ROAD_SOLID_LEFT : ROAD_SOLID;
          break;
        case ROAD_SOLID_RIGHT:
          solid[i] = ROAD_SOLID;
          break;
        case ROAD_SOLID_LEFT:
          solid[i] = ROAD_EMPTY;
          break;
      }
  }
}

bool theCar(byte position, char*upperSide, char*lowerSide, unsigned int score){
  bool collide = false;
  char upp = upperSide[CAR_POSITION];
  char low = lowerSide[CAR_POSITION];
  
}

void pushButton(){
  buttonP = true;
}

void setup() {
  byte digits = (score > 999) ? 4 : (score > 99) ? 3 : (score > 9) ? 2 : 1;
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // 
  lcd.setCursor(0,0);
  lcd.print(upperSide);
  upperSide[16-digits] = temp;  
  
  lcd.setCursor(0,1);
  lcd.print(lowerSide);
  
  lcd.setCursor(16 - digits,0);
  lcd.print(score);
}
void loop() {
  // put your main code here, to run repeatedly:
  static bool playing = false;
  static bool blink = false;
  static unsigned int distance = 0;
  
  if(!playing){
    drawCar((blink)? CAR_POSITION_OFF : carPos, upperSide, lowerSide, distance >> 3);
    if(blink){
      lcd.setCursor(0,0);
        lcd.print("Start Game");
    }
    delay(300);
    blink = !blink;
    if (buttonPushed){
      initializeGraphics();
        carPos = CAR_POSITION;
        playing = true;
        buttonPushed = false;
        distance = 0;
    }
    return;
  }
}
