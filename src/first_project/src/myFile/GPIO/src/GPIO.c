/*
 * GPIO.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Burmist Oleg
 */


#include "GPIO.h"



uint32_t GPIO_Init(){


		volatile uint32_t counter = 0;

		//RCC->APB2ENR  set IOPCEN
		RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN;
		RCC->APB2ENR |=  RCC_APB2ENR_IOPAEN;

		//*(uint32_t*) (0x40021018) = 0x00000010;


		/*delay for stabilize clock in peripheries*/
		counter++;
		counter++;
		counter++;
		counter++;
		counter = 0;

		/*GPIOC->CRH->MODE13 == 11: Ouput mode, max speed 50 MHz*/
		GPIOC->CRH |= GPIO_CRH_MODE13;

		/*GPIOC->CRH->CNF13 == 00: General purpose output push-pull*/
		GPIOC->CRH &= ~(0x1UL<<GPIO_CRH_CNF13_Pos);

		//*(uint32_t*) (0x40011004) = 0x44344444;

		/*GPIOA->CRL->MODE0 ==  00: Input mode (reset state)*/
		GPIOA->CRL &= ~GPIO_CRL_MODE0;

		/*GPIOA->CRL->CNF0 == 01: Floating input (reset state)*/
		GPIOA->CRL |= GPIO_CRL_CNF0_0;


	return ERR_OK;
}
