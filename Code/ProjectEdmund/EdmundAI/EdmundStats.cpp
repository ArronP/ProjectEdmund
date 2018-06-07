#include "Edmund.h"
#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override something,
//but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <atlconv.h>
#include <sapi.h>
#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#pragma warning(disable : 4996) //Do I have any alternatives besides disabling the warning?
Edmund::Edmund() {

}

string Edmund::DailyGreeting(string greeting) {
	//This states this once on program initialization. 
	//In Gen 2 I will introduce server side information and saving current time on initialization.
	time_t now = time(0);

	string user = "Arron";
	string currDay = "Thursday";
	string currTime = "3:20PM";
	greeting = "Hello " + user + ". \n"
		+ "it's currently " + asctime(localtime(&now));

	// current date/time based on current system
	//FIXME: Update time using custom formatting EX:(3:20pm on the 22nd of Thursday.) 

	std::cout << greeting << endl; //Time using c++98.
	TextToSpeech(greeting);

	return greeting;

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

wstring Edmund::Conversion(const string& output) {
	int len;
	int slength = (int)output.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, output.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, output.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
} //For use with converting string to WSstring and WString to LPCWSTR.

int Edmund::TextToSpeech(string output) {
	wstring stemp = Conversion(output);
	LPCWSTR result = stemp.c_str();

	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		hr = pVoice->Speak(result, 0, NULL); //FIXME: Convert String type in order to speak 'Output'.

		pVoice->Release();
		pVoice = NULL;
	}
	::CoUninitialize();
	return TRUE;
}