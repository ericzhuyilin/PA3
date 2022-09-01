@ Describe the hardware to the assembler1
       .arch   armv6
       .cpu    cortex-a53
       .syntax unified

@ Declare any external functions
       .extern strtoul
       //.global main

@ Define any constants
       .equ    FP_OFFSET, 4
       .equ    NULL, 0x0
       .equ    EXIT_SUCCESS, 0

@ Start data segment where you will define your string
       .data

@ Start text segment and begin writing your function
       .text
       .type   parseNum, %function

parseNum: push {fp, lr}
          add  fp, sp, FP_OFFSET
          
          // set up r0
          // ldr  r0, [r0]  // get *argv[] to r0  
          add  r0, 8 // go to the address of argv[2]
          
          // set sp for double word alignment
          // sub  sp, sp, 8

          // char *endPtr;
          ldr  r1, =NULL

          // set up r2
          mov  r2, 16

          bl   strtoul

          sub  sp, fp, FP_OFFSET
          pop  {fp, lr}
          bx   lr

.end
