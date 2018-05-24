#include "Edmund.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
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