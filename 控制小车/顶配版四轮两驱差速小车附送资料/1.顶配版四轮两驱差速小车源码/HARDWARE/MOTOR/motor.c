#include "motor.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
void MiniBalance_Motor_Init(void)
{
	RCC->APB2ENR|=1<<2;       //PORTA时钟使能   
	RCC->APB2ENR|=1<<3;       //PORTB时钟使能   
	RCC->APB2ENR|=1<<4;       //PORTC时钟使能  
  RCC->APB2ENR|=1<<5;       //PORTD时钟使能 
	GPIOA->CRH&=0XFFF0FFFF;   // 
	GPIOA->CRH|=0X00080000;   // 
	GPIOB->CRL&=0XFF00FF00;   //推挽输出
	GPIOB->CRL|=0X00220022;   //推挽输出
	GPIOB->ODR|=0<<0;  	
	GPIOB->ODR|=0<<1;  	
	GPIOB->ODR|=0<<4;  
	GPIOB->ODR|=0<<5;  
	GPIOC->CRL&=0XFF00FFFF;   //推挽输出
	GPIOC->CRL|=0X00220000;   //推挽输出	
	GPIOC->CRH&=0XFFF0FFFF;   //推挽输出
	GPIOC->CRH|=0X00020000;   //推挽输出	
	GPIOC->ODR|=0<<4;  	
	GPIOC->ODR|=0<<5;  
	GPIOC->ODR|=0<<12; 
	GPIOD->CRL&=0XFFFFF0FF;   //推挽输出
	GPIOD->CRL|=0X00000200;   //推挽输出	
	GPIOD->ODR|=0<<2; 
	INA1=0;
	INB1=0;
	INA2=0;
	INB2=0;

}
void MiniBalance_PWM_Init(u16 arr,u16 psc)
{		 					 
	MiniBalance_Motor_Init();  //初始化电机控制所需IO
	RCC->APB2ENR|=1<<13;       //使能TIM8时钟    
	RCC->APB2ENR|=1<<4;        //PORTC时钟使能     
	GPIOC->CRH&=0XFFFFFF00;    //PORTC8复用输出
	GPIOC->CRH|=0X000000BB;    //PORTC8复用输出
	
	GPIOC->CRL&=0X00FFFFFF;    //PORTC6 7复用输出
	GPIOC->CRL|=0XBB000000;    //PORTC6 7复用输出
	TIM8->ARR=arr;             //设定计数器自动重装值 
	TIM8->PSC=psc;             //预分频器不分频
	TIM8->CCMR1|=6<<4;         //CH1 PWM1模式	
	TIM8->CCMR1|=6<<12;        //CH2 PWM1模式	
	TIM8->CCMR2|=6<<4;         //CH3 PWM1模式	
	TIM8->CCMR2|=6<<12;        //CH4 PWM1模式	
	
	TIM8->CCMR1|=1<<3;         //CH1预装载使能	  
	TIM8->CCMR1|=1<<11;        //CH2预装载使能	 
	TIM8->CCMR2|=1<<3;         //CH3预装载使能	  
	TIM8->CCMR2|=1<<11;        //CH4预装载使能	  
	
	TIM8->CCER|=1<<0;         //CH1输出使能	
	TIM8->CCER|=1<<4;         //CH2输出使能	   
	TIM8->CCER|=1<<8;         //CH3输出使能	 
	TIM8->CCER|=1<<12;        //CH4输出使能
	TIM8->CCR1=0;
	TIM8->CCR2=0;
	TIM8->CCR3=0;
	TIM8->CCR4=0;
	TIM8->BDTR |= 1<<15;       //TIM8必须要这句话才能输出PWM
	TIM8->CR1=0x8000;          //ARPE使能 
	TIM8->CR1|=0x01;          //使能定时器1 			
} 

