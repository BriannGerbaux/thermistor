#ifndef THERMISTOR_H
#define THERMISTOR_H

#define BETA        3950.0     // Replace with your thermistor's Beta value
#define R1          10000.0    // Resistance at 25°C (10k ohms)
#define T0_KELVIN   298.15     // 25°C in Kelvin

float get_thermistor_resistance(float V_out);
double thermistor_to_celsius(float thermistor_resistance);

#endif