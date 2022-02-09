%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    PRINT_STRING msg ; 공식적으로 어셈블리어는 아니다.
    
    xor rax, rax
    ret
    

;********************************************    
; section .data >> 초기화 된 데이터
; [변수이름] [크기] [초기값]
; [크기] db(1) dw(2) dd(4) dq(8)

section .data
    msg db 'Hello World', 0x00

    a db 0x11, 1, 2, 3, 4  ;[0x11]
    b dd 0x12345678
    ; 장단점이 교차한다.
    ; -   빅 엔디안: 숫자 비교에 유리
    ; - 리틀 엔디안: 캐스팅에 유리
    
    
;********************************************
; section .bss >> 초기화 되지 않은 데이터
; [변수이름] [크기] [개수]
; [크기] resb(1) resw(2) resd(4) resq(8)

section .bss
    e resb 3
    f resw 2
    
;********************************************