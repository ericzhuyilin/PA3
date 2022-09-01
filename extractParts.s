@ Describe the hardware to the assembler1
              .arch   armv6
              .cpu    cortex-a53
              .syntax unified

@ Declare any external functions
              .extern strtoul

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
              
              sub  sp, sp, 8

              // load struct pointer to r4, address of the struct
              ldr  r4, [r1] 

              // store ieeeBin to stack
              strd r0, [fp, -12]

              // set the sign bit
              mov  r2, 0
              strb r2, [r4]
              
             
              // load first 4 bytes of the number
              ldr  r1, [sp, 4]
           

              sub  sp, fp, FP_OFFSET
              pop  {fp, lr}
              bx   lr

.end
