#ifndef DIAPERQUEST_H // include guard
#define DIAPERQUEST_H
//#include <iostream>
#include "Quest.h"


	class DiaperQuest: public Quest{
		private:
		//                        bread, panini, steak;
		int consecDaysInDiaperDQ=-10;
		int totalDaysInDiaperDQ= 0;
		bool MaryInPartyDQ = false;
		bool wornDiaperBeforeDQ = false;
		
		//
		public:
		bool getMaryInPartyDQ();
		//std::string Objective = "Wear Diaper for 7 Days";
		void startQuest();
		bool currentlyInDiaperDQ = false;
		void polymorphismFunction();
		std::string getQuestName();
		void restartDiaperQuest();
		void giveUpDiaperQuest();
		void incDaysInDiaper();
		void setConsecDaysInDiaperDQ(int i);
		int getConsecDaysInDiaperDQ();
		void displayQuestObjective();
		void additionalQuestOverALL();
		int getTotalDaysInDiaperDQ();
		
	};

#endif
