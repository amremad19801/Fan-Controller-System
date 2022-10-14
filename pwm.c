/*******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the PWM driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/

#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"	/* To use Timer0 Registers */

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz.
 * Timer0 will be used with pre-scaler F_CPU/8.
 * F_PWM = (F_CPU) / (256 * N) = (10^6) / (256*8) = 500Hz.
 * Duty Cycle can be changed by updating the value in the Output Compare Register.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* Set Timer0 Initial Value to 0 */
	TCNT0 = 0;

	/* Set Timer0 Compare Value */
	OCR0 = (((float)duty_cycle / 100) * 255);

	/* Configure PB3/OC0 as output pin */
	GPIO_setupPinDirection(TIMER0_PORT_ID,TIMER0_PIN_ID,PIN_OUTPUT);

	/* Configure Timer/Counter Control Register
	 * 1. Fast PWM mode FOC0 = 0
	 * 2. Fast PWM Mode WGM00 = 1 & WGM01 = 1
	 * 3. Clear OC0 when match occurs (Non Inverting Mode) COM00 = 0 & COM01 = 1
	 * 4. Clock = F_CPU/8 CS00 = 0 CS01 = 1 CS02 = 0
	 */
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
}
