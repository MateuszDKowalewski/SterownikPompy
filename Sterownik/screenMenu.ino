//Contain number of current selected option
byte option;

void menuScreen() {
  //Opreate menu screen
  //Must be run to display it

  //Display first line
  lcd.setCursor(0, 0);
  lcd.print("      MENU      ");
  lcd.setCursor(0, 1);

  //Display current option
  switch (option) {
    case 0:
      lcd.print("PODGLAD         ");
      break;

    case 1:
      lcd.print("CYKL ROCZNY     ");
      break;

    case 2:
      lcd.print("CYKL DZIENNY    ");
      break;

    case 3:
      lcd.print("USTAWIENIA CZASU");
      break;
  }

  //Operate buttons

  if (wasButtonBumpped(LEFT)) {
    //Change current option
    option--;
    if (option == 255) {
      option = 3;
    }
  }

  if (wasButtonBumpped(RIGHT)) {
    //Change current option
    option++;
    if (option == 4) {
      option = 0;
    }
  }

  if (wasButtonBumpped(ESCAPE)) {
    //Change display mode to home screen
    goToHomeScreen();
  }

  if (wasButtonBumpped(ENTER)) {
    //Check option and change display mode to...
    switch (option) {
      case 0:
        //..prewiew screen
        goToPrewiewScreen();
        break;

      case 1:
        //...set year cycle screen
        goToSetYearScreen();
        break;

      case 2:
        //...set day cycle screen
        goToSetDayScreen();
        break;

      case 3:
        //..set time screen
        goToSetTimeScreen();
        break;
    }
  }
}

void goToMenuScreen() {
  //Starting menu screen
  displayMode = 1;
  option = 0;
}
