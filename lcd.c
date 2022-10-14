/*******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Amr Emad
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "lcd.h"
#include "gpio.h"
#include <util/delay.h>	/* To use the delay functions */
#include "common_macros.h"	/* To use the macros like GET_BIT */

/*******************************************************************************
 *                            Functions Definitions                            *
 *******************************************************************************/

/*
 * Description:
 * Initialize the LCD driver:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bit or 8-bit.
 */
void LCD_init(void)
{
	/* Configure the direction for RS and E pins as output pins */
	GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);
	/* LCD Power ON delay always > 15ms */
	_delay_ms(20);
#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* Use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
#elif(LCD_DATA_BITS_MODE == 8)
	/* Configure the data port as output port */
	GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);
	/* Use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
#endif
	/* Cursor off */
	LCD_sendCommand(LCD_CURSOR_OFF);
	/* Clear the LCD at the beginning */
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

/*
 * Description:
 * Send the required command to the screen.
 */
void LCD_sendCommand(uint8 command)
{
	/* Instruction Mode RS = 0 */
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);
	/* Delay for processing Tas = 50ns */
	_delay_ms(1);
	/* Enable LCD E = 1 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	/* Delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);
#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,7));

	/* Delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* Disable LCD E = 0 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	/* Delay for processing Th = 13ns */
	_delay_ms(1);
	/* Enable LCD E = 1 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	/* Delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,3));

	/* Delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* Disable LCD E = 0 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	/* Delay for processing Th = 13ns */
	_delay_ms(1);
#elif(LCD_DATA_BITS_MODE == 8)
	/* Write the required command to the data bus D0 --> D7 */
	GPIO_writePort(LCD_DATA_PORT_ID,command);
	/* Delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* Disable LCD E = 0 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	/* Delay for processing Th = 13ns */
	_delay_ms(1);
#endif
}

/*
 * Description:
 * Display the required character on the screen.
 */
void LCD_displayCharacter(uint8 data)
{
	/* Data Mode RS = 1 */
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH);
	/* Delay for processing Tas = 50ns */
	_delay_ms(1);
	/* Enable LCD E = 1 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	/* Delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);
#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,4));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,5));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,6));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,7));

	/* Delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* Disable LCD E = 0 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	/* Delay for processing Th = 13ns */
	_delay_ms(1);
	/* Enable LCD E = 1 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	/* Delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,0));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,1));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,2));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,3));

	/* Delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* Disable LCD E = 0 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	/* Delay for processing Th = 13ns */
	_delay_ms(1);
#elif(LCD_DATA_BITS_MODE == 8)
	/* Write the required command to the data bus D0 --> D7 */
	GPIO_writePort(LCD_DATA_PORT_ID,data);
	/* Delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* Disable LCD E = 0 */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	/* Delay for processing Th = 13ns */
	_delay_ms(1);
#endif
}

/*
 * Description:
 * Display the required string on the screen.
 */
void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/********************* Another Method **********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
	************************************************************/
}

/*
 * Description:
 * Move the cursor to a specified row and column index on the screen.
 */
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;
	
	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address = col;
				break;
		case 1:
			lcd_memory_address = col + 0x40;
				break;
		case 2:
			lcd_memory_address = col + 0x10;
				break;
		case 3:
			lcd_memory_address = col + 0x50;
				break;
	}					
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description:
 * Display the required string in a specified row and column index on the screen.
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	/* Go to to the required LCD position */
	LCD_moveCursor(row,col);
	/* Display the string */
	LCD_displayString(Str);
}

/*
 * Description:
 * Display the required decimal value on the screen.
 */
void LCD_intgerToString(int data)
{
   /* String to hold the ASCII result */
   char buff[16];
   /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   itoa(data,buff,10);
   /* Display the string */
   LCD_displayString(buff);
}

/*
 * Description :
 * Send the clear screen command.
 */
void LCD_clearScreen(void)
{
	/* Send clear display command */
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}
