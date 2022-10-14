/*******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ATmega32 ADC driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

typedef enum{
	ADC_REFERENCE_VOLTAGE,
	ADC_SUPLLY_VOLTAGE,
	RESERVED,
	ADC_INTERNAL_REFERNCE_VOLTAGE
}ADC_ReferenceVolatge;

typedef enum{
	DIVISION_FACTOR_1,
	DIVISION_FACTOR_2,
	DIVISION_FACTOR_4,
	DIVISION_FACTOR_8,
	DIVISION_FACTOR_16,
	DIVISION_FACTOR_32,
	DIVISION_FACTOR_64,
	DIVISION_FACTOR_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                                 Definitions                                 *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE       1023
#define ADC_REFERENCE_VOLTAGE   2.56

/*******************************************************************************
 *                             Functions Prototype                             *
 *******************************************************************************/

/*
 * Description:
 * Initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description:
 * Read analog data from a certain ADC channel and convert it to digital using the ADC.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
