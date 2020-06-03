#!/bin/sh

arm-none-eabi-as -o main.o main.s
arm-none-eabi-ld -o output.elf -T kernel.ld main.o
arm-none-eabi-objcopy output.elf -O binary kernel.img