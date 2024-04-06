#include "Quest.h" // header in local directory
#include <iostream> // header in standard library

#include "FoodQuest.h"
using namespace std;



void FoodQuest::polymorphismFunction(){
	cout << "This is the polymorphism function of BASE class.\n The output should NOT be the same. 2222" << endl;
}

string FoodQuest::getQuestName(){
		return "Food Quest";
	}
void FoodQuest::displayQuestObjective(){
		cout << "Get Food for the girl" << endl;
	}
bool FoodQuest::checkBJHungryGirl(bool inParty, bool diaper){
	if(inParty == true){
		standardElements.at(3) = true;
			cout << "\"You know they say that ounce per ounce, semen is extremely high in both\ncalories and protein.\"\n\n";
			cout << "\"Really?\"\n\n";
			
			if(diaper == true){
				cout << "She pulls down your pants and sees the diaper\n\n";
			cout << "\"Uhhh?\"\n\n";
			cout << "\"Don't worry Babe. I was talking about me.\"\n\n";
			cout << "Carla pulls out her massive cock. It's twice as long and twice as thick flaccid as yours is erect.\n";
			cout << "The hungry girl is in shock and awe. She starts guiding Carla's cock down her mouth.\n";
			cout << "Your actually surprised the whole thing fit.\n";
			cout << "She starts sucking. She sucks and sucks and sucks.\n";
			cout << "After a few minutes there's an explosion of semen, with cum shooting out of every orfice.\n";
			cout << "Carla pulls her semen covered cock out. More semen comes out with the cock than you would've ejaculated. \n";
			cout << "The girl has to swallow twice before she can speak. She gets up and thanks Carla for the experience.\n";
			cout << "She walks away swaying her hips. Her stomach looks a little bloated\n";
			cout << "\n";
			
			}else{
				cout << "She pulls down your pants and starts sucking your dick.\n";
				cout << "You cum in her mouth. She smiles and thanks you.\n";
			}
			QuestOver(1);
			
		}
	}
