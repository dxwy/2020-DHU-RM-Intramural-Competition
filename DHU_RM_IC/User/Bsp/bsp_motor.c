#include "bsp_motor.h"
#include "bsp_ps2.h"
#include "tim.h"
#include <stdlib.h>
#include "stdio.h"
#include "bsp_usart.h"

void motor_move(uint8_t motor_i,int v)
{
	if(v>SPEED_PWM_MAX)
		v= SPEED_PWM_MAX;
	else if (v<-SPEED_PWM_MAX)
		v = -SPEED_PWM_MAX;
	
    switch(motor_i)
    {
    case MOTOR1:
        if(v>0)
        {
            HAL_GPIO_WritePin(M1A_GPIO_Port,M1A_Pin,GPIO_PIN_SET);
            HAL_GPIO_WritePin(M1B_GPIO_Port,M1B_Pin,GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,abs(v));
        }
        else
        {
            HAL_GPIO_WritePin(M1A_GPIO_Port,M1A_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M1B_GPIO_Port,M1B_Pin,GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,abs(v));
        }
        break;
    case MOTOR2:
        if(v>0)
        {
            HAL_GPIO_WritePin(M2A_GPIO_Port,M2A_Pin,GPIO_PIN_SET);
            HAL_GPIO_WritePin(M2B_GPIO_Port,M2B_Pin,GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,abs(v));
        }
        else
        {
            HAL_GPIO_WritePin(M2A_GPIO_Port,M2A_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2B_GPIO_Port,M2B_Pin,GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,abs(v));
        }
        break;
    case MOTOR3:
        if(v>0)
        {
            HAL_GPIO_WritePin(M3A_GPIO_Port,M3A_Pin,GPIO_PIN_SET);
            HAL_GPIO_WritePin(M3B_GPIO_Port,M3B_Pin,GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,abs(v));
        }
        else
        {
            HAL_GPIO_WritePin(M3A_GPIO_Port,M3A_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M3B_GPIO_Port,M3B_Pin,GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,abs(v));
        }
        break;
    case MOTOR4:
        if(v>0)
        {
            HAL_GPIO_WritePin(M4A_GPIO_Port,M4A_Pin,GPIO_PIN_SET);
            HAL_GPIO_WritePin(M4B_GPIO_Port,M4B_Pin,GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,abs(v));
        }
        else
        {
            HAL_GPIO_WritePin(M4A_GPIO_Port,M4A_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M4B_GPIO_Port,M4B_Pin,GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,abs(v));
        }
        break;
    default:
        break;
    }
}
void chassis_remote_control(void)
{
    int speed[4];
    // ps2模拟量映射到pwm
    int x;
    int y;
	int w;
    // 获取PS2数据
    key = PS2_DataKey();
    RX = PS2_AnologData(PSS_RX);
    LX = PS2_AnologData(PSS_LX);
    RY = PS2_AnologData(PSS_RY);
    LY = PS2_AnologData(PSS_LY);
	// 映射成pwm
    x = map(LX,0,255,-1000,1000);
    y = map(LY,0,255,-1000,1000);
	w = map(RX,0,255,-1000,1000);
    // 解析数据
    speed[0] = x-y+w;
    speed[1] = x+y-w;
    speed[2] = -x-y+w;
    speed[3] = -x+y-w;

    // 输出PWM
    for(uint8_t i=0; i<4; i++)
    {
        motor_move(i,speed[i]);
    }
	printf("key:%d\r\n",key);
    printf("x:%d\r\n",x);
    printf("y:%d\r\n",y);
    printf("s1:%d\r\n",speed[0]);
    printf("s2:%d\r\n",speed[1]);
    printf("s3:%d\r\n",speed[2]);
    printf("s4:%d\r\n\r\n",speed[3]);
}

//输入值分别是：输入值，输入最小值，输入最大值，输出最小值，输出最大值
float map(float val, float I_Min, float I_Max, float O_Min, float O_Max)
{
    return(((val-I_Min)*((O_Max-O_Min)/(I_Max-I_Min)))+O_Min);
}

