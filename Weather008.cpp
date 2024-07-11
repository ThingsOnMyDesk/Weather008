#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Quest.h"
#include "HelperObjectClass.h"
//#include "QuestSubGen.h"
#include "FoodQuest.h"
#include "DiaperQuest.h"
#include "LostGirl.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include "BeachQuest1.h" 
#include "Girl.h"

//g++ -o "Exe File Name" cppFile1 cppFile2;
//    -o allows you to give executable file a special name as opposed to a.out


using namespace std;
string DIALOGUE_PATH = "/home/pi/Documents/Actually Programmed Software/Weather Everything/Weather Code/V 006/Dialogue/";

bool HGInParty = false;
bool MaryInPartyMain = false;

bool overrideDisplayWhatBig1 = false;
int overrideDisplaySubLoc = -1;

int oddsOfWetting = 6;

ifstream infile; 
enum locations {town, forest};
enum sublocations {shopKeeper, couple, Diaper, Hungry, Lost};
vector <bool> availSubLocations = {true, true, true, true, true};
//Bread, Sandwhich, Steak, sword.
vector <bool> itemsPossesed = {false, false, false, false, false};
vector <string> itemsAll = {"Bread", "Sandwhich", "Steak", "Sword", "Panties"};

int gold = 10;

bool URwearingDiaper = false;
int consecDaysInDiaper = 0;
int timesWetDay = 0;
int timesWetNight = 0;

bool terminateGame = false;

void setUpVariables();
bool flipValue(bool b);

int currentSubLocation = 0;
int currentBroadLocation = 0;

int getUserInputMAIN(int q);

void displayBroadLocation();
void handleExplore();
void handleGoTo();
void handleInteractBIG();
void handleSleep();
void handleMenu();
void handleSave();
void handleLoad();
void resetGame();


//Quest Started/ Finished will be left in until we finish lost girl quest.

int displayChoiceYN();
int displayChoiceCustom(string, string);
int displayChoiceVector(vector<string>);


void displayWhatYouSeeBIG();
void foodHelperFunction();

void questChecker();

void customReadFile(string fileName);

	Quest Q;
	Quest* Qptr = &Q;
	//Qptr->testLink();
	FoodQuest FQ;
	FoodQuest* FQptr = &FQ;
	DiaperQuest DQ;
	DiaperQuest* DQptr = &DQ;
	LostGirl LG;
	LostGirl* LGptr = &LG;
	BeachQuest1 BQ1;
	BeachQuest1* BQ1ptr = &BQ1;
	vector<Quest*> FULL_LIST_OF_QUESTS = {FQptr, DQptr, LGptr};
	vector <bool> girlsInParty = {HGInParty, MaryInPartyMain};
	
bool firstTimeMenu = true;



int beachQuestStartingLocation = -1;

bool resetGameVar = false;
int main(){
	
	do{
	resetGameVar = false;
	terminateGame = false;
	cout << "The following Quests are currently under maintenence.\n";
	cout << "AJD: Recently been updating DQptr. May need to find/replace QuestStartFunction\n";
	Girl Girl1;
	
	srand(time(NULL));
	/*
	QuestSubGen QSG;
	QuestSubGen* QSGptr = &QSG;
	Qptr->nonPolymorphismFunction();
	QSGptr->nonPolymorphismFunction();
	
	Qptr->polymorphismFunction();
	QSGptr->polymorphismFunction();
	*/
	
	//While user has not terminated the game
		while(terminateGame == false){
		
		displayWhatYouSeeBIG();
		
		//guiMain gets input. If 1 repeat location
		int terminateInt = getUserInputMAIN(0);
		if(terminateInt == 1){
			continue;
			
			//If we either exit the game, or reset the game leave the inner loop.
			} else if(terminateInt== 6 || terminateInt ==55){
			break;
			}
			
		questChecker();
		
		terminateGame = false;
		cout << "AJD DEBUG: Made it to the end of loop. If it sill doesn't loop, Terminate Game = true;\n"; 
		}
	
	}while(resetGameVar == true && terminateGame == false);
	
	return 0;
}

	
bool flipValue(bool b){
	if(b == true){
			return false;
	}else{
			return true;			
	}
}

void displayBroadLocation(){
	
		switch(currentBroadLocation){
			case 0: cout << "You are in the Town\n";
			break;
			case 1: cout << "You are in the Forest\n"; 
			break;
			case 2: cout << "you are at the coast\n";
			break;
		}
			cout << "AJD Error: This location has not been programmed yet\n";
	
}
	
