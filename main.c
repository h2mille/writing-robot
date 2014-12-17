
#define  LSE_FAIL_FLAG  0x80
#define  LSE_PASS_FLAG  0x100
#include "stm32f10x_conf.h"
#include "stm32f10x_it.h"

//variable globales

int main()
{
  SysTick_Start();
  NVIC_Configuration();
  RCC_Configuration();
  GPIO_Configuration();
  Codeur_Configuration();
  Timer3_Configuration();
  Moteur_Configuration();
  Servo_Configuration();
  Moteur_Stop();

  while(1){
    char chaine[]= "HELLO WORLD";
    printf(chaine); 
    while(1);
  }
  //return 0;
}
