#include "Quest.h" // header in local directory
#include <iostream> // header in standard library

#include "DiaperQuest.h"
using namespace std;



void DiaperQuest::polymorphismFunction(){
	cout << "This is the polymorphism function of BASE class.\n The output should NOT be the same. 2222" << endl;
}

void DiaperQuest::startQuest(){
	standardElements.at(1) = true;
		cout << getQuestName() << " Started!" <<endl;
		consecDaysInDiaperDQ = -2;
		currentlyInDiaperDQ = true;
		MaryInPartyDQ = true;		
	}

string DiaperQuest::getQuestName(){
		return "Diaper Quest";
	}
	
void DiaperQuest::restartDiaperQuest(){
			startQuest();
			standardElements.at(2) = true;
				
}

void DiaperQuest::incDaysInDiaper(){
	consecDaysInDiaperDQ++;
	totalDaysInDiaperDQ++;
}

void DiaperQuest::setConsecDaysInDiaperDQ(int i){
	consecDaysInDiaperDQ = i;
	}

int DiaperQuest::getConsecDaysInDiaperDQ(){
	return consecDaysInDiaperDQ;
	}
	
void DiaperQuest::giveUpDiaperQuest(){
	standardElements.at(1) = false;
	standardElements.at(2) = true;
	currentlyInDiaperDQ = false;
	consecDaysInDiaperDQ = -10;
	MaryInPartyDQ = false;
	cout << "Mary has left your party\n";
	Quest::QuestOver(-1);
	}
void DiaperQuest::displayQuestObjective(){
		cout << "Wear Diaper for 7 days." << endl;
	}

void DiaperQuest::additionalQuestOverALL(){
	currentlyInDiaperDQ = false;
	MaryInPartyDQ = false;
	}
	
	bool DiaperQuest::getMaryInPartyDQ(){
			return MaryInPartyDQ;
		}
		
int DiaperQuest::getTotalDaysInDiaperDQ(){
			
return totalDaysInDiaperDQ;
}