void displaySubLocation(){
	switch(currentSubLocation){
			case 0:{
				//probably need an if();
				cout << "Town streets (" << currentSubLocation << ")\n";
				break;
				}
				case 1:{
				cout << "You are at the shop (" << currentSubLocation << ")\n";
				break;
				}
				case 2:{
				cout << "You are at Mary's House (" << currentSubLocation << ")\n";
				break;
				}
				case 3:{
				cout << "You are where you found food girl (" << currentSubLocation << ")\n";
				break;
				}
				case 4:{
				cout << "You are where you found the lost girl (" << currentSubLocation << ")\n";
				break;
				}
				case 5:{
				cout << "You are at the port (" << currentSubLocation << ")\n";
				break;
				}
				case 6:{
				cout << "You are at the pier (" << currentSubLocation << ")\n";
				break;
				}
				case 7:{
				cout << "You are at the beach (" << currentSubLocation << ") \n";
				break;
				}
		}
	
	}

void handleExplore(){
	int townMin = 0;
	int townMax = 1;
	int forestMin = 2;
	int forestMax = 4;
	int COASTMIN = 5;
	int COASTMAX = 7;
		//if in town
		if(currentBroadLocation == 0){
			if (currentSubLocation == 0){
				currentSubLocation = 1;
			}else if(currentSubLocation == 1){
					currentSubLocation = 0;
			} else {
					cout << "AJD Error: There was a problem changing sub location\n";
			}
			
		//if in forest
		} else if(currentBroadLocation == 1){
			if (currentSubLocation == 2){
				currentSubLocation++;
			}else if(currentSubLocation == 3){
					currentSubLocation++;
			}else if(currentSubLocation == 4){
					currentSubLocation = 2;
			}else {
					cout << "AJD Error: There was a problem changing sub location\n";
			}
			
		//If you are in the coast		
		} else if(currentBroadLocation == 2){
		
			if(currentSubLocation == COASTMAX){
					currentSubLocation = COASTMIN;				
					
			}else{
					currentSubLocation++;
					/*
					switch(currentSubLocation){
							case 5: cout << "You are at the port.\n";
							break;
							case 6: cout << "You are at the pier.\n";
							break;
							case 7: cout << "You are at the beach.\n";
						}
						* */
			}
			
		}else{}
		
		
		
		
	}

void handleGoTo(){

		cout << "Where would you like to go?\n";
		cout << "1. The Town\n";
		cout << "2. The Forest\n";
		
		
		cout << "3. The coast (Not fully implemented yet)\n";
		cout << "4. cancel\n\n";
		int x;
		cin >> x;
		
		switch(x){
				case 1: 
				currentBroadLocation = 0;
				currentSubLocation = 0;
				break;
				case 2: 
				currentBroadLocation = 1;
				currentSubLocation = 2;
				break;
				case 3: 
				currentBroadLocation = 2;
				currentSubLocation = 5;
				break;
				default:;
		}
			
}

void handleSleep(){
	if(URwearingDiaper == true){
		if(oddsOfWetting <= 0){
		oddsOfWetting = 1;
		}
		int randVal = rand() % oddsOfWetting;
		cout << "Rand value = " << randVal << " \n";
		if(randVal == 0){
			cout << "You wet your diaper last night.\n";
			if(oddsOfWetting > 0){
				oddsOfWetting -= 2;
			}
		}else{
		cout << "You slept like a baby.\n";	
			}
		
		
		if(DQptr->getConsecDaysInDiaperDQ() < 0){
				DQptr->setConsecDaysInDiaperDQ(1);
		}else{
			DQptr->incDaysInDiaper();
		//consecDaysInDiaper++;
		}
		cout << "You have spent " << (DQptr->getConsecDaysInDiaperDQ()) << " consecutive days in a diaper\n";
	}else{
			cout << "You slept well last night.\n";
	}
}

int getUserInputMAIN(int q){
	cout << "What would you like to do?\n\n";
	
	if(firstTimeMenu == true){
			cout << "All options are available at all times (May or may not be implemented)\nOnly some are shown to save real estate.\n\n";
			firstTimeMenu = false;
	}
	
	if(q == 0){
	cout << "1. Where am I?\n";
	cout << "2. Explore\n";
	cout << "3. Go To\n";
	cout << "4. Interact\n";
	cout << "5. More\n";
	cout << "6. Exit Game\n";
	}else if(q== 1){
		cout << "7. Sleep\n";
				cout << "8. Menu\n";
				cout << "9. Save\n";
				cout << "10.Load\n";
				cout << "55. Reset\n";
				
				
				cout << "5. More Options\n";
	}else{
		cout << "AJD CRITICAL ERROR: FIX IF ELSE STATEMENT IN \'getUserInputMain\'.\n";
		}
	
	int x = 0;
	cin >> x;
	int lastVal = x;
	cout << "\n";
	switch(x){
		case 1: 
			displayBroadLocation();
			displaySubLocation();
			return 1;
			break;
			case 2: 
			handleExplore();
			break;
			case 3: 
			handleGoTo();
			break;
			case 4: 
				handleInteractBIG();
			break;
			case 5: 
			if(q == 1){
			q = 0;	
			}else{
			q=1;
			}
			return getUserInputMAIN(q);
			break;
				
			case 7:
			handleSleep();
			break;
			case 8:
			handleMenu();
			break;
			case 9:
			handleSave();
			break;
			case 10:
			handleLoad();
			break;
			case 55:
			resetGame();
			terminateGame = false;
			return 55;
			break;
			case 11:
			break;
					
				
			break;
			case 6: 
				terminateGame = true;
				return 6;
			break;
			
		
			return-2;
		}
		cout << "\n";
		return -1;
	}

