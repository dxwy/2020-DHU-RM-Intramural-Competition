/**
 ***************************************(C) COPYRIGHT 2021 DIODE***************************************
 * @file       	bsp_usart.c
 * @brief
 * @note
 * @Version    	V1.0.0
 ***************************************(C) COPYRIGHT 2021 DIODE***************************************
 */
#include "bsp_usart.h"
#include "stdio.h"
#include "usart.h"


// 重定向串口1的printf
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}



