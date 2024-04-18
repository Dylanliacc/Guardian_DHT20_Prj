/*
 * @Author: dylan dylan3000dylan@gmail.com
 * @Date: 2024-04-18 15:28:52
 * @LastEditors: dylan dylan3000dylan@gmail.com
 * @LastEditTime: 2024-04-18 16:55:23
 * @FilePath: /uart_async_rxtxtasks/main/include/UART_process.h
 * @Description: 
 * 
 *  
 */
#pragma once
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include <portmacro.h>
#include "toolbox.h"

void tx_task(void *arg);

void rx_task(void *arg);
