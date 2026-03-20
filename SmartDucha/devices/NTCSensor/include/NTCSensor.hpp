/**
 * @file NTCSensor.hpp
 * 
 * @brief NTCSensor class header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 14-06-2022
 */
#ifndef NTCSENSOR_HPP_
#define NTCSENSOR_HPP_

#include <cstdint>
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "hal/adc_types.h"

#define NTC_ADC_UNIT            ADC_UNIT_1
#define NTC_ADC_CHANNEL         ADC_CHANNEL_4
#define NTC_ADC_ATTEN           ADC_ATTEN_DB_11
#define NTC_ADC_BIT_WIDTH       ADC_WIDTH_BIT_12

struct adc_config_t 
{
    adc_atten_t atten;
    adc_channel_t channel;
    adc_unit_t unit;
    adc_bits_width_t bit_width;
};

class NTCSensor
{
private:
    /**
     * @brief Raw reading from adc
     * 
     */
    double _value;

    NTCSensor( adc_config_t );
    // TODO: Add ADC port information

        esp_adc_cal_characteristics_t _ntcChars;
        adc_config_t _config;

public:
    
    /**
     * @brief NTCSensor constructor
     * 
     */
    
    ~NTCSensor();
    
    static NTCSensor& getInstance();

    double readNTC();
    double getTemp();
};

#endif /* NTCSENSOR_HPP_ */
