void homeScreen() {
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
  if (runPump()) {
    lcd.print("ON              ");
  } else {
    lcd.print("OFF             ");
  }

  if (howRainyIs() > 999) {
    lcd.setCursor(12, 1);
  } else if (howRainyIs > 99) {
    lcd.setCursor(13, 1);
  } else if (howRainyIs > 9) {
    lcd.setCursor(14, 1);
  } else {
    lcd.setCursor(15, 1);
  }

  lcd.print(howRainyIs());

  if (wasButtonPressed(MENU) == true) {
    mode = 1;
  }
}

