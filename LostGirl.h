#ifndef LOSTGIRL_H // include guard
#define LOSTGIRL_H
//#include <iostream>
#include "Quest.h"


	class LostGirl: public Quest{
		private:
		//
		//                        bread, panini, steak;
		//bool girlIsInParty = false;
		public:
		//std::string Objective = "Find the Girl";
		void polymorphismFunction();
		std::string getQuestName();
		void displayQuestObjective();
		//bool getGirlIsInParty(){return girlIsInParty;}
		bool setGirlIsInParty();
	};

#endif
