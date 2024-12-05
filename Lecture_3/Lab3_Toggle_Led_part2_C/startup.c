
#include <stdint.h>

extern int main(void);
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern uint32_t _E_text;
extern uint32_t _stacktop;


void Reset_Handler(void);

void Default_Handler()
{
    Reset_Handler();
}
                                    
void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));                                                 ;
void H_fault_Handler(void) __attribute__((weak,alias("Default_Handler")));                                  ;
void MM_fault_Handler(void) __attribute__((weak,alias("Default_Handler")));                                     ;
void Bus_fault_Handler(void) __attribute__((weak,alias("Default_Handler")));                                    ;
void Usage_fault_Handler(void) __attribute__((weak,alias("Default_Handler")));                                   ;



void Reset_Handler(void)
{
    uint32_t data_size = (uint8_t*)&_E_data - (uint8_t*)&_S_data ;
    uint8_t *P_src = (uint8_t*) &_E_text;
    uint8_t* P_dst = (uint8_t*) &_S_data;
    for(int i=0; i<data_size;i++)
    {
        *((uint8_t*)P_dst++) = *((uint8_t*)P_src++);
    }

    uint32_t bss_size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss;
    P_dst=(uint8_t*)&_S_bss;
    for(int i=0; i<bss_size;i++)
    {
        *((uint8_t*)P_dst++) = (uint8_t)0;
    }    
    main();
}

uint32_t vector[] __attribute__((section(".vectors"))) = 
{       

     (uint32_t) &_stacktop,
     (uint32_t) &Reset_Handler,
     (uint32_t) &NMI_Handler,
     (uint32_t) &H_fault_Handler,
     (uint32_t) &MM_fault_Handler,
     (uint32_t) &Bus_fault_Handler,
     (uint32_t) &Usage_fault_Handler

};