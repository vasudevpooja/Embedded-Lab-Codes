#include<LPC17xx.H>
void delay(unsigned long int x);
int main(void)
{
int i ;

 SystemInit();
 LPC_GPIO0 -> FIOMASK2 = 0X0F;
 LPC_GPIO0 -> FIODIR2 = 0X20;
 i=0;
 while(i<10)
 {
  LPC_GPIO0 -> FIOSET2 = 0X20;
  delay(0x5000);
	 LPC_GPIO0 -> FIOCLR2=0X20;
	 delay(0X5000);
	 i++;
  
  }
} 
  void delay (unsigned long int x)
	{ unsigned long int i=0;
		for( i =0;i<x;i++);
	}