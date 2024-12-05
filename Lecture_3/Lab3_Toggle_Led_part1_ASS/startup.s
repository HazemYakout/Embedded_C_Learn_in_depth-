

.section .vectors 

.word 0x20001000            /*stack top*/
.word _reset                /* Reset*/
.word Vector_handler        /*Hard Faualt*/
.word Vector_handler        /*MM Fault*/
.word Vector_handler        /*Bus Fault*/
.word Vector_handler        /*Usage Fault*/
.word Vector_handler        /*Reserved*/
.word Vector_handler        /*Reserved*/
.word Vector_handler        /*Reserved*/
.word Vector_handler        /*Reserved*/
.word Vector_handler        /*SV call*/
.word Vector_handler        /*Debug*/
.word Vector_handler        /*Reserved*/
.word Vector_handler        /*PendSV*/
.word Vector_handler        /*SYS_Tick*/
.word Vector_handler        /*IRQ0*/
.word Vector_handler        /*IRQ1*/

.section .text
_reset:
 bl main
 b .
.thumb_func
 Vector_handler:
    b _reset
