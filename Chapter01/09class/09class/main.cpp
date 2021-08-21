#include<iostream>
#include<string>
#include<memory>

int chicken_idx = 0;

class Chickens {
    public:
        Chickens(int idx, std::string name, int price, std::string info); // 생성자
        ~Chickens();    // 소멸자
        // setter
        void setPrice(int price);
        void setInfo(std::string info);

        // getter
        int getIDX() const;
        std::string getName() const;
        int getPrice();
        std::string getInfo();

    private:
        int idx;
        std::string name;
        int price;
        std::string info;

};

// 자바 마냥 구분 못함 입력 변수와 내부 변수는 다르게 해야됨.
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

int main() {
    Chickens chickens(0, "fride", 15000, "JMT");
    
    std::cout << "idx : " << chickens.getIDX() << "\n"
        << "name : " << chickens.getName() << "\n"
        << "price : " << chickens.getPrice() << "\n"
        << "info : " << chickens.getInfo()  << "\n" << std::endl;

    return 0;
}