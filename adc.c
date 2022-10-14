/*******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "adc.h"
#include "avr/io.h" /* To use the ADC Registers */
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                            Functions Definitions                            *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * ADLAR	= 0 right adjusted
	 * MUX	4:0 = 00000 to choose channel 0 as initialization
	 */
	ADMUX = 0;
	ADMUX = (ADMUX & 0X3F) | ((Config_Ptr->ref_volt) << REFS0);

	/* ADCSRA Register Bits Description:
	 * ADEN	 = 1 Enable ADC
	 * ADIE	 = 0 Disable ADC Interrupt
	 * ADATE = 0 Disable Auto Trigger
	 */
	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADIE);
	ADCSRA = (ADCSRA & 0XF8) | ((Config_Ptr->prescaler) & 0X07);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	/* Input channel number must be from 0 --> 7 */
	channel_num &= 0x07;
	/* Clear the first 5 bits in the ADMUX (Channel Number MUX 4:0 bits) before setting the required channel */
	ADMUX &= 0xE0;
	/* Choose the correct channel by setting the channel number in MUX 4:0 bits */
	ADMUX = ADMUX | channel_num;
	/* Write '1' to ADSC to start conversion */
	SET_BIT(ADCSRA,ADSC);
	/* Wait for conversion to complete, ADIF becomes '1' */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	 /* Clear ADIF by writing '1' to it :) */
	SET_BIT(ADCSRA,ADIF);
	/* Read the digital value from the data register */
	return ADC;
}
