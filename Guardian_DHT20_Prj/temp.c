/*
 * @Author: dylan dylan3000dylan@gmail.com
 * @Date: 2024-04-18 14:51:33
 * @LastEditors: dylan dylan3000dylan@gmail.com
 * @LastEditTime: 2024-04-18 14:52:16
 * @FilePath: /uart_async_rxtxtasks/temp.c
 * @Description: 
 * 
 *  
 */
#include "at_commands.h"
#include "serial.h"  // 假设这是用来处理串口读写的自定义库

// 测试AT启动
AT_Status_t AT_Test(void) {
    serial_write("AT\r\n");
    char response[100];
    if (serial_read(response, sizeof(response), 1000) == 0) {
        if (strcmp(response, "OK\r\n") == 0) {
            return AT_OK;
        }
    }
    return AT_ERROR;
}

// 开启/关闭回显
AT_Status_t AT_Echo(bool enable) {
    if (enable) {
        serial_write("ATE1\r\n");
    } else {
        serial_write("ATE0\r\n");
    }
    char response[100];
    if (serial_read(response, sizeof(response), 1000) == 0) {
        if (strcmp(response, "OK\r\n") == 0) {
            return AT_OK;
        }
    }
    return AT_ERROR;
}

// 设置波特率
AT_Status_t AT_SetBaudRate(uint32_t baudRate) {
    char command[50];
    snprintf(command, sizeof(command), "AT+BAUD=%lu\r\n", baudRate);
    serial_write(command);
    char response[100];
    if (serial_read(response, sizeof(response), 1000) == 0) {
        if (strcmp(response, "OK\r\n") == 0) {
            return AT_OK;
        }
    }
    return AT_ERROR;
}

// 重启模块
AT_Status_t AT_Reset(void) {
    serial_write("AT+RST\r\n");
    // 假设重启命令没有立即回复
    return AT_OK;
}

// 查询固件版本
AT_Status_t AT_GetFirmwareVersion(char* version, uint32_t bufferSize) {
    serial_write("AT+GMR\r\n");
    char response[100];
    if (serial_read(response, sizeof(response), 1000) == 0) {
        strncpy(version, response, bufferSize);
        return AT_OK;
    }
    return AT_ERROR;
}
