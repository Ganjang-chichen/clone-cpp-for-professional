# 산술, 논리 연산

## SASM 매크로 함수

    GET_DEC (입력될 바이트수), (입력될 데이터 공간)
    10진수로 입력받음
    ex) GET_DEC 1, al

    PRINT_DEC (출력할 바이트수), (출력할 데이터)
    10진수로 출력
    ex) PRINT_DEC 1, al ; 

    NEWLINE
    출력에서 줄바꿈

## 산술연산

    더하기 연산
    add a, b (a += b)
    a 는 레지스터 or 메모리
    b 는 레지스터 or 메모리 or 상수
    단 a = b = 메모리 X
    ex) add al, 2

    빼기 연산
    sub a, b (a -= b)
    규칙은 덧셈과 이하 동일
    ex) sub al, 1

    곱하기 연산
    mul reg
    mul bl => al * bl
    연산 결과를 ax에 저장
    mul bx => ax * bx

    ex)
    mov al, 5
    mov bl, 8
    mul bl

    나누기 연산
    dev reg
    dev bl => al / bl
    연산결과는 al(몫) ah(나머지)
    연산 결과는 dx(상위 16비트) ax (하위 16비트)에 저장
    ex)
    mov ax, 0
    mov al, 100
    mov bl, 3
    div bl

    