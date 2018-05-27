byte changeSezonMode;

byte sezonDayToSet;
byte sezonMonthToSet;

tmElements_t springToSet;
tmElements_t summerToSet;
tmElements_t autumnToSet;
tmElements_t winterToSet;

void setYearScreen() {
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
  lcd.print("PIERWSZY DZIEN  ");
  lcd.setCursor(0, 1);

  switch (changeSezonMode) {
    case 0:
      lcd.print("WIOSNY:    ");
      if (blinkState) {
        if (sezonDayToSet < 10) {
          lcd.print(0);
        }
        lcd.print(sezonDayToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print('/');
      if (sezonMonthToSet < 10) {
        lcd.print(0);
      }
      lcd.print(sezonMonthToSet);
      break;

    case 1:
      lcd.print("WIOSNY:    ");
      if (sezonDayToSet < 10) {
        lcd.print(0);
      }
      lcd.print(sezonDayToSet);
      lcd.print('/');
      if (blinkState) {
        if (sezonMonthToSet < 10) {
          lcd.print(0);
        }
        lcd.print(sezonMonthToSet);
      } else {
        lcd.print("  ");
      }
      break;

    case 2:
      lcd.print("LATA:      ");
      if (blinkState) {
        if (sezonDayToSet < 10) {
          lcd.print(0);
        }
        lcd.print(sezonDayToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print('/');
      if (sezonMonthToSet < 10) {
        lcd.print(0);
      }
      lcd.print(sezonMonthToSet);
      break;

    case 3:
      lcd.print("LATA:      ");
      if (sezonDayToSet < 10) {
        lcd.print(0);
      }
      lcd.print(sezonDayToSet);
      lcd.print('/');
      if (blinkState) {
        if (sezonMonthToSet < 10) {
          lcd.print(0);
        }
        lcd.print(sezonMonthToSet);
      } else {
        lcd.print("  ");
      }
      break;

    case 4:
      lcd.print("JESIENI:   ");
      if (blinkState) {
        if (sezonDayToSet < 10) {
          lcd.print(0);
        }
        lcd.print(sezonDayToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print('/');
      if (sezonMonthToSet < 10) {
        lcd.print(0);
      }
      lcd.print(sezonMonthToSet);
      break;

    case 5:
      lcd.print("JESIENI:   ");
      if (sezonDayToSet < 10) {
        lcd.print(0);
      }
      lcd.print(sezonDayToSet);
      lcd.print('/');
      if (blinkState) {
        if (sezonMonthToSet < 10) {
          lcd.print(0);
        }
        lcd.print(sezonMonthToSet);
      } else {
        lcd.print("  ");
      }
      break;

    case 6:
      lcd.print("ZIMY:      ");
      if (blinkState) {
        if (sezonDayToSet < 10) {
          lcd.print(0);
        }
        lcd.print(sezonDayToSet);
      } else {
        lcd.print("  ");
      }
      lcd.print('/');
      if (sezonMonthToSet < 10) {
        lcd.print(0);
      }
      lcd.print(sezonMonthToSet);
      break;

    case 7:
      lcd.print("ZIMY:      ");
      if (sezonDayToSet < 10) {
        lcd.print(0);
      }
      lcd.print(sezonDayToSet);
      lcd.print('/');
      if (blinkState) {
        if (sezonMonthToSet < 10) {
          lcd.print(0);
        }
        lcd.print(sezonMonthToSet);
      } else {
        lcd.print("  ");
      }
      break;
  }

  switch (changeSezonMode) {
    case 0:
      if (wasButtonBumpped(LEFT)) {
        sezonDayToSet--;
        if (sezonDayToSet == 0) {
          sezonDayToSet = 31;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        sezonDayToSet++;
        if (sezonDayToSet == 32) {
          sezonDayToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        changeSezonMode++;
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }
      break;

    case 1:
      if (wasButtonBumpped(LEFT)) {
        sezonMonthToSet--;
        if (sezonMonthToSet == 0) {
          sezonMonthToSet = 12;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        sezonMonthToSet++;
        if (sezonMonthToSet == 13) {
          sezonMonthToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        if ((sezonMonthToSet == 1) || (sezonMonthToSet == 3) || (sezonMonthToSet == 5) || (sezonMonthToSet == 7) || (sezonMonthToSet == 8) || (sezonMonthToSet == 10) || (sezonMonthToSet == 12)) {
          springToSet.Month = sezonMonthToSet;
          springToSet.Day = sezonDayToSet;
          sezonMonthToSet = EEPROM.read(8);
          sezonDayToSet = EEPROM.read(9);
          changeSezonMode++;
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        } else if ((sezonMonthToSet == 4) || (sezonMonthToSet == 6) || (sezonMonthToSet == 9) || (sezonMonthToSet == 11)) {
          if (sezonDayToSet < 31) {
            springToSet.Month = sezonMonthToSet;
            springToSet.Day = sezonDayToSet;
            sezonMonthToSet = EEPROM.read(8);
            sezonDayToSet = EEPROM.read(9);
            changeSezonMode++;
            blinkState = true;
            previousMillisToBlinck = currentMillis;
          }
        } else if (sezonDayToSet < 29) {
          springToSet.Month = sezonMonthToSet;
          springToSet.Day = sezonDayToSet;
          sezonMonthToSet = EEPROM.read(8);
          sezonDayToSet = EEPROM.read(9);
          changeSezonMode++;
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }
      break;

    case 2:
      if (wasButtonBumpped(LEFT)) {
        sezonDayToSet--;
        if (sezonDayToSet == 0) {
          sezonDayToSet = 31;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        sezonDayToSet++;
        if (sezonDayToSet == 32) {
          sezonDayToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        changeSezonMode++;
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }
      break;

    case 3:
      if (wasButtonBumpped(LEFT)) {
        sezonMonthToSet--;
        if (sezonMonthToSet == 0) {
          sezonMonthToSet = 12;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        sezonMonthToSet++;
        if (sezonMonthToSet == 13) {
          sezonMonthToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        if ((sezonMonthToSet == 1) || (sezonMonthToSet == 3) || (sezonMonthToSet == 5) || (sezonMonthToSet == 7) || (sezonMonthToSet == 8) || (sezonMonthToSet == 10) || (sezonMonthToSet == 12)) {
          summerToSet.Month = sezonMonthToSet;
          summerToSet.Day = sezonDayToSet;
          if (aFasterThanB(springToSet, summerToSet)) {
            changeSezonMode++;
            sezonMonthToSet = EEPROM.read(15);
            sezonDayToSet = EEPROM.read(16);
          } else {
            changeSezonMode -= 3;
            sezonMonthToSet = EEPROM.read(1);
            sezonDayToSet = EEPROM.read(2);
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        } else if ((sezonMonthToSet == 4) || (sezonMonthToSet == 6) || (sezonMonthToSet == 9) || (sezonMonthToSet == 11)) {
          if (sezonDayToSet < 31) {
            summerToSet.Month = sezonMonthToSet;
            summerToSet.Day = sezonDayToSet;
            if (aFasterThanB(springToSet, summerToSet)) {
              changeSezonMode++;
              sezonMonthToSet = EEPROM.read(15);
              sezonDayToSet = EEPROM.read(16);
            } else {
              changeSezonMode -= 3;
              sezonMonthToSet = EEPROM.read(1);
              sezonDayToSet = EEPROM.read(2);
            }
            blinkState = true;
            previousMillisToBlinck = currentMillis;
          }
        } else if (sezonDayToSet < 29) {
          summerToSet.Month = sezonMonthToSet;
          summerToSet.Day = sezonDayToSet;
          if (aFasterThanB(springToSet, summerToSet)) {
            changeSezonMode++;
            sezonMonthToSet = EEPROM.read(15);
            sezonDayToSet = EEPROM.read(16);
          } else {
            changeSezonMode -= 3;
            sezonMonthToSet = EEPROM.read(1);
            sezonDayToSet = EEPROM.read(2);
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
      }
      break;

    case 4:
      if (wasButtonBumpped(LEFT)) {
        sezonDayToSet--;
        if (sezonDayToSet == 0) {
          sezonDayToSet = 31;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        sezonDayToSet++;
        if (sezonDayToSet == 32) {
          sezonDayToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        changeSezonMode++;
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }
      break;

    case 5:
      if (wasButtonBumpped(LEFT)) {
        sezonMonthToSet--;
        if (sezonMonthToSet == 0) {
          sezonMonthToSet = 12;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        sezonMonthToSet++;
        if (sezonMonthToSet == 13) {
          sezonMonthToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        if ((sezonMonthToSet == 1) || (sezonMonthToSet == 3) || (sezonMonthToSet == 5) || (sezonMonthToSet == 7) || (sezonMonthToSet == 8) || (sezonMonthToSet == 10) || (sezonMonthToSet == 12)) {
          autumnToSet.Month = sezonMonthToSet;
          autumnToSet.Day = sezonDayToSet;
          if (aFasterThanB(summerToSet, autumnToSet)) {
            changeSezonMode++;
            sezonMonthToSet = EEPROM.read(22);
            sezonDayToSet = EEPROM.read(23);
          } else {
            changeSezonMode -= 3;
            sezonMonthToSet = EEPROM.read(8);
            sezonDayToSet = EEPROM.read(9);
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        } else if ((sezonMonthToSet == 4) || (sezonMonthToSet == 6) || (sezonMonthToSet == 9) || (sezonMonthToSet == 11)) {
          if (sezonDayToSet < 31) {
            autumnToSet.Month = sezonMonthToSet;
            autumnToSet.Day = sezonDayToSet;
            if (aFasterThanB(summerToSet, autumnToSet)) {
              changeSezonMode++;
              sezonMonthToSet = EEPROM.read(22);
              sezonDayToSet = EEPROM.read(23);
            } else {
              changeSezonMode -= 3;
              sezonMonthToSet = EEPROM.read(8);
              sezonDayToSet = EEPROM.read(9);
            }
            blinkState = true;
            previousMillisToBlinck = currentMillis;
          }
        } else if (sezonDayToSet < 29) {
          autumnToSet.Month = sezonMonthToSet;
          autumnToSet.Day = sezonDayToSet;
          if (aFasterThanB(summerToSet, autumnToSet)) {
            changeSezonMode++;
            sezonMonthToSet = EEPROM.read(22);
            sezonDayToSet = EEPROM.read(23);
          } else {
            changeSezonMode -= 3;
            sezonMonthToSet = EEPROM.read(8);
            sezonDayToSet = EEPROM.read(9);
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        }
      }
      break;

    case 6:
      if (wasButtonBumpped(LEFT)) {
        sezonDayToSet--;
        if (sezonDayToSet == 0) {
          sezonDayToSet = 31;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        sezonDayToSet++;
        if (sezonDayToSet == 32) {
          sezonDayToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        changeSezonMode++;
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }
      break;

    case 7:
      if (wasButtonBumpped(LEFT)) {
        sezonMonthToSet--;
        if (sezonMonthToSet == 0) {
          sezonMonthToSet = 12;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(RIGHT)) {
        sezonMonthToSet++;
        if (sezonMonthToSet == 13) {
          sezonMonthToSet = 1;
        }
        blinkState = true;
        previousMillisToBlinck = currentMillis;
      }

      if (wasButtonBumpped(ENTER)) {
        if ((sezonMonthToSet == 1) || (sezonMonthToSet == 3) || (sezonMonthToSet == 5) || (sezonMonthToSet == 7) || (sezonMonthToSet == 8) || (sezonMonthToSet == 10) || (sezonMonthToSet == 12)) {
          if (aFasterThanB(summerToSet, autumnToSet)) {
            winterToSet.Month = sezonMonthToSet;
            winterToSet.Day = sezonDayToSet;
            spring = springToSet;
            summer = summerToSet;
            autumn = autumnToSet;
            winter = winterToSet;
            EEPROM.write(1, spring.Month);
            EEPROM.write(2, spring.Day);
            EEPROM.write(8, summer.Month);
            EEPROM.write(9, summer.Day);
            EEPROM.write(15, autumn.Month);
            EEPROM.write(16, autumn.Day);
            EEPROM.write(22, winter.Month);
            EEPROM.write(23, winter.Day);
            goToPrewiewScreen();
          } else {
            changeSezonMode -= 3;
            sezonMonthToSet = EEPROM.read(15);
            sezonDayToSet = EEPROM.read(16);
          }
          blinkState = true;
          previousMillisToBlinck = currentMillis;
        } else if ((sezonMonthToSet == 4) || (sezonMonthToSet == 6) || (sezonMonthToSet == 9) || (sezonMonthToSet == 11)) {
          if (sezonDayToSet < 31) {
            winterToSet.Month = sezonMonthToSet;
            winterToSet.Day = sezonDayToSet;
            goToPrewiewScreen();
          }
        } else if (sezonDayToSet < 29) {
          winterToSet.Month = sezonMonthToSet;
          winterToSet.Day = sezonDayToSet;
          goToPrewiewScreen();
        }
      }
      break;
  }

  if (wasButtonBumpped(ESCAPE) == true) {
    goToMenuScreen();
  }
}

void goToSetYearScreen() {
  //Starting set year screen
  displayMode = 3;
  blinkState = false;
  changeSezonMode = 0;
  sezonDayToSet = spring.Day;
  sezonMonthToSet = spring.Month;
  previousMillisToBlinck = currentMillis;
}
