/*******************************************************************************
 *
 * File Name: main.c
 *
 * Author: Amr Emad
 *
 * Description: Fan Controller System
 *
 * Date: 10/4/2022
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "dc-motor.h"
#include <util/delay.h>	/* To use the delay functions */
#include "lm35_sensor.h"

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

typedef enum{
	NO_DUTY_CYCLE  = 0,
	DUTY_CYCLE_25  = 25,
	DUTY_CYCLE_50  = 50,
	DUTY_CYCLE_75  = 75,
	DUTY_CYCLE_100 = 100
}DutyCycleState;

/*******************************************************************************
 *                              Application Code                               *
 *******************************************************************************/

int main(void)
{
	/* Initialization Code*/

	/* Variable to store Current Temperature Value */
	uint8 currTemp = 0;

	/* Variable to store Previous Temperature Value */
	uint8 prevTemp = 0;

	/* ADC Configuration */
	const ADC_ConfigType ConfigType = {ADC_INTERNAL_REFERNCE_VOLTAGE,DIVISION_FACTOR_8};

	/* Initialize the drivers */

	/* Initialize the LCD driver */
	LCD_init();

	/* Initialize the DC-Motor driver */
	DcMotor_Init();

	/* Initialize the ADC driver */
	ADC_init(&ConfigType);

	LCD_displayStringRowColumn(0,3,"Fan is ");
	LCD_displayStringRowColumn(1,3,"Temp =    C");

	_delay_ms(50);
	while(1)
	{
		/* Application Code */

		currTemp = LM35_getTemperature();

		if(prevTemp != currTemp)
		{
			LCD_moveCursor(0,10);
			if(currTemp < 30)
			{
				DcMotor_Rotate(STOP,NO_DUTY_CYCLE);
				LCD_displayString("OFF");
			}
			else if(currTemp >= 120){
				DcMotor_Rotate(CLOCKWISE,DUTY_CYCLE_100);
				LCD_displayString("ON ");
			}
			else if(currTemp >= 90){
				DcMotor_Rotate(CLOCKWISE,DUTY_CYCLE_75);
				LCD_displayString("ON ");
			}
			else if(currTemp >= 60){
				DcMotor_Rotate(CLOCKWISE,DUTY_CYCLE_50);
				LCD_displayString("ON ");
			}
			else if(currTemp >= 30){
				DcMotor_Rotate(CLOCKWISE,DUTY_CYCLE_25);
				LCD_displayString("ON ");
			}

			LCD_moveCursor(1,10);
			if(currTemp >= 100)
			{
				LCD_intgerToString(currTemp);
			}
			else
			{
				LCD_intgerToString(currTemp);
				LCD_displayCharacter(' ');
			}
		}
		prevTemp = currTemp;
	}
}
