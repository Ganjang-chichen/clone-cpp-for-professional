%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    ; 반복문 구현 방법

    mov ecx, 10    
LABEL_LOOP:
    dec ecx
    PRINT_STRING msg1
    PRINT_DEC 4, ecx
    NEWLINE
    
    cmp ecx, 0
    jne LABEL_LOOP
    
    
    mov ecx, 100
    mov ebx, 0x00
LABEL_SUM:
    add ebx, ecx
    dec ecx
    
    cmp ecx, 0
    jne LABEL_SUM
    
    PRINT_DEC 4, rbx
    
    
    xor rax, rax
    ret
    
section .data
    msg1 db 'count down :'
