%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ; 주석은 ;를 사용하면 된다.
    
    ; 10진수 표현 (0 1 2 3 4 5 6 7 8 9)
    ; 0 1 2 3 4 ... 9 10
    
    ;  2진수 표현 (0 1)
    ; 0b0 0b1 0b10 0b11 0b110 ... 0b1001 0b1010
    
    ; 16진수 표현 (0 1 2 3 4 5 6 7 8 9 A B C D E F)
    ; 0x00 0x01 0x02 0x03 0x04 ... 0x09 0x0A
    
    ; 8bit = 1byte
    ; 2byte = 1word
    ; 2word = dword (double-word)
    ; 2dword = 1qword (quad-word)
    
    ; mov a b ; b의 값을 a에 옮겨라
    
    mov eax, 0x1234         ; 0000 0000 0000 0000 0001 0010 0011 0100
    mov rbx, 0x12345678     ; 0000 0000 0000 0000 0000 0000 0000 0000 0001 0010 0011 0100 0101 0110 0111 1000
    mov cl, 0xff            ; 1111 1111
    
    mov al, 0x00            ; 0000 0000 0000 0000 0001 0010 0000 0000    
    mov rax, rdx
    
    xor rax, rax
    ret