#include <iostream>
#include <vector>

std::vector<char> positions = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
bool p1turn = true;
void playerSelect();
bool spaceOcc(int sel);
void draw();
bool win(std::vector<char> pos);
int turnNumber = 1;


void greet() {
	std::cout << "\nWelcome to tic-tac-toe\n\n";
	std::cout << "   |   |   \n"
		<< " 1 | 2 | 3 \n"
		<< "   |   |   \n"
		<< "===|===|===\n"
		<< "   |   |   \n"
		<< " 4 | 5 | 6 \n"
		<< "   |   |   \n"
		<< "===|===|===\n"
		<< "   |   |   \n"
		<< " 7 | 8 | 9 \n"
		<< "   |   |   \n";
	
}


void playerSelect() {
	int selection;
	if (p1turn == true) {
		std::cout << "\nPlayer 1 select a square: ";
		std::cin >> selection;
		if (spaceOcc(selection) == false) {
			positions[selection - 1] = 'X';
			p1turn = false;
		}
		else {
			std::cout << "\nThat square is already occupied.\n";
			playerSelect();
		}
	}
	else {
		std::cout << "\nPlayer 2 select a square: ";
		std::cin >> selection;
		if (spaceOcc(selection) == false) {
			positions[selection - 1] = 'O';
			p1turn = true;
		}
		else {
			std::cout << "\nThat square is already occupied.\n";
			playerSelect();
		}
	}
	
}

bool spaceOcc(int sel) {
	if (positions[sel - 1] != 'X' && positions[sel - 1] != 'O') {
		return false;
	}
	
	return true;
	
}

void turn() {
	playerSelect();
	std::cout << "\n\n";
	draw();
	if (win(positions) == true) {
		std::cout << "WINNER!";
	}
	else if (turnNumber == 9) {
		std::cout << "TIE!";
	}
	else {
		turnNumber++;
		turn();
	}


}

void draw() {
	std::cout << "   |   |   \n"
		<< " " << positions[0] << " | " << positions[1] << " | " << positions[2] << " \n"
		<< "   |   |   \n"
		<< "===|===|===\n"
		<< "   |   |   \n"
		<< " " << positions[3] << " | " << positions[4] << " | " << positions[5] << " \n"
		<< "   |   |   \n"
		<< "===|===|===\n"
		<< "   |   |   \n"
		<< " " << positions[6] << " | " << positions[7] << " | " << positions[8] << " \n"
		<< "   |   |   \n";

}


bool win(std::vector<char> pos) {
	//rows
	if (pos[0] == pos[1] && pos[0] == pos[2]) {
		return true;
	}
	else if (pos[3] == pos[4] && pos[3] == pos[5]) {
		return true;
	}
	else if (pos[6] == pos[7] && pos[6] == pos[8]) {
		return true;
	}
	//columns
	else if (pos[0] == pos[3] && pos[0] == pos[6]) {
		return true;
	}
	else if (pos[1] == pos[4] && pos[1] == pos[7]) {
		return true;
	}
	else if (pos[2] == pos[5] && pos[2] == pos[8]) {
		return true;
	}
	else if (pos[0] == pos[4] && pos[0] == pos[8]) {
		return true;
	}
	else if (pos[2] == pos[4] && pos[2] == pos[6]) {
		return true;
	}
	
	return false;
	

}
