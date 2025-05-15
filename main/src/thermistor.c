#include <math.h>

#include "../include/thermistor.h"

float get_thermistor_resistance(float V_out)
{
    float V_input = 3300; // 5000mV (5V) input
    float R2 = R1 * (V_out / (V_input - V_out));
    return R2;
}

double thermistor_to_celsius(float thermistor_resistance)
{
    double tempK = 1.0 / ( (1.0 / T0_KELVIN) + (1.0 / BETA) * log(thermistor_resistance / R1) );
    return tempK - 273.15;
}