#ifndef BEACHQUEST1_H // include guard
#define BEACHQUEST1_H
//#include <iostream>
#include "Quest.h"


	class BeachQuest1: public Quest{
		private:
		//                        bread, panini, steak;
		
		public:
		//std::string Objective = "Get food for girl";
		
		void startQuest();
		std::string getQuestName();
		void displayQuestObjective();
	//
	};

#endif
