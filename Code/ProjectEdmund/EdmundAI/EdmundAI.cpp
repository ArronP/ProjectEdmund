#include "Edmund.h"
#include "EdmundStats.cpp"
#include <iostream>
#include <string>


int main()
{
	int sarcasmLevel = 9;
	string test = "Quit";

	Edmund userAI;
	userAI.DailyGreeting();

	std::cout << "What level of Sarcasm would you prefer?(0-10) " << endl;
	std::cin >> sarcasmLevel;
	userAI.SarcasmStatement(sarcasmLevel);

	do {
		std::cout << "I await your inqueires..." << endl;
		std::cin >> test;
	} while (test != "Quit");
	return 0;
}

