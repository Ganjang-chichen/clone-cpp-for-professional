%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    mov eax, 0x12345678
    shl eax, 4  ; 시프트 연산 왼쪽
    shr eax, 4  ; 시프트 연산 오른쪽
    
    not eax     ; not 연산 1-> 0, 0 -> 1
    xor eax, ebx; 같으면 0, 다르면 1
    
    xor rax, rax
    ret