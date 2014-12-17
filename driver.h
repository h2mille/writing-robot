#ifndef __DRIVER_H
#define __DRIVER_H
typedef enum
{
 Down,
 Up
}high;

void Delay(uint32_t nTime);
void TimingDelay_Decrement(void);
void SysTick_Start();
void toggle(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void NVIC_Configuration(void);
void RCC_Configuration(void);
void GPIO_Configuration(void);
void Codeur_Configuration(void); //timer 2 pin 1&2
void Timer3_Configuration(void); //timer 3 pin 1
void Moteur_Configuration(void); //timer 3 pin 1
void Moteur_Stop(void); //timer 3 pin 1
void Moteur_Start(void); //timer 3 pin 1
void Servo_Configuration(void); //timer 3 pin 2
void Servo_Angle(int angle); //timer 3 pin 2
void Set_Pen(high hauteur);
void TIM2_IRQHandler();
void rouler(int distance);

#endif