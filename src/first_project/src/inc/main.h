/*
 * main.h
 *
 *  Created on: Nov 7, 2019
 *      Author: Burmistr Oleg
 */

#ifndef MAIN_H_
#define MAIN_H_


#include "stm32f103xb.h"




typedef signed char		   	int8_t;
typedef unsigned char	   	uint8_;
typedef signed short	   	int16_t;
typedef unsigned short	   	uint16;
typedef signed long		   	int32;
typedef unsigned long	   	uint32_t;
typedef signed long	long   	int64;
typedef unsigned long long 	uint64;


typedef enum{

	ERR_OK = 0UL,
	ERR_TIMEOUT,
	ERR_NO_SUPPORT,
	ERR_ROUGH

}ERROR;

#endif /* MAIN_H_ */
