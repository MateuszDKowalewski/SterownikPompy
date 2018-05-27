byte startHour;
byte startMinute;
byte endHour;
byte endMinute;

bool czas;

void setSezonsData() {
  springWorkTime.startHour = EEPROM.read(3);
  springWorkTime.startMinute = EEPROM.read(4);
  springWorkTime.cycleQuantity = EEPROM.read(5);
  springWorkTime.cycleLenghtMinutes = EEPROM.read(6);
  springWorkTime.breakLenghtMinutes = EEPROM.read(7);

  summerWorkTime.startHour = EEPROM.read(10);
  summerWorkTime.startMinute = EEPROM.read(11);
  summerWorkTime.cycleQuantity = EEPROM.read(12);
  summerWorkTime.cycleLenghtMinutes = EEPROM.read(13);
  summerWorkTime.breakLenghtMinutes = EEPROM.read(14);

  autumnWorkTime.startHour = EEPROM.read(17);
  autumnWorkTime.startMinute = EEPROM.read(18);
  autumnWorkTime.cycleQuantity = EEPROM.read(19);
  autumnWorkTime.cycleLenghtMinutes = EEPROM.read(20);
  autumnWorkTime.breakLenghtMinutes = EEPROM.read(21);

  winterWorkTime.startHour = EEPROM.read(24);
  winterWorkTime.startMinute = EEPROM.read(25);
  winterWorkTime.cycleQuantity = EEPROM.read(26);
  winterWorkTime.cycleLenghtMinutes = EEPROM.read(27);
  winterWorkTime.breakLenghtMinutes = EEPROM.read(28);
}

bool isGoodTime() {
  switch (currentSezon()) {
    case 0:
      return isGoodTimeSpring();
      break;

    case 1:
      return isGoodTimeSummer();
      break;

    case 2:
      return isGoodTimeAutumn();
      break;

    case 3:
      return isGoodTimeWinter();
      break;
  }
}

void printCurrentSezon(){
  switch(currentSezon()){
    case 0:
    lcd.print("WI");
    break;

    case 1:
    lcd.print("LA");
    break;

    case 2:
    lcd.print("JE");
    break;

    case 3:
    lcd.print("ZI");
    break;
  }
}

byte currentSezon() {
    if (aFasterThanB(tm, spring)) {
      return 3;
    }

    if (aFasterThanB(tm, summer)) {
      return 0;
    }

    if (aFasterThanB(tm, autumn)) {
      return 1;
    }

    if (aFasterThanB(tm, winter)) {
      return 2;
    }

    return 3;
}

bool isGoodTimeSpring() {
  startHour = springWorkTime.startHour;
  startMinute = springWorkTime.startMinute;
  endHour = springWorkTime.startHour;
  endMinute = springWorkTime.startMinute + springWorkTime.cycleLenghtMinutes;

  endHour += endMinute / 60;
  endMinute = endMinute % 60;

  czas = false;
  for (int i = 0; i < springWorkTime.cycleQuantity; i++) {
    if ((((tm.Hour == startHour) && (tm.Minute >= startMinute)) || (tm.Hour > startHour)) && (((tm.Hour == endHour) && (tm.Minute < endMinute)) || tm.Hour < endHour)) {
      czas = true;
    }
    startMinute += springWorkTime.cycleLenghtMinutes + springWorkTime.breakLenghtMinutes;
    startHour += startMinute / 60;
    startMinute = startMinute % 60;

    endMinute += springWorkTime.cycleLenghtMinutes + springWorkTime.breakLenghtMinutes;
    endHour += endMinute / 60;
    endMinute = endMinute % 60;
  }

  return czas;
}

bool isGoodTimeSummer() {
  startHour = summerWorkTime.startHour;
  startMinute = summerWorkTime.startMinute;
  endHour = summerWorkTime.startHour;
  endMinute = summerWorkTime.startMinute + summerWorkTime.cycleLenghtMinutes;

  endHour += endMinute / 60;
  endMinute = endMinute % 60;

  czas = false;
  for (int i = 0; i < summerWorkTime.cycleQuantity; i++) {
    if ((((tm.Hour == startHour) && (tm.Minute >= startMinute)) || (tm.Hour > startHour)) && (((tm.Hour == endHour) && (tm.Minute < endMinute)) || tm.Hour < endHour)) {
      czas = true;
    }
    startMinute += summerWorkTime.cycleLenghtMinutes + summerWorkTime.breakLenghtMinutes;
    startHour += startMinute / 60;
    startMinute = startMinute % 60;

    endMinute += summerWorkTime.cycleLenghtMinutes + summerWorkTime.breakLenghtMinutes;
    endHour += endMinute / 60;
    endMinute = endMinute % 60;
  }

  return czas;
}

