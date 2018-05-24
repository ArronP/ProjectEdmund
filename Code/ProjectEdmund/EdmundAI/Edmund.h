#ifndef Edmund_H
#define Edmund_H
#include <string>

using namespace std;

class Edmund {
public:

	//Creates an object to establish what the user is attempting to do.
	//Program does not function unless "Edmund" Is stated prior to asking questions.
	//Program network is terminated once the user says/types "Thank you".
	Edmund();

	//Lighten the mood with snarky comments.
	int SarcasmLevel(int level);

	//Used for better visualizing what the user needs to do in order to help someone.
	string EmergencyAid(const string& inquery, const string& response);

	//Respond to the "Question" with the appropriate "Answer". All done via search requests.
	string Response(const string& question, const string& answer);

	//Once on initialization.
	void DailyGreeting();

	//Check the computer system stats. 
	//Eventually the Malware checking agent.
	void ComputerHealth();

	//Audio return for a simple text to speech.
	//If I have time I want my own Audio speech.
	void TextToSpeech();

private:
	string inquery = "Null";
	string response = "Null";

	string question = "Null";
	string answer = "Null";

	int level;
	int rGen;
};

#endif
