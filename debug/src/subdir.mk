################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/advanceBuffer.cpp \
../src/clearAllBuffers.cpp \
../src/parser.cpp \
../src/printHeaders.cpp \
../src/printSessionList.cpp \
../src/processInput.cpp \
../src/processLine.cpp \
../src/readHeadersIntoMemory.cpp \
../src/readfile.cpp \
../src/run.cpp \
../src/setIntensiveFlag.cpp \
../src/vlbi-sessions.cpp 

CPP_DEPS += \
./src/advanceBuffer.d \
./src/clearAllBuffers.d \
./src/parser.d \
./src/printHeaders.d \
./src/printSessionList.d \
./src/processInput.d \
./src/processLine.d \
./src/readHeadersIntoMemory.d \
./src/readfile.d \
./src/run.d \
./src/setIntensiveFlag.d \
./src/vlbi-sessions.d 

OBJS += \
./src/advanceBuffer.o \
./src/clearAllBuffers.o \
./src/parser.o \
./src/printHeaders.o \
./src/printSessionList.o \
./src/processInput.o \
./src/processLine.o \
./src/readHeadersIntoMemory.o \
./src/readfile.o \
./src/run.o \
./src/setIntensiveFlag.o \
./src/vlbi-sessions.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../inc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/advanceBuffer.d ./src/advanceBuffer.o ./src/clearAllBuffers.d ./src/clearAllBuffers.o ./src/parser.d ./src/parser.o ./src/printHeaders.d ./src/printHeaders.o ./src/printSessionList.d ./src/printSessionList.o ./src/processInput.d ./src/processInput.o ./src/processLine.d ./src/processLine.o ./src/readHeadersIntoMemory.d ./src/readHeadersIntoMemory.o ./src/readfile.d ./src/readfile.o ./src/run.d ./src/run.o ./src/setIntensiveFlag.d ./src/setIntensiveFlag.o ./src/vlbi-sessions.d ./src/vlbi-sessions.o

.PHONY: clean-src

