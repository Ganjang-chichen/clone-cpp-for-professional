# 분기문

    특정 조건에 따라 임의의 위치로 이동하게끔 하는 방법으로
    분기를 제어한다.

    CMP dst, src (dst가 기준)
    비교를 한 결과물은 Flag Register 저장
    
    JMP [label]
    Flag Register 의 상태에 따라 [label]의 위치로 이동한다.

    JMP   : 무조건 jump
    JE    : 같으면 jump
    JNE   : 다르면 jump
    JG    : 크면
    JGE   : 크거나 같으면
    JL    : 작으면
    JLE   : 작거나 같으면

[예제 코드](./code/condition.asm)