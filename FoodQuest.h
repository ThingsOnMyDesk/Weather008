#ifndef FOODQUEST_H // include guard
#define FOODQUEST_H
//#include <iostream>
#include "Quest.h"


	class FoodQuest: public Quest{
		private:
		//                        bread, panini, steak;
		//
		public:
		//std::string Objective = "Get food for girl";
		void polymorphismFunction();
		std::vector<bool> foodOwned = {false, false, false};
		std::string getQuestName();
		void displayQuestObjective();
		bool checkBJHungryGirl(bool b, bool d);
	};

#endif
