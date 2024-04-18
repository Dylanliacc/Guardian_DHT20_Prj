/*
 * @Author: dylan dylan3000dylan@gmail.com
 * @Date: 2024-04-18 14:10:03
 * @LastEditors: dylan dylan3000dylan@gmail.com
 * @LastEditTime: 2024-04-18 16:51:30
 * @FilePath: /uart_async_rxtxtasks/main/src/core.c
 * @Description: 主函数入口和全局初始化
 * 
 *  
 */

#include"core.h"

    
void app_main(void)
{
    void AT_server_init(void);
    xTaskCreate(rx_task, "uart_rx_task", 1024 * 2, NULL, configMAX_PRIORITIES - 1, NULL);
    xTaskCreate(tx_task, "uart_tx_task", 1024 * 2, NULL, configMAX_PRIORITIES - 2, NULL);
}