void displayWhatYouSeeBIG(){
	
	
	//Ocean Sprouts
	if((overrideDisplayWhatBig1 == true) && (currentSubLocation == beachQuestStartingLocation)){
		cout << "You see a slightly irritated man.\n";	
		/////////////////////////////////////////////////////////////////
	}else if(true){
	
		switch(currentSubLocation){
		case 0:{
			if (LGptr->getQuestCompletedStatus() == false){
				cout << "You see what appears to be a very worried couple.\n";
			} else {
				cout << "You see nothing of interest.\n";
			}
		break;
	}
		case 1:{
			cout << "You see a store.\n";
			break;
		}
		case 2:{
			//Diaper
			if(DQptr->getQuestCompletedStatus() == true){
				
					cout << "You see nothing of interest.\n";
			}else if((DQptr->getQuestFailed() == true) && (DQptr->getQuestProgress() == false)){
				cout << "You see [Mary] at her cabin\n";
				
			}else if(DQptr->getQuestProgress() == true){
				cout << "You see nothing of interest.\n";
			}else if(DQptr->getPreTalk() == true){
				cout << "You see [Mary] at her cabin\n";
			}else{
					cout <<"You hear a rustling nearby.\n";
			}
		break;
	}
		case 3:{
			//Hungry Girl
			if(FQptr->getQuestCompletedStatus() == false){
				cout << "You see what appears to be a very hungry woman\n";
			}else{
				if(DQptr->getQuestProgress() == false && LGptr->getQuestCompletedStatus() == true){
					customReadFile("/home/pi/Documents/Actually Programmed Software/Weather Everything/Weather Code/V 006/Dialogue/Snake Bite/dialogue");
				}
				cout << "You see nothing of interest.\n";
			}
		break;
	}
		case 4:{
			//Lost Girl
			if(LGptr->getQuestProgress() == true && LGptr->getQuestCompletedStatus() == false){
				cout << "You hear what sounds to be fighting.\n";
			}else{
				cout << "You see nothing of interest.\n";
			}
			break;
		}
		case 5:{
			//
			cout << "You are at a port\n";
			
			
			break;
		}
		case 6:{
			//
			cout << "You are at a pier\n";
			
			
			break;
		}
		case 7:{
			//
			cout << "You are at a beach\n";
			
			
			break;
		}
		default:
			cout << "AJD It would appear there is an error with sublocations and\n \"Display What you See BIG\"";
		}
	}
}

