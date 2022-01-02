
# 클래스와 객체에 능숙해지기

## 목차
[7.2 클래스의 여러 규칙들](#클래스의-여러-규칙들)
[7.2.1 클래스 접근제어](#클래스의-접근제어)
[7.2.2 선언순서](#선언순서)
[7.3 메서드의 정의](#메서드의-정의)
[7.3.1 데이터의 멤버 접근](#데이터-맴버-접근)

## 7.1 
## 클래스 만들어보기

```c++

class CppClass {

private:
    double var;

public:
    double getVar();
    void setVar(double v);

};

```

## 7.2 
## 클래스의 여러 규칙들

### 7.2.1
### 클래스의 접근제어

    public: 객체의 public 메서드 또는 public 데이터 맴버는 다른 코드에서 제한없이 호출하거나 읽고 쓸 수 있다.
    private: 해당 클래스 안에서만 접근할 수 있고, 그 클래스의 서브클래스에서조차도 접근이 불가하다.
    protected: 같은 클래스 안에서는 protected 메서드나 데이터 맴버를 호출하거나 읽고 쓸 수 있다. 파생 클래스에서도 접근 가능.

    클래스에서는 디폴트로 private 가 적용된다,

### 7.2.2
### 선언순서

    메서드, 데이터 맴버, 접근자는 어떤 순서로든 선언할 수 있다.
    그러나 가독성을 높이기 위해서 가능하면 그룹으로 선언하는 것이 좋다.

```c++

// 이렇게도 가능은 하지만 가독성이 좋지 않다.
class CppClass {

public:
    void setVar(double v);
private:
    double var;
public:
    double getVar();

};


```

### 7.3
### 메서드의 정의

    아래 클래스를 예시로 들어보자.
```c++
class CppClass {

private:
    double var;

public:
    double getVar();
    void setVar(double v);

};
```

    여기서 getVar() 을 호출하면 링커에서 정의되지 않은 메서드라고 에러를 출력할 것 이다.
    그 이유는 클래스 정의에서는 메서드 프로토타입만 선언했고, 그 구현은 정의하지 않았기 때문이다.
    마치 함수의 선언만 한 꼴과 같은것이다.

    이를 해결하려면 함수를 구현하듯이 구현을 해주면 된다.

```c++

double CppClass::getVar(){
    return var;
}

```

    여기서 함수를 구현할 때와 다른 점은 구현하고자 하는 클래스의 스코프를 지정해야 한다는 점 이다.
    
    리턴타입 클래스이름::함수이름(인자값들) 이런 형식으로 해주면 된다.


### 7.3.1
### 데이터 멤버 접근

    위의 예시처럼

```c++

double CppClass::getVar(){
    return var;
}

```

    메서드의 몸체 안에서는 다음과 같이 데이터 맴버에 접근가능하다.

```c++

double CppClass::getVar(){
    return this->var;
}

```
    