# RTOSComponentExample
Example for using the RTOS Component Library: https://github.com/jondurrant/RtosComponents

C++ for the [Raspberry PI Pico RP2040](https://raspberrypi.github.io/pico-sdk-doxygen/index.html)

## Dependencies
+ [RTOSComponent](https://github.com/jondurrant/RtosComponents)
+ [FreeRTOS Core](https://www.freertos.org/index.html)
[Raspberry Pico SDK](https://raspberrypi.github.io/pico-sdk-doxygen/index.html)
++ [Watchdog](https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__watchdog.html)
++ [PWM] (https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__pwm.html)


## Code Structure
+ Main.cpp - simple main program to test the library. Makes use of an init task
which then starts the other agents tasks.
+ Port folder contains the porting configuration for FreeRTOS.  
+ Git submodules used to link the other code.

## Clone and build
```
git clone --recurse-submodules https://github.com/jondurrant/RTOSComponentExample
cd RTOSComponentExample
mkdir build
cd build
cmake ..
make
make install #Requires utility in ~/bin to write binary to the Pico via SWD. You could copy via the Bootsel method
```
