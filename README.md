# Baremetal-Raspi3

### Basic bare metal coding on a Raspberry Pi 3.

Basic attempt at baremetal programming. Bare metal programming removes the original linux kernel and writing a program of your own and calling it as the kernel.

- One of the folders has the .c file for blinking of the ACT led on the pi board.

- The other folder has code for blinking an external LED.

I did this as a part of VLC module but alas as most of the time this didn't work for that case.

Note: The address in the code shall change with different versions of Pi as the addressing system varies from board to board.

The best resource I could get was this [blog](https://www.valvers.com/open-software/raspberry-pi/bare-metal-programming-in-c-part-1/).
