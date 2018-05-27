byte sezonMode;
byte displayMode;

byte displayHour;
int displayMinute;

void prewiewScreen() {
  lcd.setCursor(0, 0);
  switch (sezonMode) {
    case 0:
      lcd.print("WI   21.03-20.06");
      break;

    case 1:
      lcd.print("LA   21.06-23.09");
      break;

    case 2:
      lcd.print("JE   24.09-20.12");
      break;

    case 3:
      lcd.print("ZI   21.12-20.03");
      break;
  }

  if (getCycleQuantity(sezonMode) != 0) {
    lcd.setCursor(0, 1);
    lcd.print(displayMode + 1);
    lcd.print(". ");
    if(displayMode < 9){
      lcd.print(' ');
    }
    if(displayMode < 99){
      lcd.print(' ');
    }

    displayHour = getStartHour(sezonMode);
    displayMinute = getStartMinute(sezonMode);

    displayMinute += displayMode * (getCycleLenghtMinutes(sezonMode) + getBreakLenghtMinutes(sezonMode));
    displayHour += displayMinute / 60;
    displayMinute = displayMinute % 60;

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

    displayMinute += getCycleLenghtMinutes(sezonMode);
    displayHour += displayMinute / 60;
    displayMinute = displayMinute % 60;

    lcd.print("-");

    if (displayHour < 10) {
      lcd.print(0);
    }
    lcd.print(displayHour);
    lcd.print(':');
    if (displayMinute < 10) {
      lcd.print(0);
    }
    lcd.print(displayMinute);
  }else{
    lcd.setCursor(0, 1);
    lcd.print("Pompa wylaczona ");
  }

  if (wasButtonPressed(MENU) == true) {
    sezonMode = 0;
    displayMode = 0;
    mode = 1;
  }

  if (wasButtonPressed(RIGHT) == true) {
    displayMode = 0;
    sezonMode++;
    if (sezonMode == 4) {
      sezonMode = 0;
    }
  }

  if (wasButtonPressed(LEFT) == true) {
    displayMode = 0;
    if (sezonMode == 0) {
      sezonMode = 4;
    }
    sezonMode--;
  }

  if (wasButtonPressed(PLUS) == true) {
    displayMode++;
    if (displayMode == getCycleQuantity(sezonMode)) {
      displayMode = 0;
    }
  }

  if (wasButtonPressed(MINUS) == true) {
    if (displayMode == 0) {
      displayMode = getCycleQuantity(sezonMode);
    }
    displayMode--;
  }
}

void setupPrewiewScreen() {
  sezonMode = 0;
  displayMode = 0;
}

