################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../__MACOSX/._Pcl2.cpp 

OBJS += \
./__MACOSX/._Pcl2.o 

CPP_DEPS += \
./__MACOSX/._Pcl2.d 


# Each subdirectory must supply rules for building sources it contributes
__MACOSX/%.o: ../__MACOSX/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/home/jasper/Downloads/boost_1_70_0 -I"/home/jasper/eclipse-workspace/Pcl2Cpp" -I/usr/local/include/antlr4-runtime -I"/home/jasper/eclipse-workspace/Pcl2Cpp/target/generated-sources/antlr4" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


