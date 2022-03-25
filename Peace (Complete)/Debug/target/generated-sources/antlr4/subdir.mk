################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../target/generated-sources/antlr4/PeaceBaseVisitor.cpp \
../target/generated-sources/antlr4/PeaceLexer.cpp \
../target/generated-sources/antlr4/PeaceParser.cpp \
../target/generated-sources/antlr4/PeaceVisitor.cpp 

OBJS += \
./target/generated-sources/antlr4/PeaceBaseVisitor.o \
./target/generated-sources/antlr4/PeaceLexer.o \
./target/generated-sources/antlr4/PeaceParser.o \
./target/generated-sources/antlr4/PeaceVisitor.o 

CPP_DEPS += \
./target/generated-sources/antlr4/PeaceBaseVisitor.d \
./target/generated-sources/antlr4/PeaceLexer.d \
./target/generated-sources/antlr4/PeaceParser.d \
./target/generated-sources/antlr4/PeaceVisitor.d 


# Each subdirectory must supply rules for building sources it contributes
target/generated-sources/antlr4/%.o: ../target/generated-sources/antlr4/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/katrina/eclipse-workspace/Pcl2CppMod" -I"/home/katrina/eclipse-workspace/Pcl2CppMod/target/generated-sources/antlr4" -I/usr/local/include/antlr4-runtime -I/home/katrina/Downloads/boost_1_69_0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


