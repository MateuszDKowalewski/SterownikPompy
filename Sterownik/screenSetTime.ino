byte changeTimeMode;

byte dayToSet;
byte monthToSet;
int yearToSet;
byte hourToSet;
byte minuteToSet;

void setTimeScreen() {
  if (currentMillis >= previousMillisToBlinck) {
    if (currentMillis - previousMillisToBlinck >= blinkInterval) {
      previousMillisToBlinck = currentMillis;
      blinkState = !blinkState;
    }
  } else {
    if ((unsigned long)(4294967295) - previousMillisToBlinck + currentMillis >= blinkInterval) {
      previousMillisToBlinck = currentMillis;
      blinkState = !blinkState;
    }
  }

  switch (changeTimeMode) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("USTAWIENIA CZASU");
      lcd.setCursor(0, 1);
      if (blinkState) {
        if (dayToSet < 10) {
          lcd.print(0);
        }
        lcd.print(dayToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print('/');
      if (monthToSet < 10) {
        lcd.print(0);
      }
      lcd.print(monthToSet);
      lcd.print('/');
      lcd.print(yearToSet);
      lcd.print(' ');
      if (hourToSet < 10) {
        lcd.print('0');
      }
      lcd.print(hourToSet);
      lcd.print(':');
      if (minuteToSet < 10) {
        lcd.print(0);
      }
      lcd.print(minuteToSet);
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("USTAWIENIA CZASU");
      lcd.setCursor(0, 1);
      if (dayToSet < 10) {
        lcd.print(0);
      }
      lcd.print(dayToSet);
      lcd.print('/');
      if (blinkState) {
        if (monthToSet < 10) {
          lcd.print(0);
        }
        lcd.print(monthToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print('/');
      lcd.print(yearToSet);
      lcd.print(' ');
      if (hourToSet < 10) {
        lcd.print('0');
      }
      lcd.print(hourToSet);
      lcd.print(':');
      if (minuteToSet < 10) {
        lcd.print(0);
      }
      lcd.print(minuteToSet);
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("USTAWIENIA CZASU");
      lcd.setCursor(0, 1);
      if (dayToSet < 10) {
        lcd.print(0);
      }
      lcd.print(dayToSet);
      lcd.print('/');
      if (monthToSet < 10) {
        lcd.print(0);
      }
      lcd.print(monthToSet);
      lcd.print('/');
      if (blinkState) {
        lcd.print(yearToSet);
      } else {
        lcd.print("    ");
      }
      lcd.print(' ');
      if (hourToSet < 10) {
        lcd.print('0');
      }
      lcd.print(hourToSet);
      lcd.print(':');
      if (minuteToSet < 10) {
        lcd.print(0);
      }
      lcd.print(minuteToSet);
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("USTAWIENIA CZASU");
      lcd.setCursor(0, 1);
      if (dayToSet < 10) {
        lcd.print(0);
      }
      lcd.print(dayToSet);
      lcd.print('/');
      if (monthToSet < 10) {
        lcd.print(0);
      }
      lcd.print(monthToSet);
      lcd.print('/');
      lcd.print(yearToSet);
      lcd.print(' ');
      if (blinkState) {
        if (hourToSet < 10) {
          lcd.print('0');
        }
        lcd.print(hourToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print(':');
      if (minuteToSet < 10) {
        lcd.print(0);
      }
      lcd.print(minuteToSet);
      break;

    case 4:
      lcd.setCursor(0, 0);
      lcd.print("USTAWIENIA CZASU");
      lcd.setCursor(0, 1);
      if (dayToSet < 10) {
        lcd.print(0);
      }
      lcd.print(dayToSet);
      lcd.print('/');
      if (monthToSet < 10) {
        lcd.print(0);
      }
      lcd.print(monthToSet);
      lcd.print('/');
      lcd.print(yearToSet);
      lcd.print(' ');
      if (hourToSet < 10) {
        lcd.print('0');
      }
      lcd.print(hourToSet);
      lcd.print(':');
      if (blinkState) {
        if (minuteToSet < 10) {
          lcd.print(0);
        }
        lcd.print(minuteToSet);
      } else {
        lcd.print("  ");
      }
      break;

    case 5:
      lcd.setCursor(0, 0);
      lcd.print("CAN'T SET TIME  ");
      lcd.setCursor(0, 1);
      lcd.print("ENTER->TRY AGAIN");
      break;
  }

  switch (changeTimeMode) {
    case 0:
      if (wasButtonBumpped(LEFT)) {
        dayToSet--;
        if (dayToSet == 0) {
          dayToSet = 31;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        dayToSet++;
        if (dayToSet == 32) {
          dayToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        changeTimeMode++;
        blinkState = false;
      }
      break;

    case 1:
      if (wasButtonBumpped(LEFT)) {
        monthToSet--;
        if (monthToSet == 0) {
          monthToSet = 12;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        monthToSet++;
        if (monthToSet == 13) {
          monthToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        if ((monthToSet == 1) || (monthToSet == 3) || (monthToSet == 5) || (monthToSet == 7) || (monthToSet == 8) || (monthToSet == 10) || (monthToSet == 12)) {
          changeTimeMode++;
        } else if (((monthToSet == 4) || (monthToSet == 6) || (monthToSet == 9) || (monthToSet == 11)) && (dayToSet < 31)) {
          changeTimeMode++;
        } else if (dayToSet < 30) {
          changeTimeMode++;
        }
        blinkState = false;
      }
      break;

    case 2:
      if (wasButtonBumpped(LEFT)) {
        yearToSet--;
        if (yearToSet == 2000) {
          yearToSet = 2099;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        yearToSet++;
        if (yearToSet == 2100) {
          yearToSet = 2001;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        if ((monthToSet == 1) || (monthToSet == 3) || (monthToSet == 4) || (monthToSet == 5) || (monthToSet == 6) || (monthToSet == 7) ||
            (monthToSet == 8) || (monthToSet == 9) || (monthToSet == 10) || (monthToSet == 11) || (monthToSet == 12)) {
          changeTimeMode++;
        } else if (dayToSet < 29) {
          changeTimeMode++;
        } else if (yearToSet % 4 == 0) {
          changeTimeMode++;
        }
        blinkState = false;
      }
      break;

    case 3:
      if (wasButtonBumpped(LEFT)) {
        if (hourToSet == 0) {
          hourToSet = 24;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
        hourToSet--;
      }

      if (wasButtonBumpped(RIGHT)) {
        hourToSet++;
        if (hourToSet == 24) {
          hourToSet = 0;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        changeTimeMode++;
        blinkState = false;
      }
      break;

    case 4:
      if (wasButtonBumpped(LEFT)) {
        if (minuteToSet == 0) {
          minuteToSet = 60;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
        minuteToSet--;
      }

      if (wasButtonBumpped(RIGHT)) {
        minuteToSet++;
        if (minuteToSet == 60) {
          minuteToSet = 0;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        tm.Day = dayToSet;
        tm.Month = monthToSet;
        tm.Year = CalendarYrToTm(yearToSet);
        tm.Hour = hourToSet;
        tm.Minute = minuteToSet;
        tm.Second = 0;
        if (RTC.write(tm)) {
          goToHomeScreen();
        } else {
          changeTimeMode++;
        }
      }
      break;

    case 5:
      if (wasButtonBumpped(ENTER)) {
        goToSetTimeScreen();
      }
      break;
  }

  if (wasButtonBumpped(ESCAPE) == true) {
    goToMenuScreen();
  }
}

void goToSetTimeScreen() {
  //Starting set time screen
  changeTimeMode = 0;
  displayMode = 5;
  dayToSet = tm.Day;
  monthToSet = tm.Month;
  yearToSet = tmYearToCalendar(tm.Year);
  hourToSet = tm.Hour;
  minuteToSet = tm.Minute;
  previousMillisToBlinck = currentMillis;
  blinkState = false;
}
