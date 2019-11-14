/*
 *	CLOCK.c
 *
 *  Created on: Nov 11, 2019
 *      Author: Burmistr Oleg
 */


#include "CLOCK.h"

#define FRECVENTE_HSI_RC 	8000000UL			//SYSCLK, using only HSI
#define FRECVENTE_HSE_PLL 	72000000UL			//SYSCLK, using HSE and multiplied by 9 with PLL

#define PRESCALER_FOR_1ms		1000UL
#define PRESCALER_FOR_1us		1000000UL

#define MAX_TIMEOUT				1UL


uint32_t CLOCK_Init(){

	uint32_t i32_FirstValue = 0UL;
	uint32_t i32_CurrentValue = 0UL;


	/*SysTick_Handler function will be called every 1 ms*/
	SysTick_Config(FRECVENTE_HSI_RC/PRESCALER_FOR_1ms );


	/*Check if HSI is set as source for SYSCLCK*/
	if ((RCC->CFGR & RCC_CFGR_SWS_Msk) == RCC_CFGR_SWS_HSI ){


		/*Set latency for SYSCLK more than 48MHz
		 * 000 Zero wait state, if 0 < SYSCLK<= 24 MHz
		 * 001 One wait state, if 24 MHz < SYSCLK <= 48 MHz
		 * 010 Two wait states, if 48 MHz < SYSCLK <= 72 MHz
		 * */
		FLASH->ACR |= FLASH_ACR_LATENCY_1;

		/*Set prescaler for APB divided by 2, Set as to not exceed more than 36 MHz*/
		RCC->CFGR |= RCC_CFGR_PPRE1_2;

		/*Set HSE as source for PLL*/
		RCC->CFGR |= RCC_CFGR_PLLSRC;

		/*Set multiplier factor for PLL
		 * 8MHz * 9 = 72MHz
		 * */
		RCC->CFGR |= RCC_CFGR_PLLMULL9;

		/*Enable HSE*/
		RCC->CR |= RCC_CR_HSEON;

		/*Taken value of SysTick for calculation TIMEOUT*/
		i32_FirstValue = SysTick->VAL;

		/*Wait until HSE will be ready*/
		while (!(RCC->CR & RCC_CR_HSERDY) ){

			/*In case of timeout, return error*/
			i32_CurrentValue = SysTick->VAL - i32_FirstValue;
			if(i32_CurrentValue > MAX_TIMEOUT)
			return ERR_TIMEOUT;
		}

		/*Enable Clock security system */
		RCC->CR |= RCC_CR_CSSON;

		/*Enable PLL*/
		RCC->CR |= RCC_CR_PLLON;

		/*Taken value of SysTick for calculation TIMEOUT*/
		i32_FirstValue = SysTick->VAL;

		/*Wait until PLL will be ready*/
		while (!(RCC->CR & RCC_CR_PLLRDY) ){

			/*In case of timeout, return error*/
			i32_CurrentValue = SysTick->VAL - i32_FirstValue;
			if(i32_CurrentValue > MAX_TIMEOUT)
			return ERR_TIMEOUT;

		}


		/*Configure PLL as source for SYSCLK*/
		RCC->CFGR |= RCC_CFGR_SW_1;

		/*SysTick_Handler function will be called every 1 ms*/
		SysTick_Config(FRECVENTE_HSE_PLL/PRESCALER_FOR_1ms );
		return ERR_OK;
	}else{

		return ERR_NO_SUPPORT;
	}




}



void SysTick_Handler()
{

	static uint32_t li32_counter=PRESCALER_FOR_1ms;

	if (0ul < li32_counter){
		li32_counter--;
	}else{
	/*GPIOC->ODR  toggle ODR13*/
	GPIOC->ODR =  GPIOC->ODR ^ GPIO_ODR_ODR13;
	li32_counter = PRESCALER_FOR_1ms;
	}



}
