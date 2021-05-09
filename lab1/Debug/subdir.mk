################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AllTests.c \
../CuTest.c \
../Questions.c \
../testCases.c 

OBJS += \
./AllTests.o \
./CuTest.o \
./Questions.o \
./testCases.o 

C_DEPS += \
./AllTests.d \
./CuTest.d \
./Questions.d \
./testCases.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


