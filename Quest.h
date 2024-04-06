#ifndef QUEST_H // include guard
#define QUEST_H
//#include <iostream>
#include <vector>
#include <string>

	class Quest{
		protected:
		
		std::string AYS1 = "You have nothing to gain. Are you sure2?\n";
		bool forceFinish = false;
		bool EarlyComplete = false;
		virtual void additionalQuestOver1();
		virtual void additionalQuestOver0();
		virtual void additionalQuestOverFail();
		virtual void additionalQuestOverALL();

		// PreTalked, In Progress, failed, complete
		std::vector<bool> standardElements = {false, false, false, false};
		
		public:
		//Quest();
		//virtual std::string Objective = "Regular Quest";
		void testLink();
		virtual void polymorphismFunction();
		void nonPolymorphismFunction();
		
		void preTalk();
		//void failQuest();
		void abandonQuest();
		void QuestOver(int i);
		
		bool getPreTalk();
		bool getQuestProgress();
		bool getQuestCompletedStatus();
		bool getQuestFailed();
		virtual void startQuest();
		virtual std::string getQuestName();
		virtual void displayQuestObjective();
		//virtual void handleQuestInteraction() = 0;
		
		/*
		//pure virtual function
		virtual int area() = 0;
		* 
		* The =0 means there is no body for the base class and will only be called by subclasses.
      * */
	};


#endif
