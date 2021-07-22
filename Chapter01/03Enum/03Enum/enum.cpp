#include <iostream>
#include <string>

int main() {

	enum ChessPiece { King, Queen, Rook, Pawn }; // case 1

	std::cout << "ChessPiece King  : " << ChessPiece::King << std::endl;
	std::cout << "ChessPiece Queen : " << ChessPiece::Queen << std::endl;
	std::cout << "ChessPiece Rook  : " << ChessPiece::Rook << std::endl;
	std::cout << "ChessPiece Pawn  : " << ChessPiece::Pawn << std::endl;

	enum ChessPiece2 { King2 = 1, Queen2, Rook2 = 5, Pawn2 }; // case 2

	std::cout << "ChessPiece2 King2  : " << ChessPiece2::King2 << std::endl;
	std::cout << "ChessPiece2 Queen2 : " << ChessPiece2::Queen2 << std::endl;
	std::cout << "ChessPiece2 Rook2  : " << ChessPiece2::Rook2 << std::endl;
	std::cout << "ChessPiece2 Pawn2  : " << ChessPiece2::Pawn2 << std::endl;

	return 0;
}