#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include <array>

#include "BlinkAgent.h"
#include "WatchdogBlinkAgent.h"
#include "RGBLEDAgent.h"


void
init_thread(void* pvParameters) {

	BlinkAgent blink;
	WatchdogBlinkAgent watchdog;
	RGBLEDAgent led(3,4,5);

	watchdog.start();
	led.start();
	led.set(RGBModeOn, 0, 0xFF, 0);


    for (unsigned int i=0; i < 100; i++){
    	switch(i){
    	case 1:{
    		led.set(RGBModeOn,0, 0, 0xFF);
    		break;
    	}
    	case 2:{
    		led.set(RGBModeSlow, 0xff, 0xff, 0);
    		break;
    	}
    	case 3:{
    		led.set(RGBModeFast, 0, 0xff, 0xff);
			break;
		}
    	case 4:{
    		led.set(RGBModeFade, 0xff, 0xff, 0xff);
			break;
		}
    	case 5:{
    		led.set(RGBModeRainbow, 0, 0, 0);
			break;
		}
    	case 6:{
    		led.set(RGBModeOn, 0, 0, 0xff);
			break;
		}
    	case 7:{
    		led.set(RGBModeOnce, 0, 0, 0xff);
			break;
		}
    	case 8:{
			break;
    	}
    	case 9:{
			break;
		}
    	case 10:{
    		led.set(RGBModeSlow, 0xff, 0, 0);
			break;
		}
    	}
    	if (i == 10){
    		printf("Stopping watchdog and starting blink\n");
    		watchdog.stop();
    		blink.start();
    	}

    	printf("Blink Stack %d\n", blink.getStakHighWater());
    	printf("Watchdog Stack %d\n", watchdog.getStakHighWater());
    	printf("Led Stack %d\n", led.getStakHighWater());
    	vTaskDelay(5000);

    }
}



int main() {

	stdio_init_all();

	sleep_ms(3000);
	printf("******GO******\n");


    BaseType_t atReturned;
	TaskHandle_t atHandle = NULL;

	atReturned = xTaskCreate(
					init_thread,
					"Init task",
					512,
					( void * ) 1,
					tskIDLE_PRIORITY+1,
					&atHandle );




    vTaskStartScheduler();
    while(1)
    {
        configASSERT(0);    /* We should never get here */
    }

}
