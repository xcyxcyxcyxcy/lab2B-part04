#include "pico/stdlib.h"
#include <stdio.h>
#include "stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
#include <math.h>
#include "neopixel.h"  


#define QTPY_BOOT_PIN 21
void record(bool arr[],int seconds,char sdir)
{
    stdio_init_all();                                           //Initialization functions
    int cnt=0;
    neopixel_set_rgb(0x00ff00ff);
    int div;
    int speed;                                                 //speedx slower, if speed=4, it will play 4x slower
    switch(sdir){
      case 'a'  : //Mode 0
      speed = 1;
      div=1;
      break; 
	
      case 'b'  : //Mode 1
      speed = 2;
      div=1;
      break; 

      case 'c'  : //Mode 2
      speed = 4;
      div=1;
      break; 

      case 'd'  : //Mode 3
      speed = 1;
      div=2;
      break; 

      case 'e'  : //Mode 4
      speed = 1;
      div=4;
      break; 
    
   default : 
    speed = 1;
    div=1;
    }
    while(true)
    {   
        if(!(gpio_get(QTPY_BOOT_PIN))){
            arr[cnt]=true;
            
            sleep_ms(floor((5*speed)/div));
        }
        else{                                                   // If BOOT button is not pressed
        arr[cnt]=false;
        sleep_ms(floor((5*speed)/div));
        }
        cnt=cnt+1;
        if(cnt>=((seconds*1000)-2))
        {
            cnt=0;
            neopixel_set_rgb(0x00000000);
            break;
        }
    }
}


void play(bool arr[], int seconds, char color, char sdir)
{
  stdio_init_all();                                            
    uint32_t light_color;

    switch(color){
            case 'r':
                light_color = 0x00ff0000;
                break;
            case 'g':
                light_color = 0x0000ff00;
                break;
            case 'b':
                light_color = 0x000000ff;
                break;
                default : 
                light_color = 0x000000ff;
    
    }
    int div;
    int speed;                                                 //speedx slower, if speed=4, it will play 4x slower
    switch(sdir){
      case 'a'  : //Mode 0
      speed = 1;
      div=1;
      break; 
	
      case 'b'  : //Mode 1
      speed = 2;
      div=1;
      break; 

      case 'c'  : //Mode 2
      speed = 4;
      div=1;
      break; 

      case 'd'  : //Mode 3
      speed = 1;
      div=2;
      break; 

      case 'e'  : //Mode 4
      speed = 1;
      div=4;
      break; 
    
   default : 
    speed = 1;
    div=1;
    }

    for(int j=0;j<=seconds*1000;j=j+1)                             
            {
                if(arr[j]==true)
                {
                     neopixel_set_rgb(light_color);
                    sleep_ms(floor((5*speed)/div));
                }

                else
                {
                    neopixel_set_rgb(0x00000000);
                    sleep_ms(floor((5*speed)/div));
                }
            }

neopixel_set_rgb(0x00000000);
}


void loopplay(bool arr[], int seconds, char color, char sdir)
{
  stdio_init_all();                                            
    uint32_t light_color;
    char c = 0;
    switch(color){
            case 'r':
                light_color = 0x00ff0000;
                break;
            case 'g':
                light_color = 0x0000ff00;
                break;
            case 'b':
                light_color = 0x000000ff;
                break;
                default : 
                light_color = 0x000000ff;
    
    }
    int div;
    int speed;                                                 //speedx slower, if speed=4, it will play 4x slower
    switch(sdir){
      case 'a'  : //Mode 0
      speed = 1;
      div=1;
      break; 
	
      case 'b'  : //Mode 1
      speed = 2;
      div=1;
      break; 

      case 'c'  : //Mode 2
      speed = 4;
      div=1;
      break; 

      case 'd'  : //Mode 3
      speed = 1;
      div=2;
      break; 

      case 'e'  : //Mode 4
      speed = 1;
      div=4;
      break; 
    
   default : 
    speed = 1;
    div=1;
    }

    int x = 0;

    for(int x=0;x<2;x=x+1)     
    { 
    for(int j=0;j<=seconds*1000;j=j+1)                             
            {
            
                if(arr[j]==true)
                {
                     neopixel_set_rgb(light_color);
                    sleep_ms(floor((5*speed)/div));
                }

                else
                {
                    neopixel_set_rgb(0x00000000);
                    sleep_ms(floor((5*speed)/div));
                }
            }
        
    }

neopixel_set_rgb(0x00000000);
}