#include "/home/pi/Documents/Actually Programmed Software/Austin's Custom Library/HelperObjectClass.h"
//#include "HelperObjectClass.h" // header in local directory
#include <iostream> // header in standard library
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void HelperObjectClass::displayCheckBoxes(std::vector<std::string>& options, std::vector<bool>& values){
		int input = -2;
	do{
	//Goes through all options that we can turn on or off
	std::cout << std::endl;
	for (int i = 0, counter = 1; i < options.size();i++, counter++){
			std::cout << counter << ". " << options.at(i);
			
			//Adds spaces to give uniformity to options.
			for(int j = options.at(i).size(); j < 20; j++){
				std::cout << " ";
			}
			
			std::cout << "[";
			displayBool(values.at(i));
			std::cout << "]\n";
	} 
	std::cout << "\nType the number to turn the test on or off.\n";  
	std::cout << "Type -1 to leave.\n";
	std::cin >> input;  
	
	if(input > values.size() || input <= 0){
		continue;
	}
	
	
	if(input != -1){
		values.at((input-1)) = flipBool(values.at((input-1)));
	}
	}while(input != -1);
}

void HelperObjectClass::displayBool(bool b){
		if (b == true){
				std::cout << "ON ";
			}else{
				std::cout << "OFF";
			}
}

bool HelperObjectClass::flipBool(bool b){
	if(b == true){
		b = false;
	}else{
		b = true;
	}
	return b;
}

void HelperObjectClass::createFile(){
	std::cout << "Please input filepath name.\n";
	std::cout << "(Linux) File name should start with / and end with file extension.\n";
	std::cout << "(Windows) File name should start with C:/ and end with file extension.\n";
	
	std::string filePathName;
	//std::getline (std::cin,filePathName);
	
	//std::ofstream myFile(filePathName);
	
	}
	
void HelperObjectClass::getHelp(){
		//A library to help you find info on particular topics
		
		//Get full line
		//Skip input/ Use enter as command
		
		
	}
/*
int HelperObjectClass::displayChoiceCustom(string s1, string s2){
		cout << "\n1. " << s1 << "\n2. " <<s2<<"\n";
	int x;
	cout << endl;
	cin >> x;
	return x;
}
* */

//NOTE::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//No static on declaration
 int HelperObjectClass::displayChoiceVector(vector<string> v){
 
	for(unsigned int i = 0; i < v.size(); i++){
	cout << "\n" << (i+1) <<" "<< v.at(i);
	}
	int x;
	cout << endl <<endl;
	cin >> x;
	return x;
}

int HelperObjectClass::displayChoiceVectorWO(vector<string> v1, vector<int> pos ){

	for(unsigned int i = 0, z = 0; i < v1.size(); i++, z++){
	bool continueOuterLoop = false;
		for(int j = 0; j< pos.size(); j++){
			if( i == pos.at(j)){
				continueOuterLoop = true;
			}
		}
		if(continueOuterLoop){
			z--;
			continue;
		}
	cout << "\n" << (z+1) <<" "<< v1.at(i);
		
	}
	int x;
	cout << endl <<endl;
	cin >> x;
	return x;
}

 bool HelperObjectClass::displayChoiceYN(){
 
	int x;
	for(unsigned int i = 0; i < 2; i++){
	cout << "\n" << (i+1);
		if(i == 0){
			cout << " Yes";
		
		}else{
			cout << " No";
		}
	}
	
	cout << endl <<endl;
	cin >> x;
	if(x == 1){
			return true;		
	}else{
			return false;
	}
	
}
