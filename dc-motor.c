/*******************************************************************************
 *
 * Module: DC-Motor
 *
 * File Name: dc-motor.c
 *
 * Description: Source file for the DC-Motor driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/

#include "pwm.h"
#include "dc-motor.h"
#include "std_types.h"

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction for the two motor pins through the GPIO driver.
 * Stop the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DCMOTOR_PORT_ID,DCMOTOR_PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,PIN_OUTPUT);
	DcMotor_Rotate(STOP,0);
}

/*
 * Description :
 * Rotate the DC Motor CW or A-CW or stop the motor based on the input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state == STOP)
	{
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN0_ID,0);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,0);
		PWM_Timer0_Start(speed);
	}
	else if(state == CLOCKWISE)
	{
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN0_ID,1);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,0);
		PWM_Timer0_Start(speed);
	}
	else if (state == ANTICLOCKWISE)
	{
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN0_ID,0);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,1);
		PWM_Timer0_Start(speed);
	}
}
