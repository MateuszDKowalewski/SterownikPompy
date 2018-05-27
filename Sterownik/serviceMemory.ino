//EEPROM
//1 - spring month
//2 - spring day
//3 - spring start hour
//4 - spring start minute
//5 - spring cycle quantity
//6 - spring cycle lenght in minutes
//7 - spring break lenght in minutes
//8 - summer month
//9 - summer day
//10 - summer start hour
//11 - summer start minute
//12 - summer cycle quantity
//13 - summer cycle lenght in minutes
//14 - summer break lenght in minutes
//15 - autumn month
//16 - autumn day
//17 - autumn start hour
//18 - autumn start minute
//19 - autumn cycle quantity
//20 - autumn cycle lenght in minutes
//21 - autumn break lenght in minutes
//22 - winter month
//23 - winter day
//24 - winter start hour
//25 - winter start minute
//26 - winter cycle quantity
//27 - winter cycle lenght in minutes
//28 - winter break lenght in minutes

void setSezons() {
  //gets first day of all sezons

  spring.Month = EEPROM.read(1);
  spring.Day = EEPROM.read(2);

  summer.Month = EEPROM.read(8);
  summer.Day = EEPROM.read(9);

  autumn.Month = EEPROM.read(15);
  autumn.Day = EEPROM.read(16);

  winter.Month = EEPROM.read(22);
  winter.Day = EEPROM.read(23);
}

