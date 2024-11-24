#include "uart.h"
#include "Platform_Types.h"

#define UART0DR *((vuint32_t* const) ((uint32*) 0x101f1000)) 

void Uart_Send_String (uint8* P_tx_string)
{
	while (*P_tx_string != '\0')
	{
		UART0DR = (uint32) (*P_tx_string);
		P_tx_string++;
	}
}