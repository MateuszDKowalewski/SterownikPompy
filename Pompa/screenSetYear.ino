void setYearScreen() {
  lcd.setCursor(0, 0);
  lcd.print("SET YEAR        ");
  lcd.setCursor(0, 1);
  lcd.print("                ");

  
  if (wasButtonPressed(MENU) == true) {
    mode = 1;
  }
}

