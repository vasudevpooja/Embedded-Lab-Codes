#include<LPC17xx.H>
unsigned char SW;
int main()
{

 SystemInit();
 LPC_GPIO0 -> FIOMASK3 = 0XF7;
 LPC_GPIO0 -> FIODIR3 = 0X8;
  LPC_GPIO0 -> FIOMASK2 = 0XBF;
 LPC_GPIO0 -> FIODIR2 = 0X40;
 
 while(1)
 {
  SW= ((LPC_GPIO0 -> FIOPIN3 & 0X08)>>3);
  if (SW == 1)
	 LPC_GPIO0 -> FIOSET2=0X40;
	 else
	 LPC_GPIO0 -> FIOCLR2 = 0X40;
  
  
  }
} 
  void delay (unsigned long int x)
	{ unsigned long int i=0;
		for( i =0;i<x;i++);
	}