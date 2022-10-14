/*******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the PWM driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Timer0 HW Port and Pin IDs */
#define TIMER0_PORT_ID       PORTB_ID
#define TIMER0_PIN_ID       PIN3_ID

/*******************************************************************************
 *                            Functions Prototypes                            *
 *******************************************************************************/

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz.
 * Timer0 will be used with pre-scaler F_CPU/8.
 * F_PWM = (F_CPU) / (256 * N) = (10^6) / (256*8) = 500Hz.
 * Duty Cycle can be changed by updating the value in the Output Compare Register.
 */
void PWM_Timer0_Start(uint8);

#endif /* PWM_H_ */