void handleInteractBIG(){
	
	if(overrideDisplayWhatBig1 == true && currentSubLocation == beachQuestStartingLocation){
		string str = DIALOGUE_PATH + "/Beach/BeachQuest1MarysFriend";
		customReadFile(str);
		int y = displayChoiceYN();
		if(y ==1){
			BQ1ptr->startQuest();
			}
		
	}else if(true){
	
	int x;
		switch(currentSubLocation){
		case 0:{
			//Where the couple is.
			if (LGptr -> getQuestCompletedStatus() == false){
				if(LGptr -> getQuestProgress() == true ){
					cout << "We last saw our daughter running into the forest. Please go find her.\n";
				
					
					
					//cout << "You look like a big strong.\n";
				}else if(LGptr->getPreTalk() == true ){
					cout << "\"Have you decided to help us Hero?\"\n";
					cout << "Will you help the couple? \n\n 1. Yes\n 2. No\n";
					//int x;
					cin >> x;
					if (x == 1){
							//Display details of quest
							LGptr->startQuest();
	
					} else {
						cout << "\"Please let us know if you've changed your mind\"\n";
					}
					
				}else if(LGptr -> getPreTalk() == false ){
					cout << "\"Please Help us. Our Daughter ran away into that terrible forest.\n Please Bring her back to us safely.";
					cout << " We'll make sure to reward you handsomely.\"\n";
					cout << "Will you help the couple? \n\n 1. Yes\n 2. No\n";
					//int x;
					cin >> x;
					if (x == 1){
							//Display details of quest
							LGptr->startQuest();
							LGptr->preTalk();
							//findGirlConditions.at(0) = true;
							//findGirlConditions.at(1) = true;
							
					} else {
						cout << "\"Please let us know if you've changed your mind\"\n";
						LGptr->preTalk();
					}
				}
				
			} else {
				cout << "There's nothing to interact with.\n";
			}
		break;
	}
		case 1:{
			//Store
			cout << "You arrive at the shop. You have " << gold << " gold. What would you like to buy.\n";
			cout << "1. Bread 3 Gold\n2. Grilled Cheese 5 Gold \n3. Steak 10 Gold\n4.Sword 100 Gold\n5. Frilly Panties 15 Gold\n6. Leave\n";
			
			//int x;
			cin >> x;
			
			switch(x){
				case 1:
					if(gold >= 3){
					FQptr->foodOwned.at(0) = true;
					gold -= 3;
					} else {
					cout << "This item is too expensive\n";	
					}
				break;
				case 2:
					if(gold >= 5){
					FQptr->foodOwned.at(1) = true;
					gold -= 5;
					} else {
					cout << "This item is too expensive\n";	
					}
				break;
				case 3:
					if(gold >= 10){
					FQptr->foodOwned.at(2) = true;
					gold -= 10;
					} else {
					cout << "This item is too expensive\n";	
					}
				break;
				case 4:
					if(gold >= 100){
					itemsPossesed.at(3) = true;
					gold -= 100;
					} else {
					cout << "This item is too expensive\n";	
					}
				break;
					case 5:
					if(gold >= 15){
					itemsPossesed.at(4) = true;
					gold -= 15;
					//cout << "AJD: You bought the panties. Inventory may not be updated. See HandleInteractBig()\n";
					} else {
					cout << "This item is too expensive\n";	
					}
				break;
				}
			break;
		}
		case 2:{
			//Diaper
			if(DQptr->getQuestCompletedStatus() == true){
				
					cout << "There's nothing to interact with.\n";
			}else if(DQptr->getQuestFailed() == true && DQptr->getQuestProgress() == false){
				cout << "\"So, would you like to try again?\"\n1. Yes \n2. No\n";
				cin >> x;
				if(x == 1){
						cout << "\"Very well, same rules as before. You have to go seven days in your diaper.\"\n";
						cout << "She puts you in a diaper\n";
					
						DQptr->restartDiaperQuest(URwearingDiaper);
						URwearingDiaper = true;
						girlsInParty.at(1) =DQptr->getMaryInPartyDQ();
						/*
						consecDaysInDiaper = -2;
						DiaperQuestConditions.at(1) = true;
						URwearingDiaper = true;
						QuestStarted();
						//cout << "Debug: Line 340ish. DQC at 1 = " << DiaperQuestConditions.at(1) << " and DQC at 3 = " << DiaperQuestConditions.at(3)<<endl;;
						* */ 
				}else{
					cout << "\"Well you don't have to be such a big baby about it.\"\n";
				}
				
				
			}else if(DQptr->getQuestProgress() == true){
				cout << "There's nothing to interact with.\n";
			}else if(DQptr->getPreTalk() == true){
				cout << "\"So have you decided to take me up on my offer?\n";
				cout << "Agree to wear the diaper for one week?\n\n1. Yes\n2. No";
				cin >> x;
				if(x == 1){
						cout << "\"Very well. As mentioned before, you have to go seven days in your diaper.\"\n";
						cout << "She puts you in a diaper\n";
						cout <<"As she does so, she explains that the only time you are allowed to have\n";
						cout <<"your diaper removed is when she removes it, and only for the sole purpose of changing\n";
						
						DQptr->startQuest();
						
						URwearingDiaper = true;
						girlsInParty.at(1) =DQptr->getMaryInPartyDQ();
						
	
						
				}else{
					cout << "\"Well you don't have to be such a big baby about it.\"\n";
				}
			}else{
				
				customReadFile("/home/pi/Documents/Actually Programmed Software/Weather Everything/Weather Code/V 006/Dialogue/Diaper Quest 001/First Pre Talk");
				
				
				x = displayChoiceYN();
				if(x == 1){
						cout << "She puts you in a diaper\n";
						cout <<"As she does so, she explains that the only time you are allowed to have\n";
						cout <<"your diaper removed is when she removes it, and only for the sole purpose of changing\n";
						cout << "[Mary] has joined your party\n";
						
						DQptr->startQuest();
							URwearingDiaper = true;
						girlsInParty.at(1) =DQptr->getMaryInPartyDQ();
						/*
						URwearingDiaper = true;
						consecDaysInDiaper = -2;
						DiaperQuestConditions.at(1) = true;
						QuestStarted();
						* */
						//l
				}else{
					cout << "\"Well you don't have to be such a big baby about it.\"\n";
				}
				DQptr->preTalk();
			}
		break;
	}
		case 3:{
			bool breakOut = false;
			vector<string> choosableitems;
			//int x;
			//Hungry Girl
			if(FQptr->getQuestCompletedStatus() == false){
				//If the quest has not yet been completed
				
				if(FQptr->foodOwned.at(0) == true || FQptr->foodOwned.at(1) == true ||FQptr->foodOwned.at(2) == true ){
					//Do you have food? If yes, would you like to offer
				cout << "Would you like to offer this woman some food?\n\n1. Yes\n2. No \n";
					cin >> x;
					if(x == 1){
						//You offered food
							foodHelperFunction();
							break;
					}else{	}
					
				}else{
					//if you don't have any food
				}
				
					
					
						//If you decide not to offer her food.
						//You talk to her
				if(FQptr->getPreTalk() == false){
					//You haven't talked to her yet.
					
							cout << "\"Please sir, I'm so Hungry. I can't even make it back into town.\nWould you please help me? I'll pay you.\"\n";
							cout << "Help the girl?\n";
							//getFoodConditions.at(0) = true;
							FQptr->preTalk(); 
							x = displayChoiceYN();
							
							if(x == 1){
									cout << "\"Thank you. Here's 10 gold. Please hurry back.\"\n";
									gold += 10;
									//getFoodConditions.at(1) = true;
									//QuestStarted();
									FQptr->startQuest();
									if(FQptr->checkBJHungryGirl(girlsInParty.at(0), URwearingDiaper)){
									break;
								}
								
									
							}else{
									cout << "\"Um... Alright\"\n";
							}
				}else if (FQptr->getPreTalk() == true && FQptr->getQuestProgress() == false ){
					//You talked but denied the quest.
								cout << "\"Have you decided to help me?\"\n\n1. Yes. \n2. No";
								cin >> x;
							if(x == 1){
									cout << "\"Thank you. Here's 10 gold. Please hurry back.\"\n";
									gold += 10; 
									//getFoodConditions.at(1) = true;
								
									FQptr->startQuest();
									if(FQptr->checkBJHungryGirl(girlsInParty.at(0), URwearingDiaper)){
									break;
								}
							}else{
									cout << "\"Um... Alright\"\n";
							}
				}else if (FQptr->getQuestProgress() == true){
							cout << "\"Did you get any food? You can get some at the store in town.\"\n";
							if(FQptr->checkBJHungryGirl(girlsInParty.at(0), URwearingDiaper)){
									break;
								}
				}
					
					
					
					
					
				
				
			}else{
				
				cout << "There's nothing to interact with.\n";
			}
		break;
	}
		case 4:{
			//Lost Girl
			if(LGptr->getQuestProgress() == true ||LGptr->getQuestCompletedStatus() == false){
				customReadFile("/home/pi/Documents/Actually Programmed Software/Weather Everything/Weather Code/V 006/Dialogue/Lost Girl /Main Text");
				
				x = displayChoiceCustom("Turn in the Girl", "Don't turn in the Girl");
				
					//Make sure to include that's not necessarily a bad thing.
				//int x;
				//cin >> x;
				if (x == 1){
						cout << "You turned the girl into her parents. You recieve 75 Gold\n";
						LGptr->QuestOver(1);
						//QuestFinished(1, "(Lost Girl)");
						gold += 75;
						//LGptr-> = true;
						currentBroadLocation = 0;
						currentSubLocation = 0;
						
				}else{
					cout << "By selecting \"Don't turn in\" means you forefeit this quest and its reward\n";
					cout << "This is not necessarily a bad thing. Do you want to stick with your answer?\n\n1. Yes, stick with answer\n2. No, turn the girl in.\n";
					cin >> x;
					if (x == 1){
							cout << "You didn't turn the girl in. She has decided to join your party.\n";
					LGptr->QuestOver(0);
					girlsInParty.at(0) = true;
						//findGirlConditions.at(2) = true;
					}else{
						cout << "You turned the girl into her parents. You recieve 75 Gold\n";
						LGptr->QuestOver(1);
						gold += 75;
						//findGirlConditions.at(2) = true;
						currentBroadLocation = 0;
						currentSubLocation = 0;
					}
					
					
				}
				
			}else{
				cout << "There's nothing to interact with.\n";
			}
			break;
		}
		case 5:{
			//Handle SissyLandQuest();
			//Port
			
			
			break;
			}
		case 6:{
			//Pier
			
			break;
			}
		case 7:{
			//Beach
			string fileNameA = DIALOGUE_PATH + "Beach/Beach Dialogue 1";
			customReadFile(fileNameA);
			vector<string> options;
			bool inDiaper = URwearingDiaper;
			int choiceA;
			if(inDiaper){
				fileNameA = DIALOGUE_PATH + "Beach/BDialogue2";
				customReadFile(fileNameA);
				options = {"Strip all clothes", "Strip to diaper", "Leave"};
			choiceA = displayChoiceVector(options);
			// =========>Handle here
					if(choiceA == 1){
						if(true){
							cout << "AJD error: HandleInteractionBig: Pseudo virtual function below. You should rename.\n";
						}
						//DQptr->abandonQuest();
						DQptr->giveUpDiaperQuest(URwearingDiaper);
						cout << "You will not be able to find Mary's friend without Mary.\n\n";
						BQ1ptr->abandonQuest();
							URwearingDiaper = false;
					}else if(choiceA == 2){
						fileNameA = DIALOGUE_PATH + "Beach/BD3MarysFriend";
						customReadFile(fileNameA);
						cout << "AJD error: Inventory has not yet been updated\n";
					}else{
					}
			
			}else{
					cout << "What do you do?\n";
					options = {"Strip all clothes", "Leave"};
				choiceA = displayChoiceVector(options);
			}
			
			
			break;
			}
		default:
			cout << "AJD It would appear there is an error with sublocations and\n \"Interactions BIG\"";
		}
	}

}

