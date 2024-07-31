#include "HX711.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

HX711 loadcell;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Setting Required Constants
const long calibration_factor = 420.89795918367346938775510204082; //We get this constant through calibration process
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;

void setup() {
  // Initializing the Serial Communication
  Serial.begin(9600);
  Serial.println("Initializing the scale");
  
  // Initializing the HX711 scale
  loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  loadcell.set_scale(calibration_factor);

  // Inititalzing the LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  float data = loadcell.get_units(10);
  Serial.print(data);
  Serial.println(" kg");

  lcd.print(data);
  lcd.setCursor(5, 0);
  lcd.print("kg");

  delay(1000);

  lcd.clear();
}
