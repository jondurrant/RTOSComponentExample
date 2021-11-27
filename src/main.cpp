#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include <array>

#include "BlinkAgent.h"
#include "WatchdogBlinkAgent.h"


void
init_thread(void* pvParameters) {

	BlinkAgent blink;
	WatchdogBlinkAgent watchdog;

	watchdog.start();


    for (unsigned int i=0; i < 100; i++){
    	if (i == 10){
    		printf("Stopping watchdog and starting blink\n");
    		watchdog.stop();
    		blink.start();
    	}

    	printf("Blink Stack %d\n", blink.getStakHighWater());
    	printf("Watchdog Stack %d\n", watchdog.getStakHighWater());
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
