################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/util/CrossReferencer.cpp \
../wci/util/ParseTreePrinter.cpp 

OBJS += \
./wci/util/CrossReferencer.o \
./wci/util/ParseTreePrinter.o 

CPP_DEPS += \
./wci/util/CrossReferencer.d \
./wci/util/ParseTreePrinter.d 


# Each subdirectory must supply rules for building sources it contributes
wci/util/%.o: ../wci/util/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/katrina/eclipse-workspace/Pcl2CppMod" -I"/home/katrina/eclipse-workspace/Pcl2CppMod/target/generated-sources/antlr4" -I/usr/local/include/antlr4-runtime -I/home/katrina/Downloads/boost_1_69_0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


