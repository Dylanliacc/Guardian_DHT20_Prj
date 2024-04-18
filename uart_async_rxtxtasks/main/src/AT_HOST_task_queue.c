/*
 * @Author: dylan dylan3000dylan@gmail.com
 * @Date: 2024-04-18 16:52:10
 * @LastEditors: dylan dylan3000dylan@gmail.com
 * @LastEditTime: 2024-04-18 17:07:15
 * @FilePath: /uart_async_rxtxtasks/main/src/AT_HOST_task_queue.c
 * @Description: 
 * 
 *  
 */

#include "AT_HOST_task_queue.h"


void setup_queues() {
    // 创建接收队列
    xQueueReceiveHandle = xQueueCreate(QUEUE_LENGTH, MAX_CMD_SIZE * sizeof(char));
    if (xQueueReceiveHandle == NULL) {
        // 处理错误：队列创建失败
        // 可以通过设置错误标志、重试或停止系统等方式处理
    }

    // 创建发送队列
    xQueueSend = xQueueCreate(QUEUE_LENGTH, MAX_CMD_SIZE * sizeof(char));
    if (xQueueSend == NULL) {
        // 处理错误：队列创建失败
    }
}