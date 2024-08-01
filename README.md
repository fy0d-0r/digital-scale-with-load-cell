# Creating a Digital Scale with Load Cell

## Assembly
![](https://github.com/fy0d-0r/digital-scale-with-load-cell/blob/main/images/assembled-components.png)

DT - GPIO pin 4
SCK - GPIO pin 5

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
