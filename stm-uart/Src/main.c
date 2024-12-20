/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {

	RCC_AHB1ENR_t volatile *p_peripheral_ahb_clock_reg =
			(RCC_AHB1ENR_t*) 0x40023830;
	uint32_t volatile *p_peripheral_apb_clock_reg = (uint32_t*) 0x40023840;
	// The above register is not abstratable for unknown reasons
	GPIOx_MODE_t volatile *p_mode_reg = (GPIOx_MODE_t*) 0x40020000;
	GPIOx_OUT_SPEED_t volatile *p_out_speed_reg =
			(GPIOx_OUT_SPEED_t*) 0x40020008;
	GPIOx_PUP_t volatile *p_pull_up_down_reg = (GPIOx_PUP_t*) 0x4002000C;
	GPIOx_AFRL_t volatile *p_afrl_reg = (GPIOx_AFRL_t*) 0x40020020;
	//usart pin addressses
	USART_BRR_t volatile *p_uart_brr_reg = (USART_BRR_t*) 0x40004408;
	USART_CR1_t volatile *p_uart_control_reg = (USART_CR1_t*) 0x4000440C;
	USART_SR_t volatile *p_uart_status_reg = (USART_SR_t*) 0x40004400;
	USART_DR_t volatile *p_uart_data_reg = (USART_DR_t*) 0x40004404;
	//other constants
	uint32_t f_apb1_ck = 16000000;
	uint32_t baud_rate = 9600;
	uint32_t brr_value;
	//data buffer
	uint8_t tx_buff[] = { ' ', 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l',
			'd' };

	//enabling the clock for gpioa peripheral and uart
	p_peripheral_ahb_clock_reg->gpioa_en = 1;
	*p_peripheral_apb_clock_reg |= (1 << 17);

	//setting the gpioa pin 2 and 3 on alternate function mode;
	p_mode_reg->pin_2 = 2;
	p_mode_reg->pin_3 = 2;

	//setting the gpioa pin 2 and 3 output speed as medium
	p_out_speed_reg->pin_2 = 0;
	p_out_speed_reg->pin_3 = 0;

	//enabling pull up pull down for pin 2 and pin 3
	p_pull_up_down_reg->pin_2 = 1;
	p_pull_up_down_reg->pin_3 = 1;

	//configuring alternate function for pin 2 and 3
	p_afrl_reg->pin_2 = 7;
	p_afrl_reg->pin_3 = 7;

	//baud rate calculation
	brr_value = f_apb1_ck / (baud_rate);
	p_uart_brr_reg->mantissa = (brr_value >> 4) & 0x0FFF;
	p_uart_brr_reg->fraction = (brr_value & 0xF) & 0x0F;

	//configuration of control register.
	p_uart_control_reg->usart_enable = 1;
	p_uart_control_reg->transmitter_enable = 1;
	p_uart_control_reg->receiver_enable = 1;
	p_uart_control_reg->word_length = 0;

	for (;;) {
		// Calculate the buffer size dynamically
		int tx_buff_size = sizeof(tx_buff) / sizeof(tx_buff[0]); // Number of elements in tx_buff

		// Wait for the TXE (Transmit data register empty) flag to be set
		for (int i = 0; i < tx_buff_size; i++) { // Loop over the calculated buffer size
			while (!(p_uart_status_reg->transmit_data_register_empty_txe))
				;
			p_uart_data_reg->data_value = tx_buff[i]; // Send each byte in tx_buff
			for (volatile int j = 0; j < 1000000; j++)
				;  // Simple delay (you can adjust this)
		}
	}

}
