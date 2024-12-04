/*
 * main.h
 *
 *  Created on: Nov 30, 2024
 *      Author: vishw
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct {
	uint32_t gpioa_en :1;
	uint32_t gpiob_en :1;
	uint32_t gpioc_en :1;
	uint32_t gpiod_en :1;
	uint32_t gpioe_en :1;
	uint32_t gpiof_en :1;
	uint32_t gpiog_en :1;
	uint32_t gpioh_en :1;
	uint32_t gpioi_en :1;
	uint32_t reserved_1 :3;
	uint32_t crc_en :1;
	uint32_t reserved_2 :3;
	uint32_t reserved_3 :2;
	uint32_t bkpsram_en :1;
	uint32_t reserved_4 :1;
	uint32_t ccmdataram_en :1;
	uint32_t dma1_en :1;
	uint32_t dma2_en :2;
	uint32_t reserved_5 :2;
	uint32_t ethmac_en :1;
	uint32_t ethmactx_en :1;
	uint32_t ethmacrx_en :1;
	uint32_t ethmacptp_en :1;
	uint32_t otghs_en :1;
	uint32_t otghsulpi_en :1;
	uint32_t reserved_6 :1;
} RCC_AHB1ENR_t;



typedef struct {
	uint32_t pin_0 :2;
	uint32_t pin_1 :2;
	uint32_t pin_2 :2;
	uint32_t pin_3 :2;
	uint32_t pin_4 :2;
	uint32_t pin_5 :2;
	uint32_t pin_6 :2;
	uint32_t pin_7 :2;
	uint32_t pin_8 :2;
	uint32_t pin_9 :2;
	uint32_t pin_10 :2;
	uint32_t pin_11 :2;
	uint32_t pin_12 :2;
	uint32_t pin_13 :2;
	uint32_t pin_14 :2;
	uint32_t pin_15 :2;
} GPIOx_MODE_t;

typedef struct {
	uint32_t pin_0 :2;
	uint32_t pin_1 :2;
	uint32_t pin_2 :2;
	uint32_t pin_3 :2;
	uint32_t pin_4 :2;
	uint32_t pin_5 :2;
	uint32_t pin_6 :2;
	uint32_t pin_7 :2;
	uint32_t pin_8 :2;
	uint32_t pin_9 :2;
	uint32_t pin_10 :2;
	uint32_t pin_11 :2;
	uint32_t pin_12 :2;
	uint32_t pin_13 :2;
	uint32_t pin_14 :2;
	uint32_t pin_15 :2;
} GPIOx_OUT_SPEED_t;

typedef struct {
	uint32_t pin_0 :2;
	uint32_t pin_1 :2;
	uint32_t pin_2 :2;
	uint32_t pin_3 :2;
	uint32_t pin_4 :2;
	uint32_t pin_5 :2;
	uint32_t pin_6 :2;
	uint32_t pin_7 :2;
	uint32_t pin_8 :2;
	uint32_t pin_9 :2;
	uint32_t pin_10 :2;
	uint32_t pin_11 :2;
	uint32_t pin_12 :2;
	uint32_t pin_13 :2;
	uint32_t pin_14 :2;
	uint32_t pin_15 :2;
} GPIOx_PUP_t;

typedef struct {
	uint32_t pin_0 :4;
	uint32_t pin_1 :4;
	uint32_t pin_2 :4;
	uint32_t pin_3 :4;
	uint32_t pin_4 :4;
	uint32_t pin_5 :4;
	uint32_t pin_6 :4;
	uint32_t pin_7 :4;
} GPIOx_AFRL_t;

typedef struct {
	uint32_t fraction :4;
	uint32_t mantissa :12;
	uint32_t reserved :16;
} USART_BRR_t;

typedef struct {
	uint32_t send_break :1;
	uint32_t receiver_wake_up :1;
	uint32_t receiver_enable :1;
	uint32_t transmitter_enable :1;
	uint32_t idle_interrupt_enable :1;
	uint32_t rxne_interrupt_enable :1;
	uint32_t transmission_complete_interrupt_enable :1;
	uint32_t txe_interrupt_enable :1;
	uint32_t pe_interrupt_enable :1;
	uint32_t parity_selection :1;
	uint32_t parity_control_enable :1;
	uint32_t wake_up_method :1;
	uint32_t word_length :1;
	uint32_t usart_enable :1;
	uint32_t reserved :1;
	uint32_t oversampling_mode :1;
	uint32_t reserved_2 :16;
} USART_CR1_t;

typedef struct {

} USART_CR3_t;

typedef struct {
	uint32_t parity_error_pe :1;
	uint32_t framing_error_fe :1;
	uint32_t noise_detected_flag_nf :1;
	uint32_t overrun_error_oe :1;
	uint32_t idle_line_detected_IDLE :1;
	uint32_t read_data_register_not_empty_rxne :1;
	uint32_t transmission_complete_tc :1;
	uint32_t transmit_data_register_empty_txe :1;
	uint32_t lin_break_detection_flag_lbd :1;
	uint32_t cts_flag_CTS :1;
	uint32_t reserved :32;

} USART_SR_t;

typedef struct {
	uint32_t data_value :8;
	uint32_t reserved :24;
} USART_DR_t;

#endif /* MAIN_H_ */
