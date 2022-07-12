/*
 * display216.c
 *
 *  Created on: Jul 6, 2022
 *      Author: enesb
 */

#include "display216.h"

static void sendLCDData(I2C_HandleTypeDef* hi2c1, uint8_t DevAddress, uint8_t data);


void send_command(I2C_HandleTypeDef* hi2c1, uint8_t DevAddress, uint8_t data){

	uint8_t data_h, data_l;

	data_h = (data & 0xF0);
	data_l = ((data << 4) & (0xF0));

	sendLCDData(hi2c1, DevAddress, data_h);
	sendLCDData(hi2c1, DevAddress, data_l);
}

void send_data(I2C_HandleTypeDef* hi2c1, uint8_t DevAddress, uint8_t data){

	uint8_t data_h, data_l;

	data_h = (data & 0xF1);
	data_l = (data << 4) & (0xF1);

	sendLCDData(hi2c1, DevAddress, data_h);
	sendLCDData(hi2c1, DevAddress, data_l);
}

static void sendLCDData(I2C_HandleTypeDef* hi2c1, uint8_t DevAddress, uint8_t data){

	uint8_t sendDataFormat;

	sendDataFormat = data | UN;
	HAL_I2C_Master_Transmit(hi2c1, DevAddress, &sendDataFormat, 1, 0);

	sendDataFormat = data | UN | EN;
	HAL_I2C_Master_Transmit(hi2c1, DevAddress, &sendDataFormat, 1, 0.001);

	sendDataFormat = data | UN;
	HAL_I2C_Master_Transmit(hi2c1, DevAddress, &sendDataFormat, 1, 0.05);

}

void lcd_init(I2C_HandleTypeDef* hi2c1, uint8_t DevAddress){
	HAL_Delay(50);

	uint8_t resetVal = (1U << 3);
	HAL_I2C_Master_Transmit(hi2c1, DevAddress, &resetVal, 1, 10);

	HAL_Delay(1000);

	// Enter 4 Bit Mode
	// First Try
	sendLCDData(hi2c1, DevAddress, (0x03 << 4));
	HAL_Delay(4.5);
	//Second
	sendLCDData(hi2c1, DevAddress, (0x03 << 4));
	HAL_Delay(4.5);
	//Third
	sendLCDData(hi2c1, DevAddress, (0x03 << 4));
	HAL_Delay(0.15);

	sendLCDData(hi2c1, DevAddress, (0x02 << 4));

	//Function Set
	send_command(hi2c1, DevAddress, LCD_FUNCTIONSET | LCD_2LINE);

	//LCD Display Off
	send_command(hi2c1, DevAddress, LCD_DISPLAYCONTROL | LCD_DISPLAYON);

	//Display Clear
	send_command(hi2c1, DevAddress, LCD_CLEAR);
	HAL_Delay(2);

	//Entry Mode Set
	send_command(hi2c1, DevAddress, LCD_ENTRYMODESET | LCD_ENTRYSHIFTINCREMENT);


	send_command(hi2c1, DevAddress, LCD_RETURNHOME);
	HAL_Delay(2);
}
