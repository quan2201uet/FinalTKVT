################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Src/BME280Task.cpp \
../Application/Src/GPSTask.cpp \
../Application/Src/IMUTask.cpp \
../Application/Src/LoraComunicationTask.cpp \
../Application/Src/MicroSDTask.cpp \
../Application/Src/PM25Task.cpp \
../Application/Src/common.cpp 

OBJS += \
./Application/Src/BME280Task.o \
./Application/Src/GPSTask.o \
./Application/Src/IMUTask.o \
./Application/Src/LoraComunicationTask.o \
./Application/Src/MicroSDTask.o \
./Application/Src/PM25Task.o \
./Application/Src/common.o 

CPP_DEPS += \
./Application/Src/BME280Task.d \
./Application/Src/GPSTask.d \
./Application/Src/IMUTask.d \
./Application/Src/LoraComunicationTask.d \
./Application/Src/MicroSDTask.d \
./Application/Src/PM25Task.d \
./Application/Src/common.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/%.o Application/Src/%.su Application/Src/%.cyclo: ../Application/Src/%.cpp Application/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/ProjectTKVT/FinalTKVT/projectTKVT/Application/Inc/Libs/sensor" -I"D:/ProjectTKVT/FinalTKVT/projectTKVT/Application/Inc/Libs" -I"D:/ProjectTKVT/FinalTKVT/projectTKVT/Application/Inc" -I"D:/ProjectTKVT/FinalTKVT/projectTKVT/Application" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src

clean-Application-2f-Src:
	-$(RM) ./Application/Src/BME280Task.cyclo ./Application/Src/BME280Task.d ./Application/Src/BME280Task.o ./Application/Src/BME280Task.su ./Application/Src/GPSTask.cyclo ./Application/Src/GPSTask.d ./Application/Src/GPSTask.o ./Application/Src/GPSTask.su ./Application/Src/IMUTask.cyclo ./Application/Src/IMUTask.d ./Application/Src/IMUTask.o ./Application/Src/IMUTask.su ./Application/Src/LoraComunicationTask.cyclo ./Application/Src/LoraComunicationTask.d ./Application/Src/LoraComunicationTask.o ./Application/Src/LoraComunicationTask.su ./Application/Src/MicroSDTask.cyclo ./Application/Src/MicroSDTask.d ./Application/Src/MicroSDTask.o ./Application/Src/MicroSDTask.su ./Application/Src/PM25Task.cyclo ./Application/Src/PM25Task.d ./Application/Src/PM25Task.o ./Application/Src/PM25Task.su ./Application/Src/common.cyclo ./Application/Src/common.d ./Application/Src/common.o ./Application/Src/common.su

.PHONY: clean-Application-2f-Src

