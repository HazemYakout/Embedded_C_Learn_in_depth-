
#include <stdint.h>
//extern to be determined by th linker
extern int main(void);
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern uint32_t _E_text;
volatile uint32_t size_t;

// Global Section
static unsigned long stacktop [256]; //256*4=1024 byte (requested) 
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


// vectors section is an array of pointer to function 
 void (*const vector_func[])()__attribute__((section(".vectors"))) = 
{       
     (void(*)()) ((unsigned long)stacktop + sizeof(stacktop)),
      &Reset_Handler,
      &NMI_Handler,
      &H_fault_Handler,
      &MM_fault_Handler,
      &Bus_fault_Handler,
      &Usage_fault_Handler
};