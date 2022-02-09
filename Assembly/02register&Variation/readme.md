# 레지스터와 메모리


    section .data >> 초기화 된 데이터
    [변수이름] [크기] [초기값]
    [크기] db(1) dw(2) dd(4) dq(8)

    section .bss >> 초기화 되지 않은 데이터
    [변수이름] [크기] [개수]
    [크기] resb(1) resw(2) resd(4) resq(8)

(예제)[./code/regiNmem.asm]

<img src="./img/section.png" name=".data, .bss 메모리 변수 값">

<img src="./img/00memory.png">

<img src="./img/01memory.png">

<img src="./img/02memory.png">

<img src="./img/03memory.png">

<img src="./img/04memory.png">

<img src="./img/05memory.png">

<img src="./img/06memory.png">

<img src="./img/07memory.png">

<img src="./img/08memory.png">

