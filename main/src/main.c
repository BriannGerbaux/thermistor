#include <stdio.h>

#include "../include/adc.h"
#include "../include/thermistor.h"

void app_main(void)
{
    adc_oneshot_unit_handle_t adc_handle;
    adc_channel_t adc_channel = ADC_CHANNEL_0; // Pin D4

    config_adc(&adc_handle, adc_channel);

    while (1) {
        int adc_raw_output = read_raw_adc(&adc_handle, adc_channel);
        int voltage = get_output_voltage(adc_raw_output);
        float thermistor_resistance = get_thermistor_resistance((float) voltage);
        float temperature = thermistor_to_celsius(thermistor_resistance);

        printf("Temperature: %f\n", temperature);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}