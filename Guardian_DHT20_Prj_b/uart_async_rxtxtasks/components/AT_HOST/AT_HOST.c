/*
 * @Author: dylan dylan3000dylan@gmail.com
 * @Date: 2024-04-18 14:41:19
 * @LastEditors: dylan dylan3000dylan@gmail.com
 * @LastEditTime: 2024-04-18 16:15:33
 * @FilePath: /uart_async_rxtxtasks/components/AT_HOST/AT_HOST.c
 * @Description: 
 * 
 *  
 */
#include "AT_HOST.h"
#include "toolbox.h"
#include "dht20.h"


AT_Status_t AT_Test(void){
    return 0;
}


AT_Status_t AT_Echo(bool enable){
    return 0;
}

/*  
@todo: 1.调用ATsend函数进行回传
*/
AT_Status_t AT_TempHumidityFeedback(bool enable){
    return 0;
}

AT_Status_t AT_TempFeedback(bool enable){
     return 0;
}

AT_Status_t AT_HumidityFeedback(bool enable){
     return 0;
}