void foodHelperFunction(){
	vector<string> choosableItems;
		int x;
					cout << "What would you like to give?\n\n";
					for(unsigned int i = 0, j = 1; i < FQptr->foodOwned.size(); i++){
						if(FQptr->foodOwned.at(i) == false){
								continue;
						}
						choosableItems.push_back(itemsAll.at(i));
						cout << j <<". " << itemsAll.at(i) << endl;
						j++;
					}
					cin >> x;
					x--;
					
					//X can only be a Max of 2.
					cout << endl;
					if(choosableItems.at(x) == "Bread" ){
						cout << "She thanks you for your kindness.\n";
						FQptr->QuestOver(1);
						//QuestFinished(1, "(Hungry Girl)");
					//gold += 10;
						//return 0;
					} else if (choosableItems.at(x) == "Sandwhich"){
						cout << "She is very thankful. She wants to give you a special reward.\n";
						if(URwearingDiaper == true){
								cout << "She pulls down your pants. \n\"Are you wearing a diaper?\"\n...\n";
								cout << "\"Look, thanks for the sandwhich but I'm going to get going.\"\n\n";
						}else{
								cout << "She pulls down your pants and starts sucking your dick.\nShe gives you some extra gold and leaves\n";
								gold += 10;
						}
						FQptr->QuestOver(1);
							//return 1;
					} else if (choosableItems.at(x) == "Steak"){
						cout << "She is extremely grateful. She wants to give you a special reward\n";
						if(URwearingDiaper == true){
								cout << "She pulls down your pants. \n\"Are you wearing a diaper?\"\n...\n\"Oh well whatever\"\n";
								cout << "Do you accept the BJ? \n\n1. Yes \n2. No\n";
								cin >> x;
								if (x == 1){
								cout << "She pulls off your diaper and starts sucking your dick.\nShe gives you your gold and leaves\n\n";
								gold += 10;
								FQptr->QuestOver(1);
								
									if(DQptr->getConsecDaysInDiaperDQ() < 7){
										DQptr->QuestOver(-1);
										cout << "Would you like to restart your diaper quest?\n\n1. Yes \n2. No\n";
										DQptr->setConsecDaysInDiaperDQ(-10);
								cin >> x;
										if (x == 1){
											//DQptr->failQuest();
											DQptr->restartDiaperQuest(URwearingDiaper);
											URwearingDiaper = true;
										} else {
											
											URwearingDiaper= false;
											cout << "[Mary] has left your party.\n";
										}
									}else{}
								}else{
									cout << "\"Whatever Diaper Boy.\"\nShe gives you your gold and leaves\n\n";
								gold += 10;
								FQptr->QuestOver(1);
								}
								
								
							//return 2;
					} else {
						cout << "She pulls down your pants and give you the best blow job of your life.\n";
						cout << "She gives you your gold and leaves\n\n";
								gold += 10;
					FQptr->QuestOver(1);
					}
				}
				
				
				FQptr->QuestOver(1);
				
				//getFoodConditions.at(2) = true;
				//getFoodConditions.at(3) = true;
					
}

