void menuScreen() {
  lcd.setCursor(0, 0);
  lcd.print("      MENU      ");
  lcd.setCursor(0, 1);
  lcd.print("1-Pod 2-Dz 3-Rok");

  
  if (wasButtonPressed(MENU) == true) {
    mode = 0;
  }

  if (wasButtonPressed(OPTION_1) == true) {
    mode = 2;
  }
  if (wasButtonPressed(OPTION_2) == true) {
    mode = 3;
  }
  if (wasButtonPressed(OPTION_3) == true) {
    mode = 4;
  }
}

