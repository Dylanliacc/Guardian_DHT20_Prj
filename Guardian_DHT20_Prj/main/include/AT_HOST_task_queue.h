/*
 * @Author: dylan dylan3000dylan@gmail.com
 * @Date: 2024-04-18 16:52:03
 * @LastEditors: dylan dylan3000dylan@gmail.com
 * @LastEditTime: 2024-04-18 17:06:16
 * @FilePath: /uart_async_rxtxtasks/main/include/AT_HOST_task_queue.h
 * @Description: 
 * 
 *  
 */
#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#define MAX_CMD_SIZE 10
#define QUEUE_LENGTH 10
#define ITEM_SIZE sizeof(DataItem)

QueueHandle_t xQueueReceiveHandle;
QueueHandle_t xQueueSend;