void questChecker(){
	int x;
	// Pre Quest Talked, InProgress, 7 days, fail,  finished
	//             0          1        2       3      4
	if((DQptr->getQuestProgress() == true) && (DQptr->getQuestCompletedStatus() == false)){
		//cout << "AJD TEST: Quest is in Progress AND incomplete \n";
		if((DQptr->getConsecDaysInDiaperDQ() == -2)){
			//cout << "AJD TEST: diaper days = -2 but will immediately increment \n";
		DQptr->incDaysInDiaper();
		} else if((DQptr->getConsecDaysInDiaperDQ()== -1) && (DQptr->getQuestFailed() == false)) {
			DQptr->incDaysInDiaper();
			customReadFile("/home/pi/Documents/Actually Programmed Software/Weather Everything/Weather Code/V 006/Dialogue/Diaper Quest 001/Diaper Rules One Time");

			
		}else if(DQptr->getConsecDaysInDiaperDQ() == 6){
			cout << "As you and [Mary] are sitting by the campfire, she says\n";
			cout << "\"I've really enjoyed spending these last few days with you.\n";
			cout << "I hope it hasn't been too bad. You know you've given me a lot of entertainment lately\n";
			cout << "If you take off your diaper, maybe I'll entertain you.\"\n";
			cout << "Do you take off your diaper?\n\n1. Yes\n2. No\n";
			cin >> x;
			
			if (x == 1){
						cout << "You take off your diaper and toss it aside\n";
						cout << "She gets in real close. You can feel her breath on your neck\n";
						cout << "She angrily SMACKS you in the balls\n";
						cout << "\"I EXPLICITLY TOLD YOU, UNDER NO CIRCUMSTANCES, DO YOU REMOVE YOUR DIAPER!\"\n";
						
						DQptr->giveUpDiaperQuest(URwearingDiaper);
						cout << "Would you like to restart?\n\n1. Yes \n2. No\n";
										//consecDaysInDiaper = -2;
								cin >> x;
										if (x == 1){
											DQptr->restartDiaperQuest(URwearingDiaper);
											URwearingDiaper = true;
										
										} else {
											DQptr->giveUpDiaperQuest(URwearingDiaper);
											cout << "[Mary] has left your party.\n";
											URwearingDiaper = false;
										}
			}else{
				cout << "You passed my test. Good job. One more day.\n";
			}
			
		}else if(DQptr->getConsecDaysInDiaperDQ() >= 7){
			DQptr->QuestOver(1);
			//QuestFinished(1, "(Diaper)");
			//DiaperQuestConditions.at(4) = true;
			//URwearingDiaper = false;
			
			cout << "[Mary] removes your diaper and gives you a sword.\n";
			itemsPossesed.at(3) = true;
			cout << "[Mary] has left your party. (NOTE: this has NOT been programemd)\n";
			URwearingDiaper = false;
		} else {
				//cout << "AJD TEST: Nothing passed, relevant variables are: \n";
		}
		
	}
	
	if((DQptr->getQuestProgress() == true )&& (DQptr->getQuestCompletedStatus() == false) ){
		cout << "Total days in diaper is = " << DQptr->getTotalDaysInDiaperDQ() << endl;
		if((DQptr->getConsecDaysInDiaperDQ() >= 3) && (BQ1ptr->getQuestProgress() == false)) {
		
		
		//cout << "AJD DEBUGGING: Consec days in diaper." << DQptr->getConsecDaysInDiaperDQ() << endl;
		
		//&& (currentSubLocation != 7)){
			//getConsecDaysInDiaperDQ() in diaper
			//Notice how its Diaper Quest and Beach quest
			
			overrideDisplayWhatBig1 = true;
			if(beachQuestStartingLocation == -1){
				beachQuestStartingLocation = currentSubLocation;
			}
			
		}else{
			overrideDisplayWhatBig1 = false;
		}
		
	}else{
			overrideDisplayWhatBig1 = false;
	}
}


	
void QuestFinished(int i, string s){
	if(i == 0){
	cout << "\nQUEST FINISHED! " << s <<"\n\n";
	} else if(i == -1){
	cout << "\nQUEST FAILED! " << s <<"\n\n";
	} else if(i == 1){
	cout << "\nQUEST COMPLETE! " << s <<"\n\n";
	}
}

