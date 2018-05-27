byte currentSetSezon;
byte currentSetSezonMode;

byte startHourToSet;
byte startMinuteToSet;
byte cycleQuantityToSet;
byte cycleLenghtHoursToSet;
byte cycleLenghtMinutesToSet;
byte breakLenghtHoursToSet;
byte breakLenghtMinutesToSet;

void setDayScreen() {
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

  lcd.setCursor(0, 0);
  switch (currentSetSezon) {
    case 0:
      lcd.print("WI  ");
      break;

    case 1:
      lcd.print("LA  ");
      break;

    case 2:
      lcd.print("JE  ");
      break;

    case 3:
      lcd.print("ZI  ");
      break;
  }

  switch (currentSetSezonMode) {
    case 0:
      lcd.print("ILOSC CYKLI ");
      lcd.setCursor(0, 1);
      lcd.print("             ");
      if (blinkState) {
        if (cycleQuantityToSet < 100) {
          lcd.print(" ");
        }
        if (cycleQuantityToSet < 10) {
          lcd.print(" ");
        }
        lcd.print(cycleQuantityToSet);
      } else {
        lcd.print("   ");
      }
      break;

    case 1:
      lcd.print("START PRACY ");
      lcd.setCursor(0, 1);
      lcd.print("           ");
      if (blinkState) {
        if (startHourToSet < 10) {
          lcd.print(0);
        }
        lcd.print(startHourToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print(':');
      if (startMinuteToSet < 10) {
        lcd.print(0);
      }
      lcd.print(startMinuteToSet);
      break;

    case 2:
      lcd.print("START PRACY ");
      lcd.setCursor(0, 1);
      lcd.print("           ");
      if (startHourToSet < 10) {
        lcd.print(0);
      }
      lcd.print(startHourToSet);
      lcd.print(':');
      if (blinkState) {
        if (startMinuteToSet < 10) {
          lcd.print(0);
        }
        lcd.print(startMinuteToSet);
      } else {
        lcd.print("  ");
      }
      break;

    case 3:
      lcd.print("CZAS PRACY  ");
      lcd.setCursor(0, 1);
      lcd.print("          ");
      if (blinkState) {
        lcd.print(cycleLenghtHoursToSet);
      } else {
        lcd.print(" ");
      }
      lcd.print("h ");
      if (cycleLenghtMinutesToSet < 10) {
        lcd.print(' ');
      }
      lcd.print(cycleLenghtMinutesToSet);
      lcd.print('m');
      break;

    case 4:
      lcd.print("CZAS PRACY  ");
      lcd.setCursor(0, 1);
      lcd.print("          ");
      lcd.print(cycleLenghtHoursToSet);
      lcd.print("h ");
      if (blinkState) {
        if (cycleLenghtMinutesToSet < 10) {
          lcd.print(' ');
        }
        lcd.print(cycleLenghtMinutesToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print('m');
      break;

    case 5:
      lcd.print("CZAS PRZERWY");
      lcd.setCursor(0, 1);
      lcd.print("          ");
      if (blinkState) {
        lcd.print(breakLenghtHoursToSet);
      } else {
        lcd.print(" ");
      }
      lcd.print("h ");
      if (breakLenghtMinutesToSet < 10) {
        lcd.print(' ');
      }
      lcd.print(breakLenghtMinutesToSet);
      lcd.print('m');
      break;

    case 6:
      lcd.print("CZAS PRZERWY");
      lcd.setCursor(0, 1);
      lcd.print("          ");
      lcd.print(breakLenghtHoursToSet);
      lcd.print("h ");
      if (blinkState) {
        if (breakLenghtMinutesToSet < 10) {
          lcd.print(' ');
        }
        lcd.print(breakLenghtMinutesToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print('m');
      break;
  }

  switch (currentSetSezonMode) {
    case 0:
      if (wasButtonBumpped(LEFT)) {
        if (cycleQuantityToSet == 0) {
          cycleQuantityToSet = 255;
        }
        cycleQuantityToSet--;
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        cycleQuantityToSet++;
        if (cycleQuantityToSet == 255) {
          cycleQuantityToSet = 0;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        if (cycleQuantityToSet == 0) {
          switch (currentSetSezon) {
            case 0:
              springWorkTime.startHour = 0;
              springWorkTime.startMinute = 0;
              springWorkTime.cycleQuantity = 0;
              springWorkTime.cycleLenghtMinutes = 0;
              springWorkTime.breakLenghtMinutes = 0;
              EEPROM.update(3, springWorkTime.startHour);
              EEPROM.update(4, springWorkTime.startMinute);
              EEPROM.update(5, springWorkTime.cycleQuantity);
              EEPROM.update(6, springWorkTime.cycleLenghtMinutes);
              EEPROM.update(7, springWorkTime.breakLenghtMinutes);
              startHourToSet = summerWorkTime.startHour;
              startMinuteToSet = summerWorkTime.startMinute;
              cycleQuantityToSet = summerWorkTime.cycleQuantity;
              cycleLenghtHoursToSet = summerWorkTime.cycleLenghtMinutes / 60;
              cycleLenghtMinutesToSet = summerWorkTime.cycleLenghtMinutes % 60;
              breakLenghtHoursToSet = summerWorkTime.breakLenghtMinutes / 60;
              breakLenghtMinutesToSet = summerWorkTime.breakLenghtMinutes % 60;
              currentSetSezon = 1;
              currentSetSezonMode = 0;
              break;

            case 1:
              summerWorkTime.startHour = 0;
              summerWorkTime.startMinute = 0;
              summerWorkTime.cycleQuantity = 0;
              summerWorkTime.cycleLenghtMinutes = 0;
              summerWorkTime.breakLenghtMinutes = 0;
              EEPROM.update(10, summerWorkTime.startHour);
              EEPROM.update(11, summerWorkTime.startMinute);
              EEPROM.update(12, summerWorkTime.cycleQuantity);
              EEPROM.update(13, summerWorkTime.cycleLenghtMinutes);
              EEPROM.update(14, summerWorkTime.breakLenghtMinutes);
              startHourToSet = autumnWorkTime.startHour;
              startMinuteToSet = autumnWorkTime.startMinute;
              cycleQuantityToSet = autumnWorkTime.cycleQuantity;
              cycleLenghtHoursToSet = autumnWorkTime.cycleLenghtMinutes / 60;
              cycleLenghtMinutesToSet = autumnWorkTime.cycleLenghtMinutes % 60;
              breakLenghtHoursToSet = autumnWorkTime.breakLenghtMinutes / 60;
              breakLenghtMinutesToSet = autumnWorkTime.breakLenghtMinutes % 60;
              currentSetSezon = 2;
              currentSetSezonMode = 0;
              break;

            case 2:
              autumnWorkTime.startHour = 0;
              autumnWorkTime.startMinute = 0;
              autumnWorkTime.cycleQuantity = 0;
              autumnWorkTime.cycleLenghtMinutes = 0;
              autumnWorkTime.breakLenghtMinutes = 0;
              EEPROM.update(17, autumnWorkTime.startHour);
              EEPROM.update(18, autumnWorkTime.startMinute);
              EEPROM.update(19, autumnWorkTime.cycleQuantity);
              EEPROM.update(20, autumnWorkTime.cycleLenghtMinutes);
              EEPROM.update(21, autumnWorkTime.breakLenghtMinutes);
              startHourToSet = winterWorkTime.startHour;
              startMinuteToSet = winterWorkTime.startMinute;
              cycleQuantityToSet = winterWorkTime.cycleQuantity;
              cycleLenghtHoursToSet = winterWorkTime.cycleLenghtMinutes / 60;
              cycleLenghtMinutesToSet = winterWorkTime.cycleLenghtMinutes % 60;
              breakLenghtHoursToSet = winterWorkTime.breakLenghtMinutes / 60;
              breakLenghtMinutesToSet = winterWorkTime.breakLenghtMinutes % 60;
              currentSetSezon = 3;
              currentSetSezonMode = 0;
              break;

            case 3:
              winterWorkTime.startHour = 0;
              winterWorkTime.startMinute = 0;
              winterWorkTime.cycleQuantity = 0;
              winterWorkTime.cycleLenghtMinutes = 0;
              winterWorkTime.breakLenghtMinutes = 0;
              EEPROM.update(24, winterWorkTime.startHour);
              EEPROM.update(25, winterWorkTime.startMinute);
              EEPROM.update(26, winterWorkTime.cycleQuantity);
              EEPROM.update(27, winterWorkTime.cycleLenghtMinutes);
              EEPROM.update(28, winterWorkTime.breakLenghtMinutes);
              goToPrewiewScreen();
              break;
          }
        } else {
          currentSetSezonMode++;
          blinkState = false;
        }
      }
      break;

    case 1:
      if (wasButtonBumpped(LEFT)) {
        if (startHourToSet == 0) {
          startHourToSet = 24;
        }
        startHourToSet--;
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        startHourToSet++;
        if (startHourToSet == 24) {
          startHourToSet = 0;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        currentSetSezonMode++;
        blinkState = false;
      }
      break;

    case 2:
      if (wasButtonBumpped(LEFT)) {
        if (startMinuteToSet == 0) {
          startMinuteToSet = 60;
        }
        startMinuteToSet--;
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        startMinuteToSet++;
        if (startMinuteToSet == 60) {
          startMinuteToSet = 0;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        currentSetSezonMode++;
        blinkState = false;
      }
      break;

    case 3:
      if (wasButtonBumpped(LEFT)) {
        if (cycleLenghtHoursToSet != 0) {
          cycleLenghtHoursToSet--;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        if (cycleLenghtHoursToSet < 4) {
          cycleLenghtHoursToSet++;
          if ((cycleLenghtHoursToSet == 4) && (cycleLenghtMinutesToSet > 15)) {
            cycleLenghtMinutesToSet = 15;
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
      }

      if (wasButtonBumpped(ENTER)) {
        currentSetSezonMode++;
        blinkState = false;
      }
      break;

    case 4:
      if (wasButtonBumpped(LEFT)) {
        if (cycleLenghtHoursToSet == 4) {
          if (cycleLenghtMinutesToSet == 0) {
            cycleLenghtMinutesToSet = 16;
          }
          cycleLenghtMinutesToSet--;
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        } else {
          if (cycleLenghtMinutesToSet == 0) {
            cycleLenghtMinutesToSet = 60;
          }
          cycleLenghtMinutesToSet--;
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
      }

      if (wasButtonBumpped(RIGHT)) {
        if (cycleLenghtHoursToSet == 4) {
          cycleLenghtMinutesToSet++;
          if (cycleLenghtMinutesToSet == 16) {
            cycleLenghtMinutesToSet = 0;
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        } else {
          cycleLenghtMinutesToSet++;
          if (cycleLenghtMinutesToSet == 60) {
            cycleLenghtMinutesToSet = 0;
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
      }

      if (wasButtonBumpped(ENTER)) {
        currentSetSezonMode++;
        blinkState = false;
      }
      break;

    case 5:
      if (wasButtonBumpped(LEFT)) {
        if (breakLenghtHoursToSet != 0) {
          breakLenghtHoursToSet--;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        if (breakLenghtHoursToSet < 4) {
          breakLenghtHoursToSet++;
          if ((breakLenghtHoursToSet == 4) && (breakLenghtMinutesToSet > 15)) {
            breakLenghtMinutesToSet = 15;
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
      }

      if (wasButtonBumpped(ENTER)) {
        currentSetSezonMode++;
        blinkState = false;
      }
      break;

    case 6:
      if (wasButtonBumpped(LEFT)) {
        if (breakLenghtHoursToSet == 4) {
          if (breakLenghtMinutesToSet == 0) {
            breakLenghtMinutesToSet = 16;
          }
          breakLenghtMinutesToSet--;
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        } else {
          if (breakLenghtMinutesToSet == 0) {
            breakLenghtMinutesToSet = 60;
          }
          breakLenghtMinutesToSet--;
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
      }

      if (wasButtonBumpped(RIGHT)) {
        if (breakLenghtHoursToSet == 4) {
          breakLenghtMinutesToSet++;
          if (breakLenghtMinutesToSet == 16) {
            breakLenghtMinutesToSet = 0;
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        } else {
          breakLenghtMinutesToSet++;
          if (breakLenghtMinutesToSet == 60) {
            breakLenghtMinutesToSet = 0;
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
      }

      if (wasButtonBumpped(ENTER)) {

        long endHour = startHourToSet + (cycleLenghtHoursToSet * cycleQuantityToSet) + (breakLenghtHoursToSet * (cycleQuantityToSet - 1)) +
                       (((cycleLenghtMinutesToSet * cycleQuantityToSet) + (breakLenghtMinutesToSet * (cycleQuantityToSet - 1))) / 60);
        while ((endHour >= 24) && (cycleQuantityToSet > 0)) {
          cycleQuantityToSet--;
          endHour = startHourToSet + (cycleLenghtHoursToSet * cycleQuantityToSet) + (breakLenghtHoursToSet * (cycleQuantityToSet - 1)) +
                    (((cycleLenghtMinutesToSet * cycleQuantityToSet) + (breakLenghtMinutesToSet * (cycleQuantityToSet - 1))) / 60);
        }

        switch (currentSetSezon) {
          case 0:
            springWorkTime.startHour = startHourToSet;
            springWorkTime.startMinute = startMinuteToSet;
            springWorkTime.cycleQuantity = cycleQuantityToSet;
            springWorkTime.cycleLenghtMinutes = cycleLenghtHoursToSet * 60 + cycleLenghtMinutesToSet;
            springWorkTime.breakLenghtMinutes = breakLenghtHoursToSet * 60 + breakLenghtMinutesToSet;
            EEPROM.update(3, springWorkTime.startHour);
            EEPROM.update(4, springWorkTime.startMinute);
            EEPROM.update(5, springWorkTime.cycleQuantity);
            EEPROM.update(6, springWorkTime.cycleLenghtMinutes);
            EEPROM.update(7, springWorkTime.breakLenghtMinutes);
            startHourToSet = summerWorkTime.startHour;
            startMinuteToSet = summerWorkTime.startMinute;
            cycleQuantityToSet = summerWorkTime.cycleQuantity;
            cycleLenghtHoursToSet = summerWorkTime.cycleLenghtMinutes / 60;
            cycleLenghtMinutesToSet = summerWorkTime.cycleLenghtMinutes % 60;
            breakLenghtHoursToSet = summerWorkTime.breakLenghtMinutes / 60;
            breakLenghtMinutesToSet = summerWorkTime.breakLenghtMinutes % 60;
            currentSetSezon = 1;
            currentSetSezonMode = 0;
            break;

          case 1:
            summerWorkTime.startHour = startHourToSet;
            summerWorkTime.startMinute = startMinuteToSet;
            summerWorkTime.cycleQuantity = cycleQuantityToSet;
            summerWorkTime.cycleLenghtMinutes = cycleLenghtHoursToSet * 60 + cycleLenghtMinutesToSet;
            summerWorkTime.breakLenghtMinutes = breakLenghtHoursToSet * 60 + breakLenghtMinutesToSet;
            EEPROM.update(10, summerWorkTime.startHour);
            EEPROM.update(11, summerWorkTime.startMinute);
            EEPROM.update(12, summerWorkTime.cycleQuantity);
            EEPROM.update(13, summerWorkTime.cycleLenghtMinutes);
            EEPROM.update(14, summerWorkTime.breakLenghtMinutes);
            startHourToSet = autumnWorkTime.startHour;
            startMinuteToSet = autumnWorkTime.startMinute;
            cycleQuantityToSet = autumnWorkTime.cycleQuantity;
            cycleLenghtHoursToSet = autumnWorkTime.cycleLenghtMinutes / 60;
            cycleLenghtMinutesToSet = autumnWorkTime.cycleLenghtMinutes % 60;
            breakLenghtHoursToSet = autumnWorkTime.breakLenghtMinutes / 60;
            breakLenghtMinutesToSet = autumnWorkTime.breakLenghtMinutes % 60;
            currentSetSezon = 2;
            currentSetSezonMode = 0;
            break;

          case 2:
            autumnWorkTime.startHour = startHourToSet;
            autumnWorkTime.startMinute = startMinuteToSet;
            autumnWorkTime.cycleQuantity = cycleQuantityToSet;
            autumnWorkTime.cycleLenghtMinutes = cycleLenghtHoursToSet * 60 + cycleLenghtMinutesToSet;
            autumnWorkTime.breakLenghtMinutes = breakLenghtHoursToSet * 60 + breakLenghtMinutesToSet;
            EEPROM.update(17, autumnWorkTime.startHour);
            EEPROM.update(18, autumnWorkTime.startMinute);
            EEPROM.update(19, autumnWorkTime.cycleQuantity);
            EEPROM.update(20, autumnWorkTime.cycleLenghtMinutes);
            EEPROM.update(21, autumnWorkTime.breakLenghtMinutes);
            startHourToSet = winterWorkTime.startHour;
            startMinuteToSet = winterWorkTime.startMinute;
            cycleQuantityToSet = winterWorkTime.cycleQuantity;
            cycleLenghtHoursToSet = winterWorkTime.cycleLenghtMinutes / 60;
            cycleLenghtMinutesToSet = winterWorkTime.cycleLenghtMinutes % 60;
            breakLenghtHoursToSet = winterWorkTime.breakLenghtMinutes / 60;
            breakLenghtMinutesToSet = winterWorkTime.breakLenghtMinutes % 60;
            currentSetSezon = 3;
            currentSetSezonMode = 0;
            break;

          case 3:
            winterWorkTime.startHour = startHourToSet;
            winterWorkTime.startMinute = startMinuteToSet;
            winterWorkTime.cycleQuantity = cycleQuantityToSet;
            winterWorkTime.cycleLenghtMinutes = cycleLenghtHoursToSet * 60 + cycleLenghtMinutesToSet;
            winterWorkTime.breakLenghtMinutes = breakLenghtHoursToSet * 60 + breakLenghtMinutesToSet;
            EEPROM.update(24, winterWorkTime.startHour);
            EEPROM.update(25, winterWorkTime.startMinute);
            EEPROM.update(26, winterWorkTime.cycleQuantity);
            EEPROM.update(27, winterWorkTime.cycleLenghtMinutes);
            EEPROM.update(28, winterWorkTime.breakLenghtMinutes);
            goToPrewiewScreen();
            break;
        }
        break;
      }
  }

  if (wasButtonBumpped(ESCAPE) == true) {
    goToMenuScreen();
  }
}

void goToSetDayScreen() {
  //Starting set yday screen
  displayMode = 4;
  startHourToSet = autumnWorkTime.startHour;
  startMinuteToSet = springWorkTime.startMinute;
  cycleQuantityToSet = springWorkTime.cycleQuantity;
  cycleLenghtHoursToSet = springWorkTime.cycleLenghtMinutes / 60;
  cycleLenghtMinutesToSet = springWorkTime.cycleLenghtMinutes % 60;
  breakLenghtHoursToSet = springWorkTime.breakLenghtMinutes / 60;
  breakLenghtMinutesToSet = springWorkTime.breakLenghtMinutes % 60;
  currentSetSezon = 0;
  currentSetSezonMode = 0;
  previousMillisToBlinck = currentMillis;
  blinkState = false;
}
