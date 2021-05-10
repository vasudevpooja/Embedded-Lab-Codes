#include<LPC17xx.H>
void delay(unsigned long int x);
int main(void)
{
int arr[]={8,4,2,1};
int num = 0;

 SystemInit();
 LPC_GPIO0 -> FIOMASK1 = 0XF0;
 LPC_GPIO0 -> FIODIR1 = 0X0F;
 
 while(1)
 {
  LPC_GPIO0 -> FIOSET1 = arr[num %4];
  delay(0x50000);
	 LPC_GPIO0 -> FIOCLR1=0X0F;
	 num++;
  
  }
} 
  void delay (unsigned long int x)
	{ unsigned long int i=0;
		for( i =0;i<x;i++);
	}