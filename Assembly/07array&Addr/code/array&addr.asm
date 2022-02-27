%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ; 배열과 주소
    ; 배열: 동일한 타입의 데이터 묶음
    ; - 배열을 구성하는 각 값을 요소(element)라고 함
    ; - 배열의 위치를 가리키는 숫자를 인덱스(index)라고 함
    
    mov rax, a
    
    PRINT_HEX 1, [a]
    NEWLINE

    PRINT_HEX 1, [a + 1]
    NEWLINE
    
    mov rbx, 0
    mov rcx, 5
LABEL_START:
    cmp rbx, 5
    je LABEL_END
    
    mov rdx, rax
    add rdx, rbx
    
    PRINT_HEX 1, [a + rbx]
    NEWLINE
    
    add rbx, 1
    jmp LABEL_START

LABEL_END:

    
    
    
    

    xor rax, rax
    ret

section .data
    a db 0x01, 0x02, 0x03, 0x04, 0x05 ; 5 바이트
    b times 5 dw 1; 5 * 2 = 10바이트
    
section .bss
    num resb 10