#include<LPC17xx.h>
void delay(unsigned long int x);
int main()
{
 SystemInit();
 LPC_GPIO1 -> FIOMASK3 = 0XEF;
 LPC_GPIO1 -> FIODIR3 = 0X10;
 while(1)
 {
  LPC_GPIO1 -> FIOSET3 = 0X10;
  delay(0x50);
  LPC_GPIO1 -> FIOCLR3 = 0X10;
  delay(0x50);
  }
  }
  void delay(unsigned long int x)
  {
  unsigned long int i =0;
  for (i=0;i<x;i++);
  }