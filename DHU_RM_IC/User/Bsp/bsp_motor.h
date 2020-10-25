#ifndef __BSP_MOTOR_H
#define __BSP_MOTOR_H
#include "main.h"

#define PS2_PSS_MID_VALUE		128
#define SPEED_PWM_MAX 			999	// ���pwm
#define SPEED_PWM_DEAD_ZONE 	50	// ��Сpwm����ֹ��Ʈ

#define MOTOR1	0
#define MOTOR2	1
#define MOTOR3	2
#define MOTOR4	3

#define M1TIM htim3
#define M2TIM htim3
#define M3TIM htim3
#define M4TIM htim3

void motor_move(uint8_t motor_i,int v);
void chassis_remote_control(void);
float map(float val, float I_Min, float I_Max, float O_Min, float O_Max);

#endif

