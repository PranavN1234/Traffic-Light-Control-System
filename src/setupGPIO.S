.section .text
.align 2
.globl setupGPIO

#include "memoryMap.inc"
#include "GPIO.inc"

setupGPIO:

    # INPUTS ARE TAKEN 

    addi sp, sp, -16
    # allocate a stack frame, moves the stack up by 16 bits
    sw ra, 12(sp)
    li t0, GPIO_CTRL_ADDR # load GPIO base address

    li t1, PIN_19 # Button1 

    sw t1, GPIO_INPUT_EN(t0) # set pin 2 for input enable
    sw t1, GPIO_INPUT_PULUP(t0) # enable pull up
    
    # We define the output with their pin names next to it

    li t1, PIN_2 # NS_RED
    li t2, PIN_7 # NS_Yellow
    or t1, t1, t2
    li t2, PIN_8 # NS_Green
    or t1, t1, t2
    li t2, PIN_9 # EW_RED
    or t1, t1, t2
    li t2, PIN_17 # EW_Yellow
    or t1, t1, t2
    li t2, PIN_18 # EW_Green
    or t1, t1, t2
    li t2, PIN_4 # PED_RED
    or t1, t1, t2
    li t2, PIN_10 # PED_Green
    or t1, t1, t2
    li t2, GPIO_GREEN_LED 
    or t1, t1, t2 
    sw t1, GPIO_OUTPUT_EN(t0)
    sw t2, GPIO_OUTPUT_VAL(t0) 

    
    
    


    # write the GPIO RGP pins to GPIO Enable offset
    # (Enable output on RGP pins so we can write)
     # set the XOR so the RGB pins are active high
    lw ra, 12(sp)
    addi sp, sp, 16

    
    ret