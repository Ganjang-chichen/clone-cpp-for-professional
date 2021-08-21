
# 챕터 2 문자열의 활용

## 목차

[2.1 c와 c++ 문자열 비교](#c와-cpp-문자열-비교)

[2.2 기존 c의 문자열](#기존-c의-문자열)

[2.3 비표준 문자열](#비표준-문자열)

### 2.1
### c와 cpp 의 문자열 비교

    기존의 c에서는 문자열의 표현을 배열로 밖에 사용못했었다.
    이는 버퍼 오버플로우 등 보안 위험등의 문제가 있다.
    따라서 c++ STL 에서는 더 안전하고 사용하기 쉬운 std::string 클레스를 제공한다.

    c 스타일 문자열의 장점
    * 단순하다. 기본 문자 타입과 배열 구조만 사용한다.
    * 가볍다. 재대로 사용하면 꼭 필요한 메모리 공간만 점유한다.
    * 저수준이다. 로우 메모리상에서 쉽게 조작하거나 복제 가능하다.
    * c 에 익숙한 사람은 새로 배울 필요가 없다.
    
    c 스타일 문자열의 단점
    * 범용 문자열 데이터 타입이므로 고급 작업을 하기에는 너무 많은 노력이 추가로 필요하다.
    * 잘못된 메모리 작업에 민감하고 해당 버그를 찾기 어렵다.
    * c++의 객체지향 개념을 활요하지 못한다.
    * 프로그래머가 문자열의 내무 동작 방식을 이해해야 한다.

### 2.2
### 기존의 c의 문자열

    기존 c 의 문자열을 c++에서 쓸일이 있을까 하지만, 의외로 쓸일이 종종 있기 때문에 알고있어야 한다.
    
    c에서의 문자열은 배열로 구현되는데, 마지막 문자 다음 배열의 값을 \0 (null) 로 하여 끝을 판단한다.
    이에 따라 c의 문자열의 크기는 실제 문자열의 크기 + 1 이라고 볼 수 있다.

```c++
    
    char str[] = "hello"; // 필요 메모리 6
    cout << strlen(str) << endl; // 출력 5
    cout << sizeof(str) << endl; // 출력 6

    char* str2 = "hello";
    cout << strlen(str2) << endl; // 출력 5
    cout << sizeof(str2) << endl; // 출력 32비트 모드에서 4, 64비트에선 8
```

    문자열 리터럴
    리터럴은 코드 구문 자체가 변수가 아닌 값을 타나내는 것 이다.
    예를 들면
    cout << "hello" << endl;
    에서 hello 를 문자열 리터럴이라 할 수 있다.
    문자열 리터럴은 스택이나 힙이 아닌 읽기전용 메모리에 할당된다.
    이를 리터럴 풀링(literal pooling)이라 하는데, 이는 컴파일러가 메모리를 절약하기 위한 방법 중 하나이다.

    문자열 리터럴은 변수에 대입될 순 있지만 위험한 방식이 될 수 있다.
    왜냐하면 읽기 전용 메모리에 할당된 변수이기 때문이다.

```c++

    char* ptr = "hello";    // 문자열 리터럴을 변수에 대입
    ptr[1] = 'a';           // 정의되지 않은 동작. 무슨일이 일어날 지 알 수 없다.

    // 위의 경우 때문에 문자열 리터럴을 변수로 사용 시 const를 사용하는것이 안전하다.
    // 왜냐하면 컴파일러에서 걸러주기 때문이다.
    const char* ptr2 = "hello"; // 문자열 리터럴을 변수에 대입
    ptr2[1] = 'a';              // 컴파일 에러! 읽기 전용 메모리에 쓰기시도!

    // 문자열 리터럴은 문자 배열의 초깃값으로 사용가능하다.
    char arr[] = 'hello';   // 컴파일러가 자동으로 문자열 배열크기에 맞게 복제 및 메모리 할당
    arr[1] = 'a';           // 이 경우는 배열 내용을 수정가능하다. 
                            // 왜냐하면 이 경우는 리터럴 풀링에 포함되지 않기 때문이다.

```

[리터럴 예제 코드](./01c_literal/01c_literal/main.cpp)

### 2.2
### c++ string 클래스

    string 클래스는 cstrin 에서 제공하는 문자열 처리기능 대부분을 지원하고, 잘 사용만 한다면, 메모리 할당까지 해준다.

    string 클래스 사용법
    string이 클래스이긴 하지만 대부분은 int 나 char 같은 내장 기본 타입으로 취급하고 시용해도 된다.

```c++

    string s1 = "ab";
    string s2 = "cd";
    string s3 = "ab";

    cout << s1 + s2 << endl;    // 출력 abcd
    cout << (s1 == s3) << endl; // 출력 1
    cout << (s1 < s2) << endl;  // 출력 1 사전순
    cout << (s1 > s2) << endl;  // 출력 0

    s1[1] = 'B';
    cout << s1 << endl;         // 출력 aB

    const char* s4 = s1.c_str();    // string to char*
    cout << s4 << endl;

    string s5 = s4;                 // char* to string
    cout << s5 << endl;

    int integer = 333;
    string s6 = to_string(integer); // int to string
    cout << "integer : " + s6 << endl;

    int integer_c = stoi(s6);       // string to int
    cout << integer_c + 2 << endl;

    float f = 3.141592f;
    string s7 = to_string(f);       // float to string
    cout << "float : " + s7 + "f" << endl;

    float f_c = stof(s7);           // string to float
    cout << f_c + 2 << endl;
    
    // 나머지 변환은 생략

    string text = "hello \n \t fff\rg";
    cout << text << endl;

    string text2 = R"(고래야 적어도 바다는 네가 가졌으면 좋겠어 // 로우 문자열에선 주석도 안먹힌다.
고래야 헤엄하던대로 계속 헤엄했으면 좋겠어
    \r \n \t)";

    cout << text2 << endl;

    // 확장된 로우 문자열 리터럴. )을 사용할 수 있다.
    // 재일 앞, 끝부분을 구분자라 하는데 양 끝이 같아야 하고, 사용자가 정의한다.
    string text3 = R"d-char-sequence(여기선 괄호() 사용가능해유 )d-char-sequence";
    cout << text3 << endl;

    string text4 = R"wtf(쮸압쮸압)wtf";
    cout << text4 << endl;

```

[string 예제 코드](./02string/02string/main.cpp)

### 2.3
### 비표준 문자열

    이렇게 string 클레스가 좋음에도 불구하고 꽤 많은 개발자들이 string 타입을 사용하지 않는다.
    그이유로는 string 타입이 각 프로그래머가 처한 상황에 적합한 동작을 하지 않아서 이다.
    또는 그냥 있는지 몰라서 안쓰는 경우도 있다.
    하지만 가장 납득이 가는 이유는 사용하는 개발 프레임 워크가 자신만의 문자열 타입을 이용하기 때문인 것도 있다.
    예로써 MS의 MFC로, CString 이라는 자신만의 문자열 타입을 별도로 정의해 사용한다.
    이러한 프레임워크 문제는 하위 호환성이나, 과거 코드 재활용 문제와 연관이 되기 때문에 어쩔 수 없다.

    이러한 상황을 보았을 때 c++ 프로젝트에서 문자열 타입을 선택할 때 장기적인 안목으로 고민해야 한다.