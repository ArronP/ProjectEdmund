#include "Edmund.h"
#include "EdmundStats.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int sarcasmLevel = 0;
	string greeting = "empty";
	string inquery = "NULL";
	string response = "NULL";

	Edmund userAI;
	userAI.DailyGreeting(greeting);

	std::cout << "What level of Sarcasm would you prefer?(0-10) " << endl;
	std::cin >> sarcasmLevel;
	userAI.SarcasmStatement(sarcasmLevel);


	do {
		std::cout << "I await your inqueires..." << endl;
		std::cin >> inquery;
		
		if (inquery == "help" || "Help" || "Emergency" || "911") {
		std:cout << "What kind of emergency are you having?" << endl;
		std:cin >> inquery;
			userAI.EmergencyAid(inquery, response);
		}
	} while (inquery != "Quit");
	return 0;
}

