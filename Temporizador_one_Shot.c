#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#define LED_RED 12
#define LED_BLUE 11
#define LED_GREEN 13

#define BUTTON 5
bool led_on=false;
bool led_active = false;
absolute_time_t turn_off_time;

int64_t turn_off_callback(alarm_id_t id, void *user_data) {
 
        gpio_put(LED_BLUE,false);
     
    led_active = false;

    return 0;
}
int64_t turn_off_callback2(alarm_id_t id, void *user_data) {
 
        gpio_put(LED_RED,false);
     
    led_active = false;

    return 0;
}
int64_t turn_off_callback3(alarm_id_t id, void *user_data) {
 
        gpio_put(LED_GREEN,false);
     
    led_active = false;

    return 0;
}


   
   
  



int main(){
    stdio_init_all();
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

        struct repeating_timer timer;
        

    while (true) {
         if (gpio_get(BUTTON) == 0 && !led_active) {
            sleep_ms(50);

            if (gpio_get(BUTTON) == 0 && gpio_get(LED_RED)==0 && gpio_get(LED_BLUE)==0 && gpio_get(LED_GREEN)==0) {
                sleep_ms(1000);
                gpio_put(LED_RED, true);
                gpio_put(LED_BLUE,true);
                gpio_put(LED_GREEN,true);


                led_active = true;
                //  add_repeating_timer_ms(1000, repeating_timer_callback, NULL, &timer);
                add_alarm_in_ms(1000, turn_off_callback, NULL, false);
                add_alarm_in_ms(4000, turn_off_callback2, NULL, false);
                add_alarm_in_ms(7000, turn_off_callback3, NULL, false);

                
                  
            }
           
        }
    
    sleep_ms(10);

}
return 0;
}
