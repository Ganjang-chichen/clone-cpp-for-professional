%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging

    GET_DEC 1, al   ; 10진수로 입력 받음, 어셈블러가 아닌 SASM 매크로 함수
    GET_DEC 1, num  ; 용법: GET_DEC (입력받을 바이트수), (저장공간)
    
    PRINT_DEC 1, al ; 10진수로 출력,어셈블러가 아닌 SASM 매크로 함수
                    ; 용법: PRINT_DEC (출력할 바이트수), (출력할 데이터)
    NEWLINE         ; 출력에서 줄바꿈, 어셈블러가 아닌 SASM 매크로 함수
    PRINT_DEC 1, num

    ; 더하기 연산
    ; add a, b (a += b)
    ; a 는 레지스터 or 메모리
    ; b 는 레지스터 or 메모리 or 상수
    ; 단 a = b = 메모리 X

    ; 빼기 연산
    ; sub a, b (a -= b)
    ; 규칙은 덧셈과 이하 동일

    add al, 2        ; 레지스터 + 상수
    PRINT_DEC 1, al
    NEWLINE
    
    add al, [num]        ; 레지스터 + 메모리
    PRINT_DEC 1, al
    NEWLINE    
    
    ; 곱하기 연산
    ; mul reg
    ; - mul bl => al * bl
    ; -- 연산 결과를 ax에 저장
    ; - mul bx => ax * bx
    
    
    mov ax, 0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2, ax
    NEWLINE
    
    ; 나누기 연산
    ; dev reg
    ; - dev bl => al / bl
    ; 연산결과는 al(몫) ah(나머지)
    ; -- 연산 결과는 dx(상위 16비트) ax (하위 16비트)에 저장

    mov ax, 0
    mov al, 100
    mov bl, 3
    div bl
    PRINT_DEC 1, al
    NEWLINE
    mov al, ah
    PRINT_DEC 1, al
    NEWLINE

    xor rax, rax
    ret
    
section .bss
    num resb 1