idf_component_register(SRCS "src/main.c" "src/adc.c" "src/thermistor.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_adc)