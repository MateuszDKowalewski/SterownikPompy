void homeScreen() {
  //Opreate home screen
  //Must be run to display it

  //Display current date and time
  lcd.setCursor(0, 0);
  if (tm.Day < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Day);
  lcd.print('/');
  if (tm.Month < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Month);
  lcd.print('/');
  lcd.print(tmYearToCalendar(tm.Year));
  lcd.print(' ');
  if (tm.Hour < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Hour);
  lcd.print(':');
  if (tm.Minute < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Minute);

  lcd.setCursor(0, 1);
  printCurrentSezon();
  lcd.print(" ");
  if(runPump()){
    lcd.print("ON ");
  }else{
    lcd.print("OFF");
  }
  lcd.print("      ");

  if (howRainyIs() < 999) {
    lcd.print(' ');
  }
  if (howRainyIs < 99) {
    lcd.print(' ');
  }
  if (howRainyIs < 9) {
    lcd.print(' ');
  }
  lcd.print(howRainyIs());

  //Operate buttons
  if (wasButtonBumpped(ENTER) == true) {
    //Change display mode to menu screen
    goToMenuScreen();
  }
}

void goToHomeScreen() {
  //Starting home screen
  displayMode = 0;
}
