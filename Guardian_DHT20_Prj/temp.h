#ifndef AT_COMMANDS_H
#define AT_COMMANDS_H

#include <stdbool.h>
#include <stdint.h>

// 错误代码
typedef enum {
    AT_OK = 0,
    AT_ERROR,
    AT_INVALID_PARAM,
    AT_TIMEOUT
} AT_Status_t;

// AT命令处理函数原型
AT_Status_t AT_Test(void);
AT_Status_t AT_Echo(bool enable);
AT_Status_t AT_SetBaudRate(uint32_t baudRate);
AT_Status_t AT_Reset(void);
AT_Status_t AT_GetFirmwareVersion(char* version, uint32_t bufferSize);

#endif // AT_COMMANDS_H
