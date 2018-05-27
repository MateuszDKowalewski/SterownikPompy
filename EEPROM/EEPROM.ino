#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
  byte val;

  val = 3;
  EEPROM.write(1, val);

  val = 20;
  EEPROM.write(2, val);

  val = 10;
  EEPROM.write(3, val);

  val = 0;
  EEPROM.write(4, val);

  val = 4;
  EEPROM.write(5, val);

  val = 90;
  EEPROM.write(6, val);

  val = 30;
  EEPROM.write(7, val);

  val = 6;
  EEPROM.write(8, val);

  val = 22;
  EEPROM.write(9, val);

  val = 8;
  EEPROM.write(10, val);

  val = 0;
  EEPROM.write(11, val);

  val = 6;
  EEPROM.write(12, val);

  val = 90;
  EEPROM.write(13, val);

  val = 30;
  EEPROM.write(14, val);

  val = 9;
  EEPROM.write(15, val);

  val = 23;
  EEPROM.write(16, val);

  val = 10;
  EEPROM.write(17, val);

  val = 0;
  EEPROM.write(18, val);

  val = 4;
  EEPROM.write(19, val);

  val = 90;
  EEPROM.write(20, val);

  val = 30;
  EEPROM.write(21, val);

  val = 12;
  EEPROM.write(22, val);

  val = 22;
  EEPROM.write(23, val);

  val = 0;
  EEPROM.write(24, val);

  val = 0;
  EEPROM.write(25, val);

  val = 0;
  EEPROM.write(26, val);

  val = 0;
  EEPROM.write(27, val);

  val = 0;
  EEPROM.write(28, val);

  Serial.println(EEPROM.length());

  for(int i = 1; i < 29; i++){
    Serial.println(EEPROM.read(i));
  }
}

void loop() {

}
