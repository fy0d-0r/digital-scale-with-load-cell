# Creating a Digital Scale with Load Cell

## Assembly
![](https://github.com/fy0d-0r/digital-scale-with-load-cell/blob/main/images/assembled-components.png)

### Connections between Hx711 and Arduino UNO
- DT - GPIO pin 4
- SCK - GPIO pin 5
- GND on Hx711 - GND on Arduino UNO
- VCC on Hx711 - 5V on Arduino UNO

### Connections between LCD I2C and Arduino UNO
- SDA - A4
- SCL - A5
- GND on LCD I2C - GND on Arduino UNO
- VCC on LCD I2C - 5V on Arduino UNO

### Components
- Arduino UNO Development Board
- Load Cell 5kg
- Hx711 Amplifier
- LCD I2C Display
- Half-sized Breadboard

## Codes Breakdown
Including Required Libraries
```cpp
#include "HX711.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

Initializing Objects to Work With
```cpp
HX711 loadcell;
LiquidCrystal_I2C lcd(0x27, 16, 2);
```

## Calibration

1. Before calibration process be sure no load is applied on the load cell.
2. Call `scale.begin(4, 5);` for initializing the scale at GPIO pin 4 for DT and pin 5 for SCK.
3. Call `set_scale()` function with no parameter
> `set_scale()` function set the scale specified. If no parameter is specified scale is defaulted to 1.
> This means, since we do not have calibration factor yet, we just want to print the values as they are. So we multiply with 1 to change nothing.
4. Call `tare()` function to reset the readings to 0.
5. Place a known weight on the scale
6. Calculate the Calibration factor according to `calibration_factor = printed_value / known_weight`

```cpp
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
```
