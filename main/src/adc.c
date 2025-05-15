#include "../include/adc.h"

void config_adc(adc_oneshot_unit_handle_t *adc_handle, adc_channel_t adc_channel)
{
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = UNIT,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, adc_handle));

    adc_oneshot_chan_cfg_t config = {
        .bitwidth = BITWIDTH,
        .atten = ATTEN,
    };

    ESP_ERROR_CHECK(adc_oneshot_config_channel(*adc_handle, adc_channel, &config));
}

int read_raw_adc(adc_oneshot_unit_handle_t *adc_handle, adc_channel_t adc_channel)
{
    int adc_raw_output = 0;
    esp_err_t err = adc_oneshot_read(*adc_handle, adc_channel, &adc_raw_output);

    while (err == ESP_ERR_TIMEOUT) {
        err = adc_oneshot_read(*adc_handle, adc_channel, &adc_raw_output);
    }
    ESP_ERROR_CHECK(err);
    return adc_raw_output;
}

int get_output_voltage(int adc_raw_output)
{
    int voltage = 0;
    adc_cali_handle_t adc_cali_handle;
    adc_cali_line_fitting_config_t cali_config = {
        .unit_id = UNIT,
        .atten = ATTEN,
        .bitwidth = BITWIDTH,
    };

    ESP_ERROR_CHECK(adc_cali_create_scheme_line_fitting(&cali_config, &adc_cali_handle));

    ESP_ERROR_CHECK(adc_cali_raw_to_voltage(adc_cali_handle, adc_raw_output, &voltage));
    return voltage;
}