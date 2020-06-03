.section .init
.globl _start
_start:
    ldr r0,=0x20200000      /* GPIO virtual addr */

    /*
        54 GPIOs per 6 registers. 32 bits each with 7 modes per pin with 3 bits per GPIO
        GPFSELn 0-5 (0-9 | 10-19 | 20-29 | 30-39 | 40-49 | 50-54)
        16 % 10 * 3 = 18
    */

    mov r1,#1
    lsl r1,#18
    str r1,[r0,#4]          /* GPIO Function Select 1 (16 % 10 * 3) (GPFSEL1) */

    mov r1,#1
    lsl r1,#16

loop$:
    str r1,[r0,#40]         /* GPIO Pin Output Clear 0 (GPCLR0) (clears pin 16 [sets to low] (ACTOK)) */

    mov r2,#0x3F0000        /* BLINK ME! (busies the processor with some maths) */
    wait1$:
    	sub r2,#1
    	cmp r2,#0
    	bne wait1$

    str r1,[r0,#28]         /* GPIO Pin Output Set 0 (GPSET0) (sets pin 16 [to high]) */

    mov r2,#0x3F0000        /* BLINK ME! (busies the processor with some maths) */
    wait2$:
    	sub r2,#1
    	cmp r2,#0
    	bne wait2$

b loop$                     /* Do it all over again */
