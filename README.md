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
```
HX711 loadcell;
LiquidCrystal_I2C lcd(0x27, 16, 2);
```

## Calibration
