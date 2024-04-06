#include "Quest.h" // header in local directory
#include <iostream> // header in standard library

#include "BeachQuest1.h"
using namespace std;



string BeachQuest1::getQuestName(){
		return "Beach Quest";
	}
	
	
void BeachQuest1::displayQuestObjective(){
		cout << "Get Ocean Sprouts" << endl;
	}

void BeachQuest1::startQuest(){
		cout << getQuestName() << " Started!" <<endl;
		standardElements.at(1) = true;
	}
