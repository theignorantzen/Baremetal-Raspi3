#include <stdint.h>

/* Values from the BCM2835-ARM-Peripherals.pdf manual */

/* Note this value is different on pi1 models */
#define IO_BASE	0x3f000000


#define GPIO_BASE	(IO_BASE+0x200000)

#define GPIO_GPFSEL0	0
#define GPIO_GPFSEL1	1
#define GPIO_GPFSEL2	2
#define GPIO_GPFSEL3	3
#define GPIO_GPFSEL4	4

#define GPIO_GPSET0	7
#define GPIO_GPSET1	8

#define GPIO_GPCLR0	10
#define GPIO_GPCLR1	11

/* Reference to the GPIO space */
/* An array of 32-bit integers */
volatile uint32_t *gpio;

/* If we make this static, the C compiler will optimize it away */
void __attribute__ ((noinline)) delay(int length) {

	volatile int i;

	/* the asm(""); keeps gcc from optimizing away */
	for(i=0;i<length;i++) asm("");

}

/* main function */
int main(int argc, char **argv) {

	/* Point to the physical GPIO region */
	gpio = (uint32_t *)GPIO_BASE;

	/* Enable GPIO18 in the proper GPFSEL register */

	/* YOUR CODE HERE */
	gpio[GPIO_GPFSEL1] &= ~(0x7<<24);
	gpio[GPIO_GPFSEL1] |= (1<<24);

	while(1) {

		/* Write 1 to the proper SET register (turn on the LED) */

		/* YOUR CODE HERE */
		gpio[GPIO_GPSET0] |= (1<<18);

		/* delay  */
		delay(0x50000); 

		/* Write 1 to set the proper CLR register (turn off the LED) */

		/* YOUR CODE HERE */
		gpio[GPIO_GPCLR0] |= (1<<18);

		/* delay */
		delay(0x50000);

	}


	/* Hang forever; there is no OS to return to! */
	while(1) {
	}

	return 0;
}
