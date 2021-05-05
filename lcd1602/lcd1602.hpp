/*
 * This is a sample code for Raspberry Pi Pico 
 * Displays to 1602 LCD
 * 1602 code is based on pico-examples. Modified to use C++ classes
 * Original code is found in:  https://github.com/raspberrypi/pico-examples
 *  
 * Copyright Takuya Otani
 * mailto:ta98otani@gmail.com
 */

#define once

#include "hardware/i2c.h"

// Modes for lcd_send_byte
#define LCD_CHARACTER  1
#define LCD_COMMAND    0

#define MAX_LINES      2
#define MAX_CHARS      16

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT  0x10
#define LCD_FUNCTIONSET  0x20
#define LCD_SETCGRAMADDR  0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYLEFT 0x02

// flags for display and cursor control
#define LCD_BLINKON   0x01
#define LCD_CURSORON  0x02
#define LCD_DISPLAYON 0x04

// flags for display and cursor shift
#define LCD_MOVERIGHT   0x04
#define LCD_DISPLAYMOVE 0x08

// flags for function set
#define LCD_5x10DOTS  0x04
#define LCD_2LINE  0x08
#define LCD_8BITMODE 0x10

// flag for backlight control
#define LCD_BACKLIGHT 0x08

#define LCD_ENABLE_BIT 0x04


class LCD1602 {

  private:
    i2c_inst_t *i2c;
    uint8_t i2c_address;
    
    /* Quick helper function for single byte transfers */
    void i2c_write_byte(uint8_t val);
    void toggle_enable(uint8_t val);

    // The display is sent a byte as two separate nibble transfers
    void send_byte(uint8_t val, int mode);

  public:
    LCD1602(i2c_inst_t *i2c, uint8_t i2c_address);
    // go to location on LCD
    void set_cursor(int line, int position);
    void string(char *s);
    void clear(void);
};

