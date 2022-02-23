%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ; 분기문 (if)
    ; 특정 조건에 따라서 코드 흐름을 제어하는 것

    ; CMP dst, src (dst가 기준)
    ; 비교를 한 결과물은 Flag Register 저장
    
    ; JMP [label]
    ; JMP   : 무조건 jump
    ; JE    : 같으면 jump
    ; JNE   : 다르면 jump
    ; JG    : 크면
    ; JGE   : 크거나 같으면
    ; JL    : 작으면
    ; JLE   : 작거나 같으면
    
    mov rax, 10
    mov rbx, 20
    
    cmp rax, rbx
    
    je LABEL_EQUAL
    
    mov rcx, 0
    jmp LABEL_EQUAL_END
    
LABEL_EQUAL:
    mov rcx, 1
LABEL_EQUAL_END:    
    PRINT_HEX 1, rcx
    NEWLINE
    
    xor rax, rax
    ret