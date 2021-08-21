#include<iostream>
#include<string>


const std::string setConst(std::string msg) {
    return msg;
}

int main() {

    // case 1
    auto const1 = setConst("First");
    const1 = "changed1";
    std::cout << const1 << std::endl;
    // const 속성이 적용이 안되어 값이 바뀐다.

    // case 2
    decltype(setConst("Second")) const2 = setConst("Second");
    // const2 = "changed2"; 문법 오류 발생

    // case 3
    decltype(auto) const3 = setConst("Third");
    const1 = "changed3";
    std::cout << const3 << std::endl;
    // const 속성이 적용되어 값이 안 바뀐다.

    class t {
    public:
        t();
        ~t();

    };

    return 0;
}