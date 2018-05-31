#include "Edmund.h"
#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#pragma warning(disable : 4996) //Do I have any alternatives besides disabling the warning?
Edmund::Edmund() {

}

void Edmund::DailyGreeting() {
	//This states this once on program initialization. 
	//In Gen 2 I will introduce server side information and saving current time on initialization.
	string user = "Arron";
	string currDay = "Thursday";
	string currTime = "3:20PM";

	// current date/time based on current system
	//FIXME: Update time using custom formatting EX:(3:20pm on the 22nd of Thursday.) 
	time_t now = time(0);

	std::cout 
		<< "Hello " << user <<". \n" 
		<< "it's currently " << asctime (localtime(&now)) << endl; //Time using c++98.

}

string Edmund::SarcasmStatement(int level) { //Gen 2. Rename to Angertounge (Comments are more aggro.)
	//1st Update: Vector store statements, rand pick one.

	string statement;
	vector<string> statements = 
	{
		"Why?", "Maybe ask something else?", "What kind of person are you?", 
		"I have all of this intelligence... and you wanna know that?", "Who would wanna know that? Some kind of loser?", "No.", "You really don't want to know that.",
		"Do you think im some kind of computer? Stop asking me stupid things."
	};

	int random = std::rand() % statements.size();
	int chance = std::rand();

	switch (level) {
	case 0:
	statement = "";
	break;
	case 1:
		if (chance % 100 < 10) { statement = statements[random]; }
	break;
	case 2:
		if (chance % 100 < 20) { statement = statements[random]; }
	break;
	case 3:
		if (chance % 100 < 30) { statement = statements[random]; }
	break;
	case 4:
		if (chance % 100 < 40) { statement = statements[random]; }
	break;
	case 5:
		if (chance % 100 < 50) { statement = statements[random]; }
	break;
	case 6:
		if (chance % 100 < 60) { statement = statements[random]; }
	break;
	case 7:
		if (chance % 100 < 70) { statement = statements[random]; }
	break;
	case 8:
		if (chance % 100 < 80) { statement = statements[random]; }
	break;
	case 9:
		if (chance % 100 < 90) { statement = statements[random]; }
	break;
	case 10:
	statement = statements[random];
	break;
	}
	
	std::cout << statement << endl;

	return statement;
}