#include "Quest.h" // header in local directory
#include <iostream> // header in standard library

#include "LostGirl.h"
using namespace std;



void LostGirl::polymorphismFunction(){
	cout << "This is the polymorphism function of BASE class.\n The output should NOT be the same. 2222" << endl;
}

string LostGirl::getQuestName(){
		return "Lost Girl";
	}
void LostGirl::displayQuestObjective(){
		cout << "Find the Lost Girl" << endl;
	}
bool LostGirl::setGirlIsInParty(){
		//girlIsInParty = true;
	}
