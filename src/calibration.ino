#include "HX711.h"

HX711 scale;

void setup() {
  // Initializing the Serial Communication
  Serial.begin(9600);
  Serial.println("Initializing the scale");
  
  // Initializing the HX711 scale
  scale.begin(4, 5); //DT, SCK
  scale.set_scale();
  scale.tare();
}

void loop() {
  float data = scale.get_units(10);
  Serial.print(data);
  Serial.println(" units");

  delay(1000);
}
