/*
 * This is a sample code for Raspberry Pi Pico 
 * Read data from DS3231 RTC, and display the result on 1602 display 
 * Assuming i2c1 port (pin 14 and 15) are used. 
 *
 * 1602 code is based on pico-examples. Modified to use C++ classes
 * Original code is found in:  https://github.com/raspberrypi/pico-examples
 *  
 * Copyright Takuya Otani
 * mailto:ta98otani@gmail.com
 */

#include <stdio.h>
#include "ds3231.hpp"
#include "lcd1602.hpp"
#include "pico/stdlib.h"

int main() 
{

    stdio_init_all();

    // This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
    i2c_init(i2c1, 100 * 1000);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);
    gpio_pull_up(14);
    gpio_pull_up(15);

    //Instanciate and initialize DS3231 (Default bus address 0x68)
    DS3231 rtc(i2c1, 0x68);
    
    //Instanciate and initialize 1602A display. (Default bus address 0x27)
    LCD1602 lcd(i2c1, 0x27);
    char dateNow[40];
    char timeNow[40];

/*

    //Uncomment lines below to reset the RTC clock
    //Comment again for normal operation
    bool clockInit = true;

    if (clockInit) {
        //RESET the clock 
        //Notice: need to represent with "0x" becuase DS3231 uses BCD format
        rtc.setYear(0x21);
        rtc.setMonth(0x5);
        rtc.setDay(0x5);
        rtc.setDayOfWeek(0x4);
        rtc.setHour(0x21);
        rtc.setMin(0x03);
        rtc.setSec(0x0);
    }
*/

    while (1) {

        rtc.readTime();
        sprintf(dateNow, "20%02x/%02x/%02x (%s)",rtc.currentYear(), rtc.currentMonth(), rtc.currentDay(), rtc.currentWeek());
        sprintf(timeNow, "%02x:%02x:%02x",rtc.currentHour(), rtc.currentMin(), rtc.currentSec());

        lcd.set_cursor(0,0);
        lcd.string(dateNow);
        lcd.set_cursor(1,0);
        lcd.string(timeNow);
        
        sleep_ms(1000);
        lcd.clear();
    }

    return 0;
}
