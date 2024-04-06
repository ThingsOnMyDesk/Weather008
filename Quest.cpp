#include "Quest.h" // header in local directory
#include <iostream> // header in standard library


using namespace std;



void Quest::testLink(){
    cout << "Link Works Succesfully!" << endl;
}

 void Quest::polymorphismFunction(){
	cout << "This is the polymorphism function of BASE class.\n The output should NOT be the same. 1111" << endl;
}

void Quest::nonPolymorphismFunction(){
	cout << "This is the non polymorphized function.\n The output should be the same." << endl;
}

void Quest::startQuest(){
		standardElements.at(1) = true;
		cout << getQuestName() << " Started!" <<endl;
	}
	
bool Quest::getQuestProgress(){
		return standardElements.at(1);
	}
	
	
	//Maybe rename to initialize
void Quest::preTalk(){
		standardElements.at(0) = true;
	}
bool Quest::getPreTalk(){
	return standardElements.at(0);
	}
	
	
	void Quest::abandonQuest(){
		standardElements.at(2) = true;
		standardElements.at(1) = false;
		QuestOver(-1);
	}

void Quest::QuestOver(int i){
	switch(i){
		case -1: standardElements.at(2) = true;
			cout << "Quest Failed. (" << getQuestName() << ")\n";
			standardElements.at(2) = true;
			standardElements.at(1) = false;
			additionalQuestOverFail();
		break;
		case 0:standardElements.at(3) = true;
			cout << "Quest Finished. (" << getQuestName() << ")\n";
			additionalQuestOver0();
		break;
		case 1:standardElements.at(3) = true;
			cout << "Quest Completed. (" << getQuestName() << ")\n";
			additionalQuestOver1();
		break;
		}
		
		additionalQuestOverALL();
	
		//
	}
	
bool Quest::getQuestCompletedStatus(){
			return standardElements.at(3);
		}
	
string Quest::getQuestName(){
		return "Generic Quest";
	}
	
bool Quest::getQuestFailed(){
		return standardElements.at(2);
	}

void Quest::displayQuestObjective(){
		cout << "" << endl;
	}
	
void Quest::additionalQuestOver1(){
	
}
void Quest::additionalQuestOver0(){
	
}
void Quest::additionalQuestOverFail(){
	
}
void Quest::additionalQuestOverALL(){

}
