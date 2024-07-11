#ifndef GIRL_H // include guard
#define GIRL_H
//#include <iostream>
#include <vector>
#include <string>

using namespace std;
	class Girl{
		private:
		bool likesCock;
		bool likesPussy;
		bool hasPenis = false;
		int penisSize = 0;
		int height;
		string name;
		
		string intro = "";
	
		vector<string> vBreastSize = {"B", "C", "D", "DD", "E"};
		enum eBreastSize {B, C, D, DD, E, Last};
		enum Archetype {emo, cowgirl, tomboy, cop, nurse, witch, Muscular, Toned, goth };
		enum eBodyType {Slim, ExtraSlim, Regular, Thicc };
		vector<string> vBodyType {"Slim", "ExtraSlim", "Regular", "Thicc" };
		enum personality {Peppy, submissive, dominant, Slutty, Clingy, Distant};
		//vector<string> =
		
		string strBS;
		string strBT;
		int feet;
		int inches;
		string type;
		
		//Uses ints b/c in inches
		//string calculateSize(int);
		string fromHeight(int);
		void setName();
		void setIntro();
		void introduceSelf();
		
		//i.e. if name can't be processed correctly, - Witch.
		//if name comes with special intro, add special intro.
		void regOverride();
		
		public:
		//Guarantees at least one girl, has penis, likes girl, likes cock, etc. (NOTE: SHould only affect the last girl
		Girl();
		static void FinalOverrideAndCleanUP(Girl[]);
		string getName();
		string getStringHeight();
		int getHeight();
		string getBreastSize();
		//string getType();
		int getSexualityExternal();
		string getType();
		void reset();
		//void setEnum(enum &e);
		
	};

#endif
