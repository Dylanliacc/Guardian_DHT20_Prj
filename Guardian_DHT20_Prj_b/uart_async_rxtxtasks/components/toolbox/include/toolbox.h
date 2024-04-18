/*
 * @Author: dylan dylan3000dylan@gmail.com
 * @Date: 2024-04-18 11:28:44
 * @LastEditors: dylan dylan3000dylan@gmail.com
 * @LastEditTime: 2024-04-18 16:06:33
 * @FilePath: /uart_async_rxtxtasks/components/toolbox/include/toolbox.h
 * @Description: 
 * 
 *  
 */
#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <rom/ets_sys.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "driver/i2c.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "esp_err.h"
#include "sdkconfig.h"
#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_TOOLBOX_ENABLED
#ifdef CONFIG_ENABLE_I2C
#define I2C_MASTER_PORT     CONFIG_I2C_PORT_NUM
#define I2C_GPIO_SCL        CONFIG_I2C_GPIO_SCL
#define I2C_GPIO_SDA        CONFIG_I2C_GPIO_SDA

#ifndef CONFIG_I2C_GPIO_SCL_PULLUP
#define I2C_GPIO_SCL_PULLUP 0
#else
#define I2C_GPIO_SCL_PULLUP 1
#endif

#ifndef CONFIG_I2C_GPIO_SDA_PULLUP
#define I2C_GPIO_SDA_PULLUP 0
#else
#define I2C_GPIO_SDA_PULLUP 1
#endif

#define I2C_BUS_SPEED   CONFIG_I2C_MASTER_FREQUENCY
#define I2C_CMD_TIMEOUT CONFIG_I2C_BUS_TIMEOUT
#else
#error "666 shit happens"
#endif


#ifdef CONFIG_ENABLE_AT_HOST_UART
#define AT_HOST_name CONFIG_AT_HOST_name
#define AT_HOST_UART_BAUD_RATE  CONFIG_AT_HOST_UART_BAUD_RATE
#define AT_HOST_UART_RX_PIN     CONFIG_AT_HOST_UART_RX_PIN
#define AT_HOST_UART_TX_PIN     CONFIG_AT_HOST_UART_TX_PIN
#define AT_HOST_UART_RX_BUFFER_SIZE CONFIG_AT_HOST_UART_RX_BUFFER_SIZE
#define AT_T_HOST_UART_TX_BUFFER_SIZE   CONFIG_AT_HOST_UART_TX_BUFFER_SIZE
//@Dylanliacc @@TODO@@
//太多了不写了先用系统值不用自定义值了，先能用就行后面再来补
#endif

#endif

#define millis()    ( esp_timer_get_time() / 1000 )

/* ** i2c helpers ** */
esp_err_t _i2c_init(void);
//void i2c_read(uint8_t i2c_addr, uint8_t *read_buffer, size_t read_size);
esp_err_t i2c_read(uint8_t i2c_addr, uint8_t *read_buffer, size_t read_size);
//void i2c_write(uint8_t i2c_addr, uint8_t *write_buffer, size_t write_size);
esp_err_t i2c_write(uint8_t i2c_addr, uint8_t *write_buffer, size_t write_size);
void i2c_write_read(uint8_t i2c_addr, uint8_t read_reg, uint8_t *read_buffer, size_t read_size, uint16_t delayms);
/* ** tools ** */
char *print_binary(uint16_t value);
char *print_byte(uint8_t byte);

/* **** useful Arduino Functions ***** */
double map(double x, double in_min, double in_max, double out_min, double out_max);

uint8_t bcd2dec(uint8_t val);
uint8_t dec2bcd(uint8_t val);


/**AT_HOST_UART*/
void _AT_HOST_init(void);
int sendData(const char* logName, const char* data);


#ifdef __cplusplus
}
#endif