int displayChoiceYN(){
	cout << "\n1. Yes\n2. No\n";
	int x;
	cout << endl;
	cin >> x;
	
	return x;
	}
int displayChoiceCustom(string s1, string s2){
		cout << "\n1. " << s1 << "\n2. " <<s2<<"\n";
	int x;
	cout << endl;
	cin >> x;
	return x;
}

int displayChoiceVector(vector<string> v){
	for(unsigned int i = 0; i < v.size(); i++){
	cout << "\n" << (i+1) <<" "<< v.at(i);
	}
	int x;
	cout << endl;
	cin >> x;
	return x;
}

void handleMenu(){
		vector<string> options = {"Quests", "Party", "Nevermind"};
		int x = displayChoiceVector(options);
		
		switch(x){
				case 1:{
					vector<string> currentQuests;
					for(int i = 0; i < FULL_LIST_OF_QUESTS.size(); i++){
					if(FULL_LIST_OF_QUESTS.at(i)->getQuestProgress() == true){
							currentQuests.push_back(FULL_LIST_OF_QUESTS.at(i)->getQuestName());
						}	
					}
					x = displayChoiceVector(currentQuests);
					
					if((x < 1) || (x > currentQuests.size())){
							cout << "Unacceptable Input, returning to main menu.\n";
							break;
					}
					
					for(int i = 0; i <FULL_LIST_OF_QUESTS.size(); i++ ){
						//We search all quests to find out, which quest to look at.
					
					if(currentQuests.at(x-1) == FULL_LIST_OF_QUESTS.at(i)->getQuestName()){
							cout << "1. Objectives\n2. Help\n3. Abandon\n4. Nevermind\n";
							cin >> x;
							cout << endl;
							switch(x){
									case 1:
									FULL_LIST_OF_QUESTS.at(i)->displayQuestObjective();
									break;
									case 2:
									cout << "Go to store and buy food.\nThis is currently HARD CODED.\n";
									break;
									case 3:
									FULL_LIST_OF_QUESTS.at(i)->abandonQuest();
									break;
							}
							//Break out of for loop.
							break;
						}
					
					}
					
					
					
				//Display Quests
				//Nested switch for each quest
						//choice 1 cancel/Abandon choice 2. What's my objective (expanded upon for more complex quests)? 3. Help. 4. Nevermind
					break;
				}
				case 2:{
					cout << "Total options for girls in party is: " << girlsInParty.size() <<endl;
				for(int i = 0, j = 1; i < girlsInParty.size(); i++){
						if(girlsInParty.at(i) == true){
								cout << j << ". MARY HARDCODE\n";
						}else{
							cout <<". Output did NOT return true\n";
							cout <<"Output was = " << girlsInParty.at(i)<<endl;
						}
					}
				//Display Party Members
					//Talk (not yet imp)
					//Inventory (not yet imp)
					//Nevermind;
				break;
			}
		}
}

