@ Describe the hardware to the assembler1
              .arch   armv6
              .cpu    cortex-a53
              .syntax unified

@ Declare any external functions
              .extern strtoul
              .global extractParts

@ Define any constants
              .equ    FP_OFFSET, 4
              .equ    NULL, 0x0
              .equ    EXIT_SUCCESS, 0

@ Start data segment where you will define your string
              .data

@ Start text segment and begin writing your function
              .text
              .type   parseNum, %function

extractParts: push {fp, lr}
              add  fp, sp, FP_OFFSET
              
              // sub  sp, sp, 8

              // store the number to stack
              // str  r0, [fp, -8]

              // set sign to 0
              lsr  r2, r0, 31
              strb r2, [r1]

              // shift number and set the exp
              lsr  r2, r0, 23
              sub  r2, 127
              strb r2, [r1, 1]

              // set mantissa
              lsl  r0, 9
              lsr  r0, 9
              // rol  r2, r0, 23
              str  r0, [r1, 4]

              sub  sp, fp, FP_OFFSET
              pop  {fp, lr}
              bx   lr

.end
