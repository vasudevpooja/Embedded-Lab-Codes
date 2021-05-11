#include<LPC17xx.H>
unsigned char SW;
void delay(unsigned long int x);
void lcdwrt(unsigned char y);

int main()
{

 unsigned char cmd1[]={0X38,0X0F,0X06,0X01,0X80};
 unsigned char msg1[]= "HIGH" ;
 unsigned char msg2[]= "LOW" ;
unsigned char i;
 SystemInit();
 LPC_GPIO2 -> FIOMASK0 = 0X00;
 LPC_GPIO2 -> FIODIR0 = 0XFF;
  LPC_GPIO1 -> FIOMASK1 = 0XF8;
 LPC_GPIO1 -> FIODIR1 = 0X07;
  LPC_GPIO1 -> FIOCLR1 = 0X02;
 LPC_GPIO0 -> FIOMASK3 = 0XF7;
 LPC_GPIO0 -> FIODIR3 = 0X8;
  LPC_GPIO0 -> FIOMASK2 = 0XBF;
 LPC_GPIO0 -> FIODIR2 = 0X40;
 while(1)
 {
 SW=(( LPC_GPIO0 -> FIOPIN3 & 0X08)>>3);
  if(SW==1)
  {
   LPC_GPIO0 -> FIOSET2 = 0X40;
    LPC_GPIO1 -> FIOCLR2 = 0X01;
	for(i=0;i<5;i++)
	lcdwrt(cmd1[i]);
	 LPC_GPIO1 -> FIOSET2 = 0X01;
	 for(i=0;msg1[i]!='\0';i++)
	 lcdwrt(msg1[i]);
  }
  else
  {
   LPC_GPIO0 -> FIOCLR2 = 0X40;
    LPC_GPIO1 -> FIOCLR2 = 0X01;
	for(i=0;i<5;i++)
	lcdwrt(cmd1[i]);
	 LPC_GPIO1 -> FIOSET2 = 0X01;
	 for (i=0;msg2[i]!='\0';i++)
	 lcdwrt(msg2[i]);
	 }
	 }
	 }
 
  void lcdwrt(unsigned char y)
  {
   LPC_GPIO2 -> FIOPIN0 = y;
 LPC_GPIO1 -> FIOSET1 = 0X04;
 delay(0X500000);
  LPC_GPIO1 -> FIOCLR1 = 0X04;
  delay(0X500000);
 
} 
  void delay (unsigned long int x)
	{ unsigned long int j;
		for( j =0;j<x;j++);
	}