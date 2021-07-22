
# 챕터 1.1 C++ 기초

***

## 목차

[1.1 Hello, World](#hello-world)

[1.2 전처리에 대하여](#전처리에-대하여)

[1.3 main() 함수](#main-함수)

[1.4 IO 스트림](#io-스트림)

[1.5 네임 스페이스 namespace](#네임-스페이스-namespace)

[1.6 변수 및 리터럴 연산자](#변수-및-리터럴-연산자)


***

## 1.1
## Hello World

    어떤 컴퓨터 언어를 배우든 Hello, World! 부터 찍고 보는것은 국룰이다.
    아래에서 Hello, World 코드를 보면서 배울 수 있는 점들을 짚어보자.

[헬로월드 코드](./01HelloCpp/HelloWorld.cpp)

## 1.2
## 전처리에 대하여
    #include #define 말고도 보면 #ifdef #endif #ifnder #endif #progma
    이러한 전처리 지시자가 많다.
    후자의 경우 책에서 보통 중복 인클루드를 방지하기 위해 사용한다고 한다.
    앵간한 컴파일러에서는 #progma once 하나면 해결된다고하는데,
    이 progma에 관한 내용은 이후 10장에서 자세히 다룬다하니 일단 미뤄두자.

    필자의 경우 책만으로는 이해가 힘들어서 추가로 구글링을 하였다.
<https://jhnyang.tistory.com/299>

    위 링크의 티스토리 블로그에 잘 설명되어있으니 위 전처리지시자에 대하여
    조금더 이해하고싶으면 참고하면 좋을 것 같다.

## 1.3
## main 함수

    main() 함수는 c에서도 그러하였지만, 프로그렘을 실행할 때 가장 먼저 호출되는 시작점이다.
    코드에서 int main() 이라고 되어있는데 이는 반환값이 정수값이라는 것이다.
    이 정수값을 통해 프로그렘의 상태를 알려준다.
    Hello, World! 코드에서처럼 파라미터 값을 없이 사용할 수도 있지만,
    int main(int argc, char* argv[]) 이렇게 두개의 팔라미터를 사용할수도 있다.

## 1.4
## IO 스트림

    책에서 12장에서 자세히 다룬다고 한다.
    std::cout ~ 은 일단 그저 c에서 printf()라 생각하자. (공부가 미숙한 관계로 옳은 말이 아닐 가능성 높음)

    Hello, World! 에서 처럼뿐만이 아니라 다음과 같이도 사용 가능하다.
``` c++
    std::cout << "There are " << 219 << " ways I love you." << std::endl;
```
    출력: There are 219 ways I love you.

    반대로 std::cin >> ~ 은 입력스트림이다.

## 1.5
## 네임 스페이스 namespace

    네임 스페이스는 코드 내에서 같은 변수명이나 함수명이 서로 충돌하는 문제를 해결하기위해 고안되었다.
    예를 들자면 한코드내에 A 헤더파일의 foo() 함수, 내코드의 foo() 함수가 둘 다 있다면 문제가 발생한다.
    이를 해결하기 위해 어디의 foo 이런식으로 만드는 것 이다.

    아래의 예제 코드들을 보자.
[namespace 예제 코드 main](./02namespace/app.cpp)

[namespace 예제 코드 header](./02namespace/my_namespace.h)

    네임 스페이스는 헤더파일이나 코드파일 내에 다음과 같이 작성한다.
```c++
    namespace namespace_name {
        int var_name;
        void function_name(){
            // 함수 동작~
        }
    }
```
    
    네임 스페이스에 있는 함수나 변수를 불러오려면
    [namespace명(스코프)]::[변수 또는 함수] 이러한 식으로 호출하면 된다.
    ex)
```c++
    int var = namespace_name::var_name;
    namespace_name::function_name();
```

    using을 사용하면 스코프를 생략할 수 있다.
```c++
    using namespace namespace_name;
    int var = var_name;
    function_name();
```
    다음과 같이 특정 변수(또는 함수)만 선택해서 생략 가능하다.
```c++
    using namespace_name::var;
    int var = var_name;
    namespace_name::function_name();
```
    
    사용법을 보면 무언가 비슷한 것이 보일 것 이다. 
    mycode::foo()
    std::cout ~
    그렇다. std 또한 네임스페이스였던 것 이다.
    따라서 using을 통해 std:: 을 생략 가능하다.

## 1.6
## 변수 및 리터럴 연산자

    변수는 기본적으로 C에서 배운 것과 비슷하다 보면 된다.
    여기서 몇가지만 짚어보자.

    첫번째. 캐스팅.
    캐스팅이란 변수 타입을 다른 타입으로 바꾸는 것 이다.
    명시적인 캐스팅에는 3가지의 방법이 있다.

```c++
    // 명시적 변환
    float myFloat = 3.15f;
    int i1 = (int) myFloat;                 // case 1
    int i2 = int(myFlaot);                  // case 2
    int i3 = static_cast<int>(myFloat);     // case 3
```

    묵시적으로 되는 경우도 있는데 데이터의 손실이 없는경우는 
    크기가 작은비트에서 큰비트로 바뀔 때 이고,
    그 반대의 경우는 데이터의 손실이 생긴다.

```c++
    // 묵시적 변환
    float f;
    int i;
    
    int converted_i = f     // 데이터 손실 발생 및 경고 나타남
    float converted_f = i   // 데이터 손실 발생 안함

```

    연산자들

```c++

    int i = 3; // = 대입 연산자
    
    bool b = !true; // ! 논리 반전

    i = i + 1 - 1 * 1 / 1 % 1; // + - * / 사칙연산, % 나머지
    
    int j = 4;

    j = i & j; // 비트 and 연산

    j = i | j; // 비트 or 연산

    j = i ^ j; // 비트 Xor 연산

    j = i >> j; // 비트 i를 오른쪽으로 j 만큼 시프트

    j = i << j; // 비트 i를 왼쪽으로 j 만큼 시프트

```

## 1.7
## 데이터 타입

#### 1.7.1
#### 열거 타입과 enum

    enum 은 나열하는 값 목록과 범위를 엄격하게 관리하기 위한 열거 타입이다.

```c++
    // 사용 예시
    enum ChessPiece { King, Queen, Rook, Pawn}; // case 1

    enum ChessPiece2 { King2 = 1, Queen2, Rook2 = 5, Pawn2}; // case 2

```

    다음과 같이 사용할 시 열거타입은 컴파일러 안에서 정수 타입으로 처리된다.
    일반적으로 값을 따로 지정하지 않았을 시 0부터 시작해서 +1 해서 할당된다.
    예를 들면 case 1 의 값은 각각 King = 0, Queen = 1, Rook = 2, Pawn = 3 으로 할당된다.

    명시적으로 지정할 수 있고, 명시 된 다음의 명시되지 않은 변수의 값은 이전의 값에 1을 더한 값으로 할당된다.
    예를 들자면 case 2 에서 Queen = 2, Pawn = 6 으로 할당된다.

    그러나 앞서 설명한 열거타입은 정수 취급을 받기 때문에 완전 별개인 열거 타입간에도 비교 연산이 가능하다.
    엄격한 열거타입은 이를 해결하기 위한 방법 중 하나이다.

```c++
    // 엄격한 열거타입

    enum class MyEnum {
        EnumValue1, 
        EnumValue2 = 10,
        EnumValue3
    }

```