# Creating a Digital Scale with Load Cell

## Assembly
![](https://github.com/fy0d-0r/digital-scale-with-load-cell/blob/main/images/assembled-components.png)

### Components
- Arduino UNO Development Board
- Load Cell 5kg
- Hx711 Amplifier
- LCD I2C Display
- Half-sized Breadboard

## Codes Explained
Including Required Libraries
```cpp
#include "HX711.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

## Calibration
