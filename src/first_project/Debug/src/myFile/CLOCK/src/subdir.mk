################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/myFile/CLOCK/src/CLOCK.c 

OBJS += \
./src/myFile/CLOCK/src/CLOCK.o 

C_DEPS += \
./src/myFile/CLOCK/src/CLOCK.d 


# Each subdirectory must supply rules for building sources it contributes
src/myFile/CLOCK/src/%.o: ../src/myFile/CLOCK/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -I"D:/Oleg_Workspace/traning/git/STM32F103C8T6/src/first_project/src/inc/Incude" -I"D:/Oleg_Workspace/traning/git/STM32F103C8T6/src/first_project/src/inc/Device/ST/STM32F1xx/Include" -I"D:/Oleg_Workspace/traning/git/STM32F103C8T6/src/first_project/src/inc" -I"D:/Oleg_Workspace/traning/git/STM32F103C8T6/src/first_project/src/myFile/CLOCK/inc" -I"D:/Oleg_Workspace/traning/git/STM32F103C8T6/src/first_project/src/myFile/CLOCK/src" -I"D:/Oleg_Workspace/traning/git/STM32F103C8T6/src/first_project/src/myFile/GPIO/inc" -I"D:/Oleg_Workspace/traning/git/STM32F103C8T6/src/first_project/src/myFile/GPIO/src" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


