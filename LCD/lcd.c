#include<LPC17xx.H>
#define RS 0X01
#define RW 0X02
#define EN 0X04
void delay(unsigned long int x);
void lcdwrt(unsigned char y);

int main()
{

 unsigned char cmd[]={0X38,0X0F,0X06,0X01,0X80};
 unsigned char msg[]= "Welcome to PESU" ;
 unsigned char i;
 SystemInit();
 LPC_GPIO2 -> FIOMASK0 = 0X00;
 LPC_GPIO2 -> FIODIR0 = 0XFF;
  LPC_GPIO1 -> FIOMASK1 = 0XF8;
 LPC_GPIO1 -> FIODIR1 = 0X07;
  LPC_GPIO1 -> FIOCLR1 = RW;
 LPC_GPIO1 -> FIOCLR1 = RS;
 for(i=0;i<5;i++)
 lcdwrt(cmd[i]);
 LPC_GPIO0 -> FIOSET1 = RS;
 for(i=0;msg[i] ='\0';i++)
 lcdwrt(msg[i]);
  
  }
  void lcdwrt(unsigned char y)
  {
   LPC_GPIO2 -> FIOPIN0 = y;
 LPC_GPIO1 -> FIOSET1 = EN;
 delay(1);
  LPC_GPIO1 -> FIOCLR1 = EN;
  delay(1);
 
} 
  void delay (unsigned long int x)
	{ unsigned long int j;
		for( j =0;j<x;j++);
	}