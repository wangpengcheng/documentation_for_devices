#ifndef __CONTROL_H
#define __CONTROL_H
#include "sys.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
#define PI 3.14159265
#define ZHONGZHI 0 
#define DIFFERENCE 100
extern	int Balance_Pwm,Velocity_Pwm,Turn_Pwm;
int EXTI15_10_IRQHandler(void);
void Set_Pwm(int motor_a,int motor_b);
void Kinematic_Analysis(float Vy,float Vz);
void Key(void);
void Xianfu_Pwm(int amplitude);
void Xianfu_Velocity(int amplitude_A,int amplitude_B,int amplitude_C,int amplitude_D);
u8 Turn_Off( int voltage);
u32 myabs(long int a);
int Incremental_PI_A (int Encoder,int Target);
int Incremental_PI_B (int Encoder,int Target);
void Get_RC(u8 mode);
void Count_Velocity(void);
void CAN_N_Usart_Control(void);
#endif