bool isGoodTimeAutumn() {
  startHour = autumnWorkTime.startHour;
  startMinute = autumnWorkTime.startMinute;
  endHour = autumnWorkTime.startHour;
  endMinute = autumnWorkTime.startMinute + autumnWorkTime.cycleLenghtMinutes;

  endHour += endMinute / 60;
  endMinute = endMinute % 60;

  czas = false;
  for (int i = 0; i < autumnWorkTime.cycleQuantity; i++) {
    if ((((tm.Hour == startHour) && (tm.Minute >= startMinute)) || (tm.Hour > startHour)) && (((tm.Hour == endHour) && (tm.Minute < endMinute)) || tm.Hour < endHour)) {
      czas = true;
    }
    startMinute += autumnWorkTime.cycleLenghtMinutes + autumnWorkTime.breakLenghtMinutes;
    startHour += startMinute / 60;
    startMinute = startMinute % 60;

    endMinute += autumnWorkTime.cycleLenghtMinutes + autumnWorkTime.breakLenghtMinutes;
    endHour += endMinute / 60;
    endMinute = endMinute % 60;
  }

  return czas;
}

bool isGoodTimeWinter() {
  startHour = winterWorkTime.startHour;
  startMinute = winterWorkTime.startMinute;
  endHour = winterWorkTime.startHour;
  endMinute = winterWorkTime.startMinute + winterWorkTime.cycleLenghtMinutes;

  endHour += endMinute / 60;
  endMinute = endMinute % 60;

  czas = false;
  for (int i = 0; i < winterWorkTime.cycleQuantity; i++) {
    if ((((tm.Hour == startHour) && (tm.Minute >= startMinute)) || (tm.Hour > startHour)) && (((tm.Hour == endHour) && (tm.Minute < endMinute)) || tm.Hour < endHour)) {
      czas = true;
    }
    startMinute += winterWorkTime.cycleLenghtMinutes + winterWorkTime.breakLenghtMinutes;
    startHour += startMinute / 60;
    startMinute = startMinute % 60;

    endMinute += winterWorkTime.cycleLenghtMinutes + winterWorkTime.breakLenghtMinutes;
    endHour += endMinute / 60;
    endMinute = endMinute % 60;
  }

  return czas;
}

int getStartHour(byte w) {
  switch (w) {
    case 0:
      return springWorkTime.startHour;
      break;

    case 1:
      return summerWorkTime.startHour;
      break;

    case 2:
      return autumnWorkTime.startHour;
      break;

    case 3:
      return winterWorkTime.startHour;
      break;
  }
}

int getStartMinute(byte w) {
  switch (w) {
    case 0:
      return springWorkTime.startMinute;
      break;

    case 1:
      return summerWorkTime.startMinute;
      break;

    case 2:
      return autumnWorkTime.startMinute;
      break;

    case 3:
      return winterWorkTime.startMinute;
      break;
  }
}

int getCycleQuantity(byte w) {
  switch (w) {
    case 0:
      return springWorkTime.cycleQuantity;
      break;

    case 1:
      return summerWorkTime.cycleQuantity;
      break;

    case 2:
      return autumnWorkTime.cycleQuantity;
      break;

    case 3:
      return winterWorkTime.cycleQuantity;
      break;
  }
}

int getCycleLenghtMinutes(byte w) {
  switch (w) {
    case 0:
      return springWorkTime.cycleLenghtMinutes;
      break;

    case 1:
      return summerWorkTime.cycleLenghtMinutes;
      break;

    case 2:
      return autumnWorkTime.cycleLenghtMinutes;
      break;

    case 3:
      return winterWorkTime.cycleLenghtMinutes;
      break;
  }
}

int getBreakLenghtMinutes(byte w) {
  switch (w) {
    case 0:
      return springWorkTime.breakLenghtMinutes;
      break;

    case 1:
      return summerWorkTime.breakLenghtMinutes;
      break;

    case 2:
      return autumnWorkTime.breakLenghtMinutes;
      break;

    case 3:
      return winterWorkTime.breakLenghtMinutes;
      break;
  }
}

bool aFasterThanB(tmElements_t a, tmElements_t b) {
  if ((a.Month < b.Month) || ((a.Month == b.Month) && (a.Day < b.Day))) {
    return true;
  } else {
    return false;
  }
}
