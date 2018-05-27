void RTCError(){
  if(RTC.chipPresent()) {
      lcd.setCursor(0, 0);
      lcd.print("RTC is stopped");
      lcd.setCursor(0, 1);
      lcd.print("Run the SetTime");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("RTC read error");
      lcd.setCursor(0, 1);
      lcd.print("Check the circuitry");
    }  
}

