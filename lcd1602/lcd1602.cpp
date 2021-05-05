/*
 * This is a sample code for Raspberry Pi Pico 
 * Displays to 1602 LCD
 * 1602 code is based on pico-examples. Modified to use C++ classes
 * Original code is found in:  https://github.com/raspberrypi/pico-examples
 *  
 * Copyright Takuya Otani
 * mailto:ta98otani@gmail.com
 */

#include "lcd1602.hpp"

LCD1602::LCD1602(i2c_inst_t *i2c, uint8_t i2c_address) {

    this->i2c = i2c;
    this->i2c_address = i2c_address;

    send_byte(0x03, LCD_COMMAND);
    send_byte(0x03, LCD_COMMAND);
    send_byte(0x03, LCD_COMMAND);
    send_byte(0x02, LCD_COMMAND);

    send_byte(LCD_ENTRYMODESET | LCD_ENTRYLEFT, LCD_COMMAND);
    send_byte(LCD_FUNCTIONSET | LCD_2LINE, LCD_COMMAND);
    send_byte(LCD_DISPLAYCONTROL | LCD_DISPLAYON, LCD_COMMAND);
    clear();
}

/* Quick helper function for single byte transfers */
void LCD1602::i2c_write_byte(uint8_t val) {
    i2c_write_blocking(this->i2c, this->i2c_address, &val, 1, false);
}

void LCD1602::toggle_enable(uint8_t val) {
    // Toggle enable pin on LCD display
    // We cannot do this too quickly or things don't work
#define DELAY_US 600
    sleep_us(DELAY_US);
    i2c_write_byte(val | LCD_ENABLE_BIT);
    sleep_us(DELAY_US);
    i2c_write_byte(val & ~LCD_ENABLE_BIT);
    sleep_us(DELAY_US);
}

// The display is sent a byte as two separate nibble transfers
void LCD1602::send_byte(uint8_t val, int mode) {
    uint8_t high = mode | (val & 0xF0) | LCD_BACKLIGHT;
    uint8_t low = mode | ((val << 4) & 0xF0) | LCD_BACKLIGHT;

    i2c_write_byte(high);
    toggle_enable(high);
    i2c_write_byte(low);
    toggle_enable(low);
}

void LCD1602::clear(void) {
    send_byte(LCD_CLEARDISPLAY, LCD_COMMAND);
}

// go to location on LCD
void LCD1602::set_cursor(int line, int position) {
    int val = (line == 0) ? 0x80 + position : 0xC0 + position;
    send_byte(val, LCD_COMMAND);
}

void LCD1602::string(char *s) {
    while (*s) {
        send_byte(*s++, LCD_CHARACTER);
    }
}

