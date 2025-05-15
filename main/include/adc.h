#ifndef ADC_H
#define ADC_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali_scheme.h"

#define UNIT ADC_UNIT_2
#define BITWIDTH ADC_BITWIDTH_12
#define ATTEN ADC_ATTEN_DB_12


void config_adc(adc_oneshot_unit_handle_t *adc_handle, adc_channel_t adc_channel);
int read_raw_adc(adc_oneshot_unit_handle_t *adc_handle, adc_channel_t adc_channel);
int get_output_voltage(int adc_raw_output);

#endif