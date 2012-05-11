/*
 * Originally implemented by dzimboum
 *
 * Ported by Dan Malec to work with the Adafruit RGB LCD Shield
 * - Changed type of lcd (and related includes) to Adafruit_RGBLCDShield
 * - Changed lcd.init() call to lcd.begin(16, 2)
 *
 * ********************************************************************************
 * Dependencies
 * ********************************************************************************
 * Adafruit Industries's RGB 16x2 LCD Shield library:
 *       https://github.com/adafruit/Adafruit-RGB-LCD-Shield-Library
 * Adafruit Industries's MCP23017 I2C Port Expander library:
 *       https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
 * ********************************************************************************
 */
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>
#include <EEPROM.h>
#include <RgbLcdShieldHiScores.h>

Adafruit_RGBLCDShield lcd;
RgbLcdShieldHiScores hsc(lcd);

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  // LCD has 16 columns & 2 rows
  lcd.begin(16, 2);

  hsc.begin(10, 0, 0x1001);
  hsc.insert(1234);
  hsc.insert(2345);
  hsc.insert(123);
  hsc.insert(123);
  hsc.insert(123);
  hsc.insert(123);
}

void loop()
{
  hsc.display();
  delay(1000);
}
