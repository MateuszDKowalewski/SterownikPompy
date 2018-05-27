#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

//Init lcd screen
LiquidCrystal_I2C lcd( 0x27, 2, 1, 0, 4, 5, 6, 7);

//Init buttons
#define OPTION_1 9
#define OPTION_2 8
#define OPTION_3 7
#define LEFT 11
#define RIGHT 10
#define MENU 6
#define MINUS 13
#define PLUS 12

#define PUMP 5

#define RAIN A0

//current data and time
tmElements_t tm;

//Mode o display
//0 - main; 1 - menu; 2 - display; 3 - set day; 4 - set year
byte mode;

void setup() {
  buttonsSetup();
  setupPrewiewScreen();

  //Setup screen
  lcd.begin(16, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);

  pinMode(PUMP, OUTPUT);

  //setup screen mode
  mode = 0;
}

void loop() {
  buttonsReset();
  buttonCheckState();

  //Read current date
  //Show current screen
  if(RTC.read(tm)){
    check();
    
    switch(mode){
      case 0:
        homeScreen();
      break;

      case 1:
        menuScreen();
      break;

      case 2:
        prewiewScreen();
      break;

      case 3:
        setDayScreen();
      break;

      case 4:
        setYearScreen();
      break;
    }

    if(runPump() == true){
      digitalWrite(PUMP, HIGH);
    }else{
      digitalWrite(PUMP, LOW);
    }
  }else{
    RTCError();
  }
}
