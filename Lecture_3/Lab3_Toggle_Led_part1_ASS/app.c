#include <stdint.h>
#include <stdio.h>

#define RCC_BASE          0x40021000
#define APB2ENR_OFFSET    0x18
#define PORTA_BASE        0x40010800
#define CRH_OFFSET        0x04
#define ODR_OFFSET        0x0c

#define RCC_APB2ENR   *(volatile unsigned int*)(RCC_BASE   + APB2ENR_OFFSET)
#define GPIOA_CRH     *(volatile unsigned int*)(PORTA_BASE + CRH_OFFSET)
#define GPIOA_ODR     *(volatile unsigned int*)(PORTA_BASE + ODR_OFFSET)

uint8_t g_var[3]={1,2,3};
uint8_t const const_var[3]={1,2,3};


int main(void)
{

	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH    &=0xff0fffff;
	GPIOA_CRH    |=0x00200000;

	while(1)
	{
		GPIOA_ODR |=1<<13;
		for(int i=0;i<5000;i++);
		GPIOA_ODR &=~(1<<13);
		for(int i=0;i<5000;i++);
	}

	return 0;
}

