#ifndef __SIM900_H__
#define __SIM900_H__

#include <SoftwareSerial.h>
#include <Arduino.h>

#define DEFAULT_TIMEOUT     		 5 
#define DEFAULT_INTERCHAR_TIMEOUT 3000 

#define DEBUG(x)

enum DataType {
    CMD     = 0,
    DATA    = 1,
};

void  sim900_init(void* uart_device, uint32_t baud);
int   sim900_check_readable();
int   sim900_wait_readable(int wait_time);
void  sim900_flush_serial();
void  sim900_read_buffer(char* buffer, int count,  unsigned int timeout = DEFAULT_TIMEOUT,
                         unsigned int chartimeout = DEFAULT_INTERCHAR_TIMEOUT);


char* sim900_read_string_until(char* buffer, uint16_t count, const char* pattern,
                               unsigned int timeout = DEFAULT_TIMEOUT, unsigned int chartimeout = DEFAULT_INTERCHAR_TIMEOUT);
void  sim900_clean_buffer(char* buffer, int count);
void  sim900_send_byte(uint8_t data);
void  sim900_send_char(const char c);
void  sim900_send_cmd(const char* cmd);
void  sim900_send_cmd(const __FlashStringHelper* cmd);
void  sim900_send_cmd_P(const char* cmd);
boolean  sim900_send_AT(void);
void  sim900_send_End_Mark(void);
boolean  sim900_wait_for_resp(const char* resp, DataType type, unsigned int timeout = DEFAULT_TIMEOUT,
                              unsigned int chartimeout = DEFAULT_INTERCHAR_TIMEOUT);
boolean  sim900_check_with_cmd(const char* cmd, const char* resp, DataType type, unsigned int timeout = DEFAULT_TIMEOUT,
                               unsigned int chartimeout = DEFAULT_INTERCHAR_TIMEOUT * 5);
boolean  sim900_check_with_cmd(const __FlashStringHelper* cmd, const char* resp, DataType type,
                               unsigned int timeout = DEFAULT_TIMEOUT, unsigned int chartimeout = DEFAULT_INTERCHAR_TIMEOUT);
void sim900_AT_bypass();

#endif