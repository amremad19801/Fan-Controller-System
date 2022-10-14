/*******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: Header file for the LM35 Temperature Sensor driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID      		     2
#define SENSOR_MAXIMUM_VOLTAGE		     1.5
#define SENSOR_MAXIMUM_TEMPERATURE    	 150

/*******************************************************************************
 *                            Functions Prototypes                            *
 *******************************************************************************/

/*
 * Description :
 * Calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
