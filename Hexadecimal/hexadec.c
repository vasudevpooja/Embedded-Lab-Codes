#include<LPC17xx.H>
void delay(unsigned long int x);
int main()
{
 unsigned char val;
 SystemInit();
 LPC_GPIO0 -> FIOMASK1 = 0XF0;
 LPC_GPIO0 -> FIODIR1 = 0X0F;
 val=0x01;
 while(1)
 {
  LPC_GPIO0 -> FIOPIN1 = val;
  delay(0x80000);
	 val=val+0x01;;
  
  }
} 
  void delay (unsigned long int x)
	{ unsigned long int i=0;
		for( i =0;i<x;i++);
	}