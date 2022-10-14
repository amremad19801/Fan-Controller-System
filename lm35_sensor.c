/*******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: Source file for the LM35 Temperature Sensor driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/

#include "adc.h"
#include "lm35_sensor.h"

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*
 * Description :
 * Calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read the ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value */
	temp_value = (uint8)(((uint32)adc_value * SENSOR_MAXIMUM_TEMPERATURE * ADC_REFERENCE_VOLTAGE) / (ADC_MAXIMUM_VALUE * SENSOR_MAXIMUM_VOLTAGE));

	return temp_value;
}
