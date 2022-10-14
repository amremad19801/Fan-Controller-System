/*******************************************************************************
 *
 * Module: DC-Motor
 *
 * File Name: dc-motor.h
 *
 * Description: Header file for the DC-Motor driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "gpio.h"
#include "std_types.h"

/*******************************************************************************
 *                                 Definitions                                 *
 *******************************************************************************/

/* DC-Motor HW Port and Pins IDs */
#define DCMOTOR_PORT_ID       PORTB_ID
#define DCMOTOR_PIN0_ID       PIN0_ID
#define DCMOTOR_PIN1_ID       PIN1_ID

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

typedef enum
{
	STOP,
	CLOCKWISE,
	ANTICLOCKWISE
}DcMotor_State;

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction for the two motor pins through the GPIO driver.
 * Stop the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Rotate the DC Motor CW or A-CW or stop the motor based on the input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State,uint8);

#endif /* DC_MOTOR_H_ */
