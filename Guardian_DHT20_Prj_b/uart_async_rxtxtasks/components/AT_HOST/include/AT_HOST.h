/*
 * @Author: dylan dylan3000dylan@gmail.com
 * @Date: 2024-04-18 14:41:08
 * @LastEditors: dylan dylan3000dylan@gmail.com
 * @LastEditTime: 2024-04-18 15:19:02
 * @FilePath: /uart_async_rxtxtasks/components/AT_HOST/include/AT_HOST.h
 * @Description: 
 * AT指令集实现区，AT指令状态编码
 * 
 *  
 */
#ifndef AT_HOST
#ifndef AT_HOST_Enable          //AT指令开启
#include<stdint.h>
#include<stdbool.h>
#include<toolbox.h>
//状态编码

typedef enum{
    AT_OK = 0,
    AT_ERROR,
    AT_INVALID_PARAM,
    AT_TIMEOUT
} AT_Status_t;


/**
 * @description:        AT指令测试
 * @return {*       @type AT_Status_t}
 */
AT_Status_t AT_Test(void);          

/**
 * @description:    AT指令回响
 * @param {bool} enable 回响使能
 * @return {*    @type AT_Status_t}
 */
AT_Status_t AT_Echo(bool enable);

/**
 * @description:   温湿度回馈  
 * @param {bool} enable
 * @return {*   @type AT_Status_t}
 */
AT_Status_t AT_TempHumidityFeedback(bool enable);
/**
 * @description:    温度回馈
 * @param {bool} enable
 * @return {*   @type AT_Status_t}
 */  
AT_Status_t AT_TempFeedback(bool enable); 
/**
 * @description:    湿度回馈
 * @param {bool} enable
 * @return {*   @type AT_Status_t}
 */  
AT_Status_t AT_HumidityFeedback(bool enable);  

#endif
#endif