%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ; 함수 (프로시져 procedure 또는 서브루틴 subroutine)
    ; 레지스터의 활용
    ; - a, b, c, d 범용 레지스터
    ; - 포인터 레지스터 (포인터 = 위치를 가리키는~)
    ; -- ip (Instruction Pointer) : 다음 수행 명령어의 위치
    ; -- sp (Stack Pointer) : 현재 스택 top 위치 (일종의 cursor)
    ; -- bp (Base Pointer) : 스택 상대주소 계산용
    
    
    call PRINT_MSG
    
;*********************************
; 스택 활용 없는 함수 활용
    mov eax, 10
    mov ebx, 15
    call MAX_CASE1
    PRINT_DEC 4, ecx
    NEWLINE
;*********************************
; 스택의 원리 예시

    PRINT_HEX 8, rsp
    NEWLINE
    PRINT_HEX 8, rbp
    NEWLINE
    NEWLINE
    
    PRINT_STRING msg_push
    NEWLINE
    NEWLINE
    
    push 1
    PRINT_STRING msg_rsb
    PRINT_HEX 8, rsp
    NEWLINE
    PRINT_STRING msg_value
    PRINT_HEX 1, [rsp]
    NEWLINE
    PRINT_HEX 1, [rbp - 8]
    NEWLINE
    NEWLINE
    
    push 2
    PRINT_STRING msg_rsb
    PRINT_HEX 8, rsp
    NEWLINE
    PRINT_STRING msg_value
    PRINT_HEX 1, [rsp]
    NEWLINE
    PRINT_HEX 1, [rbp - 16]
    NEWLINE
    NEWLINE
    
    push 3
    PRINT_STRING msg_rsb
    PRINT_HEX 8, rsp
    NEWLINE
    PRINT_STRING msg_value
    PRINT_HEX 1, [rsp]
    NEWLINE
    PRINT_HEX 1, [rbp - 24]
    NEWLINE
    NEWLINE
    
    
    PRINT_STRING msg_pop
    NEWLINE
    NEWLINE
    
    
    pop rax
    PRINT_STRING msg_rsb
    PRINT_HEX 8, rsp
    NEWLINE
    PRINT_STRING msg_value
    PRINT_HEX 8, rax
    NEWLINE
    NEWLINE
    
    pop rax
    PRINT_STRING msg_rsb
    PRINT_HEX 8, rsp
    NEWLINE
    PRINT_STRING msg_value
    PRINT_HEX 8, rax
    NEWLINE
    NEWLINE
    
    pop rax
    PRINT_STRING msg_rsb
    PRINT_HEX 8, rsp
    NEWLINE
    PRINT_STRING msg_value
    PRINT_HEX 8, rax
    NEWLINE
    NEWLINE

;*********************************
; 스택 활용 함수 예씨

    push rax
    push rbx
    push 444
    push 666
    
    call MAX_CASE2
    add rsp, 16
    PRINT_DEC 8, rax
    
    pop rbx
    pop rax

    xor rax, rax
    ret
    
PRINT_MSG:
    PRINT_STRING msg
    NEWLINE

; ex) 두 값중 더 큰 값을 반환하는 max
; 근데 두 값을 어떻게 넘겨 받을 것인가?
; 그리고 반환은 어떻게 할 것인가?

; 1. 레지스터 활용 -> eax,, ebx 비교후 ecx 반환
; 그냥 해보는 것. 보통 이런방식으로 안 씀.
MAX_CASE1:
    cmp eax, ebx
    jg L1
    mov ecx, ebx
    jmp L2
L1:
    mov ecx, eax
L2:
    ret

; 2 스택(stack)이라는 메모리 영역을 사용 (스택 프레임)
; 함수가 사용하는 일종의 메모장
; - 매개 변수 전달
; - 돌아갈 주소 관리

MAX_CASE2:
    push rbp
    mov rbp, rsp
    
    mov rax, [rbp + 16]
    mov rbx, [rbp + 24]
    
    cmp rbx, rax
    jl L3
    mov rax, rbx
L3:
    pop rbp
    ret

section .data
    msg db 'Hello World', 0x00
    msg_rsb db 'rsb: ', 0x00
    msg_value db 'value: ', 0x00
    msg_push db 'push', 0x00
    msg_pop db 'pop', 0x00
    