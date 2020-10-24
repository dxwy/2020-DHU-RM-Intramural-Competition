#ifndef  __ps2_H
#define  __ps2_H
#include "main.h"
#include "stm32f1xx_hal.h"


/*
	PB12-->DI
	PB13-->DO
	PB14-->CS
	PB15-->CLK
*/
#define DI    HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)
#define DO_H  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET)
#define DO_L  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET)
#define CS_H  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET)
#define CS_L  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET)
#define CLK_H  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET)
#define CLK_L  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET)

/*����*/
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2          9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      26

/*ģ����*/
#define PSS_RX          5       //��ҡ��X��
#define PSS_RY          6       //��ҡ��Y��
#define PSS_LX          7       //��ҡ��X��
#define PSS_LY          8       //��ҡ��Y��

void PS2_ReadData(void); //������
void PS2_Cmd(uint8_t CMD);//������
void PS2_ClearData(void);	  //���

void PS2_ShortPoll(void);//���ó�ʼ��
void PS2_EnterConfing(void); //��������
void PS2_TurnOnAnalogMode(void);//����ģʽ����
void PS2_VibrationMode(void);//������
void PS2_ExitConfing(void);//��ɲ���������
void PS2_SetInit(void);//�ֱ����ó�ʼ��


uint8_t PS2_DataKey(void);				//��ȡ���ݲ���������
uint8_t PS2_AnologData(uint8_t button); //��ȡģ����
void PS2_Vibration(uint8_t motor1,uint8_t motor2);//�񶯺���
uint8_t PS2_RedLight(void);		//��ID

void delay_us(uint32_t udelay);

#endif


