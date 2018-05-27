#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <EEPROM.h>

//Init lcd screen
LiquidCrystal_I2C lcd( 0x27, 2, 1, 0, 4, 5, 6, 7);

//Init buttons conection
#define ENTER 9
#define ESCAPE 8
#define LEFT 11
#define RIGHT 10

#define PUMP 7

#define RAIN A0

//Mode of display
//0 - home; 1 - menu; 2 - prewiew; 3 - set day; 4 - set year
byte displayMode;

//Current data and time
//Must be updated in all turn of loop
tmElements_t tm;

//First day of sezons
tmElements_t spring;
tmElements_t summer;
tmElements_t autumn;
tmElements_t winter;

//Multitaskintg
//Current time
unsigned long currentMillis;
unsigned long previousMillisToBlackout;
unsigned long previousMillisToBlinck;
unsigned int blackoutInterval;
unsigned int blinkInterval;
bool blinkState;
bool isHighlited;

void setup() {
  //Setup screen
  lcd.begin(16, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);

  pinMode(PUMP, OUTPUT);

  //Setup functions
  setupButtons();
  setSezons();
  setSezonsData();
  goToHomeScreen();
  setON(true);

  //Setup multitasking
  currentMillis = 0;
  previousMillisToBlackout = 0;
  previousMillisToBlinck = 0;
  blackoutInterval = 3000000;
  blinkInterval = 500;

  isHighlited = true;
  displayMode = 0;
}

void loop() {
  buttonsCheckState();
  currentMillis = millis();
  check();
  if (runPump()) {
    digitalWrite(PUMP, HIGH);
  } else {
    digitalWrite(PUMP, LOW);
  }

  if (RTC.read(tm)) {
    //Check display mode, and run funcrion from this mode
    if (isHighlited) {
      switch (displayMode) {
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
          setYearScreen();
          break;

        case 4:
          setDayScreen();
          break;

        case 5:
          setTimeScreen();
          break;
      }
    }
  } else {
    if (isHighlited) {
      RTCError();
    }
  }

  
  if ((wasButtonBumpped(ENTER)) || (wasButtonBumpped(ESCAPE)) || (wasButtonBumpped(LEFT)) || (wasButtonBumpped(RIGHT))) {
    previousMillisToBlackout = currentMillis;
    if (isHighlited == false) {
      isHighlited = true;
      lcd.setBacklight(HIGH);
    }
  }

  if (isHighlited) {
    if (currentMillis >= previousMillisToBlackout) {
      if (currentMillis - previousMillisToBlackout >= blackoutInterval) {
        lcd.setBacklight(LOW);
        isHighlited = false;
        lcd.setCursor(0, 0);
        lcd.print("                ");
        lcd.setCursor(0, 1);
        lcd.print("                ");
        goToHomeScreen();
      }
    } else {
      if ((unsigned long)(4294967295) - previousMillisToBlackout + currentMillis >= blackoutInterval) {
        lcd.setBacklight(LOW);
        isHighlited = false;
        lcd.setCursor(0, 0);
        lcd.print("                ");
        lcd.setCursor(0, 1);
        lcd.print("                ");
        goToHomeScreen();
      }
    }
  }
}

struct Sezon {
  byte startHour;
  byte startMinute;
  byte cycleQuantity;
  byte cycleLenghtMinutes;
  byte breakLenghtMinutes;
};

Sezon springWorkTime;
Sezon summerWorkTime;
Sezon autumnWorkTime;
Sezon winterWorkTime;
