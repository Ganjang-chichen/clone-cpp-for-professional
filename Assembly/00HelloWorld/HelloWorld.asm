%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ; 신성한 코더의 종교의식 헬로월드
    PRINT_STRING msg 
    
    xor rax, rax
    ret
    
section .data
    msg db 'Hello World', 0x00