# Raspberry Pi Pico C++ Example Code   
This is an example code to code Raspberry pi pico in C++    
It simply retrieve data from DS3231 RTC and displays date and time on 1602 LCD  
Raspberry Pi PicoのサンプルC++プロジェクトです。DS3231からの時刻データを1602に表示するだけです  

## Hardware Setup
Connect your 1602 display, and SSD3231 to i2c1 port  
In this example, connection was made as follows:  
このサンプルでは、下記の様にブレッドボード上にSSD3231/1602を配置しました  

```
SDA->GP14(pin 19)  
SCL->GP15(pin 20)  
GND->GND  
VCC->3V3(OUT)  
```
![alt text](https://github.com/ta98otani/RPi-Pico-DS3231_LCD1602/blob/master/DS3231_LCD1602.jpeg?raw=true)  

Hardware was purchased from Amazon as below:   
1602 Display   
https://www.amazon.co.jp/gp/product/B07B24PD33/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1  
I2C Serial Interface for 1602
https://www.amazon.co.jp/gp/product/B07LBMPNCC/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1  
DS3231 RTC  
https://www.amazon.co.jp/gp/product/B01H5NAFUY/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1  

## Software
Please make sure you have pico-sdk installed with necessary environment setup  
```
git clone https://github.com/raspberrypi/pico-sdk.git  
```

For this example, use following     
```
git clone https://github.com/ta98otani/RPi-Pico-DS3231_LCD1602.git   
```

--------  
Takuya Otani  