void customReadFile(string s){
	infile.open(s);
				
				
				
				string strDiap;
				char character = '1';
				char char2;
				while (infile.get(character)){
					if (character == '\n' && char2 == '\n'){
							cin.ignore();
					}
					cout << character;
					char2 = character;
				}
				cout <<endl;
	infile.close();
}
//

void handleSave(){
	cout << "Which file would you like to use?\n";
	for (int i = 0; i < 5; i++){
		cout << "Save " << i+1 <<endl;
	}
	cout << "AJD: Hardcoded. Defaulting to Save1" << endl;
	ofstream fileX;
	fileX.open("/home/pi/Documents/Actually Programmed Software/Weather Everything/Weather Code/V008/EXEFolder/Saves/Save1.csv");
	//clears contents, Note: to overwrite, use all paramters
	fileX << currentBroadLocation <<","<< currentSubLocation << "," << gold;
	fileX.close();
	cout << "file saved successfully.\n";
}
void handleLoad(){
	cout << "AJD: Hardcoded save file1" << endl;
	fstream fstr;
	fstr.open("/home/pi/Documents/Actually Programmed Software/Weather Everything/Weather Code/V008/EXEFolder/Saves/Save1.csv",ios::in);
	string temp="";
	string val = "";
	int count = 0;
	while(fstr.good()){
		getline(fstr,val,',');
		
		switch(count){
			case 0: 
				currentBroadLocation = stoi(val);
			break;
			case 1:
				currentSubLocation = stoi(val);
			break;
			case 2:
				gold = stoi(val);
			break;
		}
		count++;
	}
	 
	 cout << "AJD: Load complete.";
	 
	}
	
void resetGame(){
	
DIALOGUE_PATH = "/home/pi/Documents/Actually Programmed Software/Weather Everything/Weather Code/V 006/Dialogue/";

HGInParty = false;
MaryInPartyMain = false;

overrideDisplayWhatBig1 = false;
overrideDisplaySubLoc = -1;

oddsOfWetting = 6;

 
//enum locations {town, forest};
//enum sublocations {shopKeeper, couple, Diaper, Hungry, Lost};
availSubLocations = {true, true, true, true, true};
//Bread, Sandwhich, Steak, sword.
itemsPossesed = {false, false, false, false, false};
itemsAll = {"Bread", "Sandwhich", "Steak", "Sword", "Panties"};

int gold = 10;

 URwearingDiaper = false;
 consecDaysInDiaper = 0;
 timesWetDay = 0;
 timesWetNight = 0;

 terminateGame = false;




 currentSubLocation = 0;
 currentBroadLocation = 0;




//Quest Started/ Finished will be left in until we finish lost girl quest.
/*
	Quest Q;
	Quest* Qptr = &Q;
	//Qptr->testLink();
	FoodQuest FQ;
	FoodQuest* FQptr = &FQ;
	DiaperQuest DQ;
	DiaperQuest* DQptr = &DQ;
	LostGirl LG;
	LostGirl* LGptr = &LG;
	BeachQuest1 BQ1;
	BeachQuest1* BQ1ptr = &BQ1;
	* */
	FULL_LIST_OF_QUESTS = {FQptr, DQptr, LGptr};
	girlsInParty = {HGInParty, MaryInPartyMain};
	
firstTimeMenu = true;



beachQuestStartingLocation = -1;
resetGameVar = true;
}



