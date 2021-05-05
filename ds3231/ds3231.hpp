/*
 * This is a sample code for Raspberry Pi Pico 
 * Read data from DS3231 RTC
 *
 * Copyright Takuya Otani
 * mailto:ta98otani@gmail.com
 */

#pragma once

#include "hardware/i2c.h"

class DS3231 {

  private:
    i2c_inst_t *i2c;
    uint8_t i2c_address;

    //seconds,minutes,hours,weekdays,days,months,yeas
    uint8_t dateTime[7];

  public:

    DS3231(i2c_inst_t *i2c, uint8_t i2c_address);
    void setYear(uint8_t year);
    void setMonth(uint8_t month);
    void setDay(uint8_t day);
    void setDayOfWeek(uint8_t dayOfWeek);
    void setHour(uint8_t hour);
    void setMin(uint8_t min);    
    void setSec(uint8_t sec);    
    void readTime();
    uint8_t currentYear();
    uint8_t currentMonth();
    uint8_t currentDay();
    char *currentWeek();
    uint8_t currentHour();
    uint8_t currentMin();
    uint8_t currentSec();
};

