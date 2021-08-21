#include <iostream>
#include <string>
#include <bitset>

int main() {

	std::cout << "비트 연산 예시\n" << std::endl;

	short s1 = 123;
	short s2 = 456;
	std::cout << "binary code s1 123  : " << std::bitset<16>(s1) << std::endl;
	std::cout << "binary code s2 456  : " << std::bitset<16>(s2) << std::endl;
	std::cout << "binary code s1 & s2 : " << std::bitset<16>(s1 & s2) << std::endl;
	std::cout << "binary code s1 | s2 : " << std::bitset<16>(s1 | s2) << std::endl;
	std::cout << "binary code s1 ^ s2 : " << std::bitset<16>(s1 ^ s2) << std::endl;
	std::cout << "binary code s1 >> 3 : " << std::bitset<16>(s1 >> 3) << std::endl;
	std::cout << "binary code s1 << 3 : " << std::bitset<16>(s1 << 3) << std::endl;
	
	std::cout << "\n\nenum 사용 예제\n" << std::endl;

	enum ChessPiece { King, Queen, Rook, Pawn }; // case 1

	std::cout << "starting of default enum value is 0" << std::endl;

	std::cout << "ChessPiece King  : " << ChessPiece::King << std::endl;
	std::cout << "ChessPiece Queen : " << ChessPiece::Queen << std::endl;
	std::cout << "ChessPiece Rook  : " << ChessPiece::Rook << std::endl;
	std::cout << "ChessPiece Pawn  : " << ChessPiece::Pawn << std::endl;

	enum ChessPiece2 { King2 = 1, Queen2, Rook2 = 5, Pawn2 }; // case 2

	std::cout << "ChessPiece2 King2  : " << ChessPiece2::King2 << std::endl;
	std::cout << "ChessPiece2 Queen2 : " << ChessPiece2::Queen2 << std::endl;
	std::cout << "ChessPiece2 Rook2  : " << ChessPiece2::Rook2 << std::endl;
	std::cout << "ChessPiece2 Pawn2  : " << ChessPiece2::Pawn2 << std::endl;

	enum class MyEnum {
		EnumValue1,
		EnumValue2 = 10,
		EnumValue3
	};

	std::cout << "MyEnum value 1 : " << static_cast<int>(MyEnum::EnumValue1) << std::endl;
	std::cout << "MyEnum value 2 : " << static_cast<int>(MyEnum::EnumValue2) << std::endl;
	std::cout << "MyEnum value 3 : " << static_cast<int>(MyEnum::EnumValue3) << std::endl;

	
	return 0;
}