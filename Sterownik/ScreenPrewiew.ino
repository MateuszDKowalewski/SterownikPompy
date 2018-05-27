//Contain number of sezon to display
//0 - spring
//1 - summer
//2 - autumn
//3 - winter
byte sezonMode;

//Contain number of pump cycle to display
byte prewiewMode;

//Contain time to display
byte displayHour;
int displayMinute;

byte dayToDisplay;
byte monthToDisplay;

void prewiewScreen() {
  //Opreate prewiew screen
  //Must be run to display it

  lcd.setCursor(0, 0);
  //Display sezon and its range
  //PAMIĘTAJ BY ZAKRES WYZNACZAĆ AUTOMATYCZNIE
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  switch (sezonMode) {
    case 0:
      lcd.print("WI   ");
      dayToDisplay = spring.Day;
      monthToDisplay = spring.Month;
      if (dayToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(dayToDisplay);
      lcd.print('.');
      if (monthToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(monthToDisplay);
      lcd.print('-');
      dayToDisplay = summer.Day;
      monthToDisplay = summer.Month;
      if ((monthToDisplay == 1) && (dayToDisplay == 1)) {
        dayToDisplay = 31;
        monthToDisplay = 12;
      } else if (dayToDisplay == 1) {
        monthToDisplay--;
        if ((monthToDisplay == 1) || (monthToDisplay == 3) || (monthToDisplay == 5) || (monthToDisplay == 7) || (monthToDisplay == 8) || (monthToDisplay == 10) || (monthToDisplay == 12)) {
          dayToDisplay = 31;
        } else if ((monthToDisplay == 4) || (monthToDisplay == 6) || (monthToDisplay == 9) || (monthToDisplay == 11)) {
          dayToDisplay = 30;
        } else {
          dayToDisplay = 28;
        }
      } else {
        dayToDisplay--;
      }
      if (dayToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(dayToDisplay);
      lcd.print('.');
      if (monthToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(monthToDisplay);
      break;

    case 1:
      lcd.print("LA   ");
      dayToDisplay = summer.Day;
      monthToDisplay = summer.Month;
      if (dayToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(dayToDisplay);
      lcd.print('.');
      if (monthToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(monthToDisplay);
      lcd.print('-');
      dayToDisplay = autumn.Day;
      monthToDisplay = autumn.Month;
      if ((monthToDisplay == 1) && (dayToDisplay == 1)) {
        dayToDisplay = 31;
        monthToDisplay = 12;
      } else if (dayToDisplay == 1) {
        monthToDisplay--;
        if ((monthToDisplay == 1) || (monthToDisplay == 3) || (monthToDisplay == 5) || (monthToDisplay == 7) || (monthToDisplay == 8) || (monthToDisplay == 10) || (monthToDisplay == 12)) {
          dayToDisplay = 31;
        } else if ((monthToDisplay == 4) || (monthToDisplay == 6) || (monthToDisplay == 9) || (monthToDisplay == 11)) {
          dayToDisplay = 30;
        } else {
          dayToDisplay = 28;
        }
      } else {
        dayToDisplay--;
      }
      if (dayToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(dayToDisplay);
      lcd.print('.');
      if (monthToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(monthToDisplay);
      break;

    case 2:
      lcd.print("JE   ");
      dayToDisplay = autumn.Day;
      monthToDisplay = autumn.Month;
      if (dayToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(dayToDisplay);
      lcd.print('.');
      if (monthToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(monthToDisplay);
      lcd.print('-');
      dayToDisplay = winter.Day;
      monthToDisplay = winter.Month;
      if ((monthToDisplay == 1) && (dayToDisplay == 1)) {
        dayToDisplay = 31;
        monthToDisplay = 12;
      } else if (dayToDisplay == 1) {
        monthToDisplay--;
        if ((monthToDisplay == 1) || (monthToDisplay == 3) || (monthToDisplay == 5) || (monthToDisplay == 7) || (monthToDisplay == 8) || (monthToDisplay == 10) || (monthToDisplay == 12)) {
          dayToDisplay = 31;
        } else if ((monthToDisplay == 4) || (monthToDisplay == 6) || (monthToDisplay == 9) || (monthToDisplay == 11)) {
          dayToDisplay = 30;
        } else {
          dayToDisplay = 28;
        }
      } else {
        dayToDisplay--;
      }
      if (dayToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(dayToDisplay);
      lcd.print('.');
      if (monthToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(monthToDisplay);
      break;

    case 3:
      lcd.print("ZI   ");
      dayToDisplay = winter.Day;
      monthToDisplay = winter.Month;
      if (dayToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(dayToDisplay);
      lcd.print('.');
      if (monthToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(monthToDisplay);
      lcd.print('-');
      dayToDisplay = spring.Day;
      monthToDisplay = spring.Month;
      if ((monthToDisplay == 1) && (dayToDisplay == 1)) {
        dayToDisplay = 31;
        monthToDisplay = 12;
      } else if (dayToDisplay == 1) {
        monthToDisplay--;
        if ((monthToDisplay == 1) || (monthToDisplay == 3) || (monthToDisplay == 5) || (monthToDisplay == 7) || (monthToDisplay == 8) || (monthToDisplay == 10) || (monthToDisplay == 12)) {
          dayToDisplay = 31;
        } else if ((monthToDisplay == 4) || (monthToDisplay == 6) || (monthToDisplay == 9) || (monthToDisplay == 11)) {
          dayToDisplay = 30;
        } else {
          dayToDisplay = 28;
        }
      } else {
        dayToDisplay--;
      }
      if (dayToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(dayToDisplay);
      lcd.print('.');
      if (monthToDisplay < 10) {
        lcd.print(0);
      }
      lcd.print(monthToDisplay);
      break;
  }

  //Check how many pump cecle are in current sezon
  if (getCycleQuantity(sezonMode) != 0) {
    //Display sezon's ordinal number
    lcd.setCursor(0, 1);
    lcd.print(prewiewMode + 1);
    lcd.print(". ");
    if (prewiewMode < 9) {
      lcd.print(' ');
    }
    if (prewiewMode < 99) {
      lcd.print(' ');
    }

    //Get hour when pump starts working in zurrent sezon
    displayHour = getStartHour(sezonMode);
    displayMinute = getStartMinute(sezonMode);

    //Ad some time to show current cycle start hour
    displayMinute += prewiewMode * (getCycleLenghtMinutes(sezonMode) + getBreakLenghtMinutes(sezonMode));
    displayHour += displayMinute / 60;
    displayMinute = displayMinute % 60;

    //Display start hour
    lcd.setCursor(5, 1);
    if (displayHour < 10) {
      lcd.print(0);
    }
    lcd.print(displayHour);
    lcd.print(':');
    if (displayMinute < 10) {
      lcd.print(0);
    }
    lcd.print(displayMinute);

    //Add some time to show current cycle end hour
    displayMinute += getCycleLenghtMinutes(sezonMode);
    displayHour += displayMinute / 60;
    displayMinute = displayMinute % 60;

    lcd.print("-");

    //Display end hour
    if (displayHour < 10) {
      lcd.print(0);
    }
    lcd.print(displayHour);
    lcd.print(':');
    if (displayMinute < 10) {
      lcd.print(0);
    }
    lcd.print(displayMinute);
  } else {
    //If there is no cycle in current sezon display message
    lcd.setCursor(0, 1);
    lcd.print("Pompa wylaczona ");
  }

  //Operate buttons

  if (wasButtonBumpped(ESCAPE) == true) {
    //Change dispaly mode to menu screen
    displayMode = 1;
  }

  if (wasButtonBumpped(ENTER) == true) {
    //Change seazon to display
    prewiewMode = 0;
    sezonMode++;
    if (sezonMode == 4) {
      sezonMode = 0;
    }
  }

  if (wasButtonBumpped(RIGHT) == true) {
    //Change cycle to display
    prewiewMode++;
    if (prewiewMode == getCycleQuantity(sezonMode)) {
      prewiewMode = 0;
    }
  }

  if (wasButtonBumpped(LEFT) == true) {
    //Change cycle to display
    if (prewiewMode == 0) {
      prewiewMode = getCycleQuantity(sezonMode);
    }
    prewiewMode--;
  }
}

void goToPrewiewScreen() {
  //Starting prewiew screen
  sezonMode = 0;
  prewiewMode = 0;
  displayMode = 2;
}
