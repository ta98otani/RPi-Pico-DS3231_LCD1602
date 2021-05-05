/*
 * This is a sample code for Raspberry Pi Pico 
 * Read data from DS3231 RTC
 *
 * Copyright Takuya Otani
 * mailto:ta98otani@gmail.com
 */

#include "ds3231.hpp"

DS3231::DS3231(i2c_inst_t *i2c, uint8_t i2c_address) 
{
	this->i2c = i2c;
  this->i2c_address = i2c_address;
}

void DS3231::setYear(uint8_t year)
{
	uint8_t buf[2];
	buf[0] = 0x06;
	buf[1] = year;  
	i2c_write_blocking(this->i2c,this->i2c_address,buf,2,false);
}

void DS3231::setMonth(uint8_t month)
{
	uint8_t buf[2];
	buf[0] = 0x05;
	buf[1] = month; 
	i2c_write_blocking(this->i2c,this->i2c_address,buf,2,false);
}

void DS3231::setDay(uint8_t day)
{
	uint8_t buf[2];
	buf[0] = 0x04;
	buf[1] = day; 
	i2c_write_blocking(this->i2c,this->i2c_address,buf,2,false);
}

void DS3231::setDayOfWeek(uint8_t dayOfWeek)
{
	uint8_t buf[2];
	buf[0] = 0x03;
	buf[1] = dayOfWeek; 
	i2c_write_blocking(this->i2c,this->i2c_address,buf,2,false);
}

void DS3231::setHour(uint8_t hour)
{
	uint8_t buf[2];
	buf[0] = 0x02;
	buf[1] = hour; 
	i2c_write_blocking(this->i2c,this->i2c_address,buf,2,false);
}

void DS3231::setMin(uint8_t min)
{
	uint8_t buf[2];
	buf[0] = 0x01;
	buf[1] = min; 
	i2c_write_blocking(this->i2c,this->i2c_address,buf,2,false);
}


void DS3231::setSec(uint8_t sec)
{
	uint8_t buf[2];
	buf[0] = 0x00;
	buf[1] = sec; 
	i2c_write_blocking(this->i2c,this->i2c_address,buf,2,false);
}

void DS3231::readTime() 
{   
	uint8_t val = 0x00;  
	i2c_write_blocking(this->i2c,this->i2c_address,&val,1,true);
	i2c_read_blocking(this->i2c,this->i2c_address, this->dateTime,7,false);
} 

uint8_t DS3231::currentYear()
{
	return this->dateTime[6];
}

uint8_t DS3231::currentMonth()
{
	return this->dateTime[5]&0x1F;
}

uint8_t DS3231::currentDay()
{
	return this->dateTime[4]&0x3F;
}

char *DS3231::currentWeek()
{
	const char* week[]  ={"SUN","Mon","Tue","Wed","Thur","Fri","Sat"};
	return (char *)week[(unsigned char)this->dateTime[3]-1];
}

uint8_t DS3231::currentHour()
{
	return this->dateTime[2]&0x3F;
}

uint8_t DS3231::currentMin()
{
	return this->dateTime[1]&0x7F;
}

uint8_t DS3231::currentSec()
{
	return this->dateTime[0]&0x7F;
}
