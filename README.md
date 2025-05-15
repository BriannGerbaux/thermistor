# _ESP32 Thermistor sensor_

This project reads a temperature from a sensor and displays it on the monitor output.
It is made with the ESP-IDF framework.

# How does it work
The thermistor resistance changes depending on it's temperature. Knowing that, we can use a voltage divider connected to an ADC port on the esp32 board and compute the current resistance of the thermistor.
With the current thermistor resistance value, and the thermistor known resistance at 25°C, we can now calculate the current room temperature and display it.

# The board connectics
![20250515_110208](https://github.com/user-attachments/assets/73ca9543-6555-4e2b-a377-0ccdd13d369a)

# Schematics
![circuit](https://github.com/user-attachments/assets/b0719a2d-27a4-4f13-8e95-496206128a25)
