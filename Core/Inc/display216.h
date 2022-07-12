/*
 * display216.h
 *
 *  Created on: Jul 6, 2022
 *      Author: enesb
 */

#ifndef INC_DISPLAY216_H_
#define INC_DISPLAY216_H_

#include "main.h"

#define EN	(1 << 2)
#define RS	(1 << 0)
#define RW	(1 << 1)
#define UN	(1 << 3)

#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

#define LCD_2LINE		0x08
#define LCD_4BITMODE	0x00

#define LCD_CLEAR		0x01
#define LCD_HOME		0x02

#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

void send_command(I2C_HandleTypeDef* hi2c1, uint8_t DevAddress, uint8_t data);

void send_data(I2C_HandleTypeDef* hi2c1, uint8_t DevAddress, uint8_t data);

void lcd_init(I2C_HandleTypeDef* hi2c1, uint8_t DevAddress);




#endif /* INC_DISPLAY216_H_ */
