################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Affector.cpp \
../Emitter.cpp \
../FadeOutAffector.cpp \
../Particle.cpp \
../ParticleSystem.cpp \
../RandomColorAffector.cpp \
../Rocket.cpp \
../SmokeEmitter.cpp \
../main.cpp 

OBJS += \
./Affector.o \
./Emitter.o \
./FadeOutAffector.o \
./Particle.o \
./ParticleSystem.o \
./RandomColorAffector.o \
./Rocket.o \
./SmokeEmitter.o \
./main.o 

CPP_DEPS += \
./Affector.d \
./Emitter.d \
./FadeOutAffector.d \
./Particle.d \
./ParticleSystem.d \
./RandomColorAffector.d \
./Rocket.d \
./SmokeEmitter.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


