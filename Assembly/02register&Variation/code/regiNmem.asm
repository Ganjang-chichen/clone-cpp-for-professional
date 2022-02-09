%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    mov rax, a ; a의 주소값을 rax에 복사
    mov bl, [a]
    mov rcx, [rax]
    
    mov [a], byte 0x55
    mov [a], word 0x6666
    mov [a], dl
    
    mov [e + 1], byte 0x11
    mov [e + 4], byte 0x21

    xor rax, rax
    ret
    
;변수의 선언 및 사용
;변수는 그냥 데이터를 저장하는 바구니 [ ]
; - 처음에 바구니 사용하겠다 선언 (이름과 크기 지정)

;********************************************    
; section .data >> 초기화 된 데이터
; [변수이름] [크기] [초기값]
; [크기] db(1) dw(2) dd(4) dq(8)

section .data
    a db 0x11 ;[0x11]
    b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444
    
;********************************************
; section .bss >> 초기화 되지 않은 데이터
; [변수이름] [크기] [개수]
; [크기] resb(1) resw(2) resd(4) resq(8)

section .bss
    e resb 3
    f resw 2
    
;********************************************