/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* SPI Master device driver :
 *  demonstartion using W25q128 SPI flash memeory which is configured in Slave and Host MCU in Master"
 */
#include <stdint.h>

//#include "default.h"
#include "rcc.h"
#include "t_delay.h"
#include "gpio.h"
#include "spi.h"
#include "uart.h"


/*
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
*/

#include "stm32f1xx.h"


char rx_buf[1025];
char tx_buf[10];

int main(void)
{

	 system_clk();
	 uart_init();
	 timer_initialise();


	 uart_tran_string("STM32 SPI Master device driver\n");

	 spi_init();


	while(1)
	{

		delay_ms(100);

	GPIOA->ODR &= ~GPIO_ODR_ODR4;
	spi_mast_tran_byte(0x9f);
	spi_mast_recv_byte();
	spi_mast_recv_byte();
	spi_mast_recv_byte();
	spi_mast_recv_byte();
	GPIOA->ODR |= GPIO_ODR_ODR4;

		delay_ms(100);
	}
}

