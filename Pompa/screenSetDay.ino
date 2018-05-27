void setDayScreen() {
  lcd.setCursor(0, 0);
  lcd.print("SET DAY         ");
  lcd.setCursor(0, 1);
  lcd.print("                ");

  
  if (wasButtonPressed(MENU) == true) {
    mode = 1;
  }
}

