%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    GET_DEC 2, eax
    mov ebx, eax
    shr ebx, 1
    shl ebx, 1
    
    cmp eax, ebx
    jne LABEL_FALSE

    mov cl, 1
    jmp LABEL_END
LABEL_FALSE:
    mov cl, 0
LABEL_END:    
    PRINT_DEC 1, cl
    
    xor rax, rax
    ret