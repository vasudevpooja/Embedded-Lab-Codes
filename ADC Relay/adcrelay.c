#include<LPC17xx.H>

unsigned short int adc = 0;
int main()
{
	SystemInit();
	LPC_SC->PCONP|= 0x00001000;
	LPC_GPIO0->FIOMASK2 = 0xBF;
	LPC_GPIO0->FIODIR2 = 0x40;
	LPC_PINCON->PINSEL3 = 0XC0000000;
	LPC_ADC-> ADCR= 0x00210320;
	while(1)
	{while((LPC_ADC->ADSTAT&0x00000020)!= 0x00000020)
		{}
			adc = ((LPC_ADC->ADDR5>>4)&0x00000fff);
			if(adc>0x9B2)
				LPC_GPIO0->FIOSET2= 0x40;
			else
				LPC_GPIO0->FIOCLR2=0x40;
		}
	}