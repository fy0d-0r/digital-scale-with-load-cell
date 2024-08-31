# Creating a Digital Scale with Load Cell

## Assembly

![simulation](https://github.com/user-attachments/assets/257b3408-27fe-4d91-a722-b11b1b64c76a)

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


Initializing the Hx711 on Specified Pins
```cpp
HX711 loadcell;
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;
const long calibration_factor = 420.89795918367346938775510204082; // The constant is calculated through calibration process and adjusting the outcome by trial and error

// void setup()
loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
loadcell.set_scale(calibration_factor);

// void loop()
float data = loadcell.get_units(10);
```

Initializing LCD I2C
```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);

// void setup()
lcd.init();
lcd.backlight();

// void loop()
lcd.print(data);
lcd.setCursor(5, 0);
lcd.print("kg");
delay(1000);
lcd.clear();
```



## Calibration
We only get serial data when we have some weight on the scale. We need a way to change the electrical signals to kilograms. This process is called calibration. In order to perform calibration, we need to calculate calibration factor first.

1. Before calibration process be sure no load is applied on the load cell.
2. Call `scale.begin(4, 5);` for initializing the scale at GPIO pin 4 for DT and pin 5 for SCK.
3. Call `set_scale()` function with no parameter
> `set_scale()` function set the scale specified. If no parameter is specified scale is defaulted to 1.
> This means, since we do not have calibration factor yet, we just want to print the values as they are. So we multiply with 1 to change nothing.
4. Call `tare()` function to reset the readings to 0.
5. Place a known weight onto the scale
6. Calculate the Calibration factor
> calibration_factor = serial_data / known_weight

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
