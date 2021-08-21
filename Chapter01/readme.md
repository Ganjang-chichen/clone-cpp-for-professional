
# 챕터 1.1 C++ 기초

***

## 목차

[1.1 Hello, World](#hello-world)

[1.2 전처리에 대하여](#전처리에-대하여)

[1.3 main() 함수](#main-함수)

[1.4 IO 스트림](#io-스트림)

[1.5 네임 스페이스 namespace](#네임-스페이스-namespace)

[1.6 변수 및 리터럴 연산자](#변수-및-리터럴-연산자)

[1.7 데이터 타입](#1.7)

***

## 1.1
## Hello World

    어떤 컴퓨터 언어를 배우든 Hello, World! 부터 찍고 보는것은 국룰이다.
    아래에서 Hello, World 코드를 보면서 배울 수 있는 점들을 짚어보자.

[헬로월드 코드](./01HelloCpp/01HelloCpp/HelloWorld.cpp)

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
[namespace 예제 코드 main](./02namespace/02namespace/app.cpp)

[namespace 예제 코드 header](./02namespace/02namespace/my_namespace.h)

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

[bit 연산 예제 코드](./03Enum/03Enum/enum.cpp)

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

    MyEnum value1 = MyEnum::EnumValue1;

```

#### 1.7.2
#### 구조체 struct

    구조체는 하나 이상의 기본타입 또는 다른 구조체를 조합하여 새로운 타입을 만들어낸다.

```c++

    struct Chicken {
        int idx;
        char* name;
        int price;
        int count;
    }

```

[구조체 예제 코드](./04struct/04struct/main.cpp)

## 1.8
## 조건, 논리

    if / else 문

```c++
    double value;
    double value2;
    if(value > 5.4) { // value 값이 5.4 보다 클 때
        foo1();
    }else if(value2 < 3.4) { // value 값이 5.4보다 크지 않고, value2 값이 3.4보다 작을 때
        foo2();
    }else { // value 값이 5.4 보다 크지 않고, value2 값이 3.4보다 작지 않을 때
        foo3();
    }

```

    switch 문

```c++ 

    switch(option) {
        case OPTION1:   // option == OPTION1 >> foo, foo2 실행  >> break 없으면 다음 케이스로 넘어간다.
            foo();
        case OPTION2:   // option == OPTION2 >> foo 2 실행      >> break 를 만나면 멈춘다.
            foo2();
            break;
        default :       // option 값이 OPTION1, OPTION2 값이 아닐 때 foo3 실행
            foo3();
    }

```

    조건 논리 연산

    a > b       a가 b초과
    a >= b      a가 b이상
    a < b       a가 b미만
    a <= b      a가 b이하
    a == b      a가 b같음
    a != b      a가 b다름
    !a          a가 아님
    a || b      a 또는 b
    a && b      a 그리고 b
    a ? b : c   a가 참이면 b, a가 거짓이면 c


## 1.9
## 배열

    배열은 같은 데이터 타입들의 값들을 일렬로 나열한 것이다.

    c 에서 물려받은 array

```c++
    
    int arr0[3];
    arr0[0] = 1;
    arr0[1] = 2;
    arr0[2] = 3;
    arr0[3] = 4;

    int arr1[3] = {3}; // arr1[0], arr1[1], arr1[2], arr1[3] 값은 3
    
    int arr2[] = {1, 2, 3, 4}; // arr2[0] = 1, arr2[1] = 2, arr2[2] = 3, arr2[3] = 4
```

    std::array

    기존의 C 배열에 대한 아주 가벼운 래퍼 클래스이다.
    
    기존 C의 배열과 비교
    1. 크기를 항상 정확하게 알 수 있다.
    2. 포인터가 자동으로 잘못 타입 캐스팅되는 것도 피할 수 있다.
    3. C++ STL의 반복자를 활용하여 항목 순회 및 STL알고리즘 활용이 가능하다.(STL은 차후 16장에서 다룬다 한다.)

    활용

```c++

    #include<array>
    #include<iostream>
    int main() {
        std::array<int, 3> arr = {9, 8, 7};
        std::cout<< "Array Size" << arr.size() <<std::endl;
        std::cout<< "Element 1 :" << arr[1] <<std::endl;
        return 0;
    }

```

## 1.10
## 루프

    while 문
    for 문

```c++

    while(condition) {  // condition 이 참을 유지할 때 까지 계속 foo 를 반복실행한다. 
        foo();          // 단, 차후 condition이 거짓이 되면 반복을 멈춘다.
    }

    do{                 // 일단 foo2()를 실행한다. condition2이 참일 때, 루프를 돈다.
        foo2();
    }while(condition2)


    for(int i = 0; i < 10; i++) {   // for(시작값;반복조건;루프 끝에 실행)
        foo();                      // 앞의 예제는 총 10번 반복
    }

    std::array<int, 4> arr = {1, 3, 5, 7}
    for(int i = 0; i < 10; i++) {   // for(시작값;반복조건;루프 끝에 실행)
        foo();                      // 앞의 예제는 총 10번 반복
    }

```

[반복문 예제 코드](./05arrayNloop/05arrayNloop/main.cpp)

## 1.11
## 함수
    반환값  함수명          입력값   
    type    function_name (type var1, type var2 ...) {
        실행 내용
        -contants- 
    }

    자동 함수 리턴 타입 auto
    auto 는 할당 받는 값으 타입에 컴파일러에서 연역하여 자동으로 타입이 정해진다.
    ex) auto x = 333; // x는 int 타입이 된다.

    또 다른 auto키워드의 사용법은 새로운 함수 정의법에서 사용할 수 있다.
    아래 함수는 일반적으로는 사용하진 않지만, 탬플릿 함수에서는 유용하다.
    auto foo(int i) -> int {
        return i + 3;
    }

    마지막으로 사용되는 방법은 제네릭 람다 표현식이다.
    이에 대한 내용은 차후 17장에서 다룬다 한다.

[함수 예제 코드](./06function/06function/main.cpp)

## 1.12
## 포인터와 동적 메모리

    동적 메모리
    동적 메모리는 컴파일 타임에 크기를 정할 수 없는 데이터를 이용할 수 있게 해준다.
    거의 모든 프로그램은 동적 메모리를 어떤 형태로든 이용하게 된다.

    스택과 힙
    c 프로세스가 사용하는 메모리는 스택과 힙 두 가지로 나뉜다.
    메모리에 함수는 호출되는 순서대로 아래부터 쌓이고 위에서부터 처리된다.
    힙 메모리에는 현재 실행중인 함수 및 스택프레임과는 독립된 메모리영역이다.
    이 메모리에는 함수의 호출이나 리턴과 관련없이 항상 본재해야하는 변수 등을 위치시킨다.

    포인터 활용
    힙에 명시적으로 메모리를 할당하면 무엇이든 저장할 수 있다.

    C 에서 가져온 malloc과 free는 사용을 지양하자.
    대신 다음의 예제에 나오는 new와 delete를 사용하자.

```c++
    // 정수를 포인터로 동적 할당
    // 포인터 변수 선언, 반드시 초기화 해야 한다.
    // c에서의 NULL은 중의성 문제가 있기 때문에 nullptr을 쓴다.
    int* myIntegerPointer = nullptr; 

    // 메모리 할당 시 new 연산자를 이용한다.
    myIntegerPointer = new int;

    // 포인터 역참조를 통한 값 설정
    *myIntegerPointer = 9;

    // 반대로 주소값을 얻을 땐 &연산자를 쓴다.
    int* getIntegerPointer = &(*myIntegerPointer);

    // 포인터의 할당 해제
    delete myIntegerPointer;
    myIntegerPointer = nullptr;

    // 구조체의 경우 아래 두 가지 방법으로 활용가능하다.
    Employee* anEmployee = &(employee);

    cout << *(anEmployee).salary << endl;
    cout << anEmployee->salary << endl; 

    // 배열의 경우
    int arrSize = 16;
    int* myVariableSizedArray = new int[arraySize];
    myVariableSizedArray[3] = 3;

    // 할당 해제
    delete [] myVariableSizedArray;

```

    스마트 포인터

    기존 C의 포인터의 여러 문제들을 해결하고자 생긴 포인터이다.
    스마트 포인터는 객체에 유효한 스코프가 더 이상 없을때 자동으로 메모리를 해제한다.
    <memory> 헤더파일안에 있다.
    
    1. std::unique_ptr
    보통의 포인터와 비슷하다. 그러나 변수가 스코프를 벗어났을 때 자동으로 메모리가 해제된다.
    명시적으로 delete를 통해 해제할 수 있다.

```c++
    #include<memory>

    // 사용법은 일반 포인터와 같다.
    auto anEmployee = std::make_unique<Employee>();

```

    2. std::shared_ptr
    데이터에 대한 오너십이 여기 저기 분산될 수 있게 해준다.
    shared_ptr 변수가 다른 변수에 대입될 때마다 레퍼런스 카운터가 증가되어 오너가 하나 더 늘었다는 것을 표시한다.
    이 변수가 모든 스코프를 벗어날 때, 레퍼런스 카운트가 0이되며 메모리가 해제된다.
    단 shared_ptr은 배열을 지원하지 않는다.

    3. std::week_ptr
    week_ptr 은 대입된 객체를 참조하되 레퍼런스 카운트에 영향을 주고 싶지 않을때 사용한다.

    위의 스마트포인터는 차후 22장에서 상세히 다룬다고 한다.

## 1.13
## 참조형
    
    원래 C 에서는 파라미터로 넘겨진 변수를 함수에서 변경시키려면포인터를 활용했어야 한다.
    그러나 C++에서는 파라미터의 타입에 &을 붙이면서 이를 가능하게 한다.

```c++

    void addOne(int i) {
        i++;    // 파라미터 변수의 복제본이기 때문에 원래 변수에는 지장 없다.
    }
    
    void addOne_mk2(int& i) {
        i++;    // 원본 파라미터의 변수값이 1 증가한다.
    }

```
[참조형 예제 코드](./07exception/07exception/main.cpp)

## 1.14
## 예외 처리

    C++ 은 코드의 안정성을 한 단계 높이기 위해 언어차원에서 제공되는 기능이다.
    특정 코드가 예외적인 상황을 인지하면, 익셉션을 던진다.
    그리고 다른 코드가 던져진 익셉션을 받아 필요한 뒤처리를 한다.
    이 부분에서 까다로운 부분은 차후 13장에서 다루도록 하겠다 한다.

```c++

    #include<stdexcept>

    double divideNumbers(double numerator, double denominator) {
        if(denominator == 0) {
            throw std::invalid_argument("Denominator cannot be 0");
        }
        return numerator / denominator;
    }

    #include<iostream>
    #include<exception>

    int main() {
        try {
            std::cout << divideNumbers(2.5, 0.5) << std::endl;
            std::cout << divideNumbers(2.5, 0) << std::endl;
            std::cout << divideNumbers(2.5, 0.1) << std::endl;
        }catch(const std::exception& exception){
            std::cout << "Exception caught : " << exception.what() << std::endl;
        }
        return 0;
    }
    
    /* 출력
    5
    Exception caught : Denominator cannot be 0
    */


```

[예외 처리 예제 코드](./07exception/07exception/main.cpp)

## 1.15
## const

    const는 javaScript에서와 같이 또는 Java의 final과 같이 변하지 않는 값을 할당할때 쓴다.
    기존의 #define 과 서용처는 비슷하지만 c++에서는 const사용을 권장한다.
    const의 모든 경우에 대한 상세 설명은 차후 10장에서 다룬다 한다.
    ex) const int MAX_COFFEE_IDX = 200;

## 1.16
## 타입 추론

    decltype(auto)

    위의 코드 같은 경우 auto는 const 속성을 없애버리는 문제점이 있었다.
    이러한 문제를 해결하기 위해 dectype(auto)가 도입되었다.

[decltype 예제 코드](./08const/08const/main.cpp)

## 1.17
## 클래스의 정의

    클래스(class)는 객체의 특성을 정의한다.
    보통 헤더파일에서 선언하고, 상세 정의는 관련 소스파일에서 작성한다.

```c++

    class Chickens {
        public :
            Chickens();      // 생성자
            ~Chickens();    // 소멸자
            void setIDX() const;
            void setName() const;
            int getIDX() const;
            std::string getName() const;
        private :
            int idx;
            std::string name;
    };

    Chickens::Chickens(int set_idx, std::string set_name, int set_price, std::string set_info) {
        idx = set_idx;
        name = set_name;
        price = set_price;
        info = set_info;
    }

    Chickens::~Chickens() {
        std::cout << "chicken "<< name << " deleted" << std::endl;
    }

    void Chickens::setPrice(int set_price) {
        price = set_price;
    }

    void Chickens::setInfo(std::string set_info) {
        info = set_info;
    }

    int Chickens::getIDX() const{
        return idx;
    }

    std::string Chickens::getName() const{
        return name;
    }

    int Chickens::getPrice() {
        return price;
    }

    std::string Chickens::getInfo() {
        return info;
    }

```

[클래스 예제 코드](./09class/09class/main.cpp)

## 1.18
## 표준 라이브러리 vector iterator

    vector 클래스는 C의 배열을 대체하는 것으로 헐씬 더 유연하고 안전하다.
    런타임에 동적으로 항목을 추가하거나, 삭제가능하고, 그에 따른 메모리 할당과 해제도 자동으로 해주기 때문에 편하다.
    차후 15장에서 상세히 살펴보겠지만 여기선 간단히 훑어보고 가자.

```c++

    #include<vector>

    int main() {

        std::vector<string> myVector = {"first", "second"}; // 배열처럼 선언
        myVector.push_back("third"); // 기존 배열에 추가
        myVector.push_back("forth");

        for(const suto& str:: myVector) {
            std::cout << str << std::endl;
        }

        return 0;
    }

```

[클래스 예제 코드](./10cppStdLib/10cppStdLib/main.cpp)