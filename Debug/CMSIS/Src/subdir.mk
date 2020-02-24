################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/Src/system_stm32f3xx.c 

OBJS += \
./CMSIS/Src/system_stm32f3xx.o 

C_DEPS += \
./CMSIS/Src/system_stm32f3xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/Src/system_stm32f3xx.o: ../CMSIS/Src/system_stm32f3xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303VCTx -DSTM32 -DSTM32F3 -DDEBUG -c -I"D:/STUDENTS/startCmsisF303/CMSIS/Inc" -I"D:/STUDENTS/startCmsisF303/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/Src/system_stm32f3xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

