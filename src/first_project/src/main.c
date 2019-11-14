/*
 * main.c
 *
 *  Created on: Nov 7, 2019
 *      Author: Burmistr Oleg
 */


#include "main.h"
#include "CLOCK.h"
#include "GPIO.h"





int main (void){


//	volatile uint32_t counter = 0;
//	volatile uint32_t counter1 = 0;


	GPIO_Init();

	if (CLOCK_Init() == ERR_OK){

		/*GPIOC->ODR  set ODR13
		 * Turn on Led*/
		GPIOC->ODR |= GPIO_ODR_ODR13;

	}else{

		/*GPIOC->ODR  reset ODR13
		 * Turn off Led*/
		GPIOC->ODR &= ~GPIO_ODR_ODR13;

		//*(uint32_t*) (0x4001100C) = 0x00002000;
	}




	while (1){


//		for (counter = 0; counter < 65000; counter++)
//			for (counter1 = 0; counter1 < 10; counter1++)
//				;

		if ((GPIOA->IDR & GPIO_IDR_IDR0_Msk) == GPIO_IDR_IDR0){

			if( (GPIOC->ODR & GPIO_ODR_ODR13_Msk) != GPIO_ODR_ODR13){
				/*GPIOC->ODR  set ODR13*/
				GPIOC->ODR |=  GPIO_ODR_ODR13;
			}

		}else{

			if( (GPIOC->ODR & GPIO_ODR_ODR13_Msk) == GPIO_ODR_ODR13){
				/*GPIOC->ODR  reset ODR13*/
				GPIOC->ODR &=  ~GPIO_ODR_ODR13;
			}

		}


		/*GPIOC->ODR  toggle ODR13*/
		//GPIOC->ODR =  GPIOC->ODR ^ (0x01<<GPIO_ODR_ODR13_Pos);

		//*(uint32_t*) (0x4001100C) = *(uint32_t*) (0x4001100C)^(1<<13);

	}

	return 0;

}

