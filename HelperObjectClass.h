#ifndef HELPEROBJECTCLASS_H // include guard
#define HELPEROBJECTCLASS_H
//#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Originally from Quest.h
	class HelperObjectClass{
		protected:
		
		public:
		//Quest();
		//virtual std::string Objective = "Regular Quest";
		
		//virtual void polymorphismFunction();
		//void nonPolymorphismFunction();
		
		void displayCheckBoxes(std::vector<std::string>& ,std::vector<bool>&);
		bool flipBool(bool b);
		void displayBool(bool b);
		void createFile();
		void getHelp();
		int displayChoiceVector(vector<string>);
		int displayChoiceVectorWO(vector<string>, vector<int>);
		bool displayChoiceYN();
		/*
		virtual int area() = 0;
		* 
		* The =0 means there is no body for the base class and will only be called by subclasses.
      * */
	};


#endif
