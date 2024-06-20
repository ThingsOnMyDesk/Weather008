#include "Girl.h"
#include <iostream>
#include <string>
#include <time.h>  
#include <stdlib.h>  
#include <fstream>
/*
 * enum my_type {
    a, b, c, d,
    last
};

void f() {
    my_type test = static_cast<my_type>(rand() % last);
}
* 
* 
* ///This may also work
* 
* my_type test = my_type(rand() % 10);

 * 
 * */

using namespace std;
Girl::Girl(){
	srand(time(NULL));
	
	//cock
	int a = rand()%2;
	//a = 1;
	//pussy
	int b = rand()%2;
	//b = 1;
	//futa
	int c = rand()%3;
	// Breast Size
	//eBreastSize bS = eBreastSize->at(rand() % eBreastSize->Last);
	string strBS = vBreastSize.at(rand()% vBreastSize.size());
	
	string strBT = vBodyType.at(rand()% vBodyType.size());
	//Sets sexuality
	cout << "a = " << a <<". B = " << b <<endl;
	
	if( a == 0 && b == 0){
			a =1;
			cout << "Both a and b are 0;\n overriding a = 1\n";
	}
	
	if(a ==1){
		likesCock = true;
	}else{
		likesCock = false;
	}
	
	if(b ==1){
		likesPussy = true;
	}else{
		likesPussy = false;
	}
	
	
	//Sets Futa
	if(c ==0){
		hasPenis = true;
		int adjuster = rand()%12;
		penisSize = rand()%5 + 3 +adjuster;
	}else{
		hasPenis = false;
	}
	
	
	//Sets Height
	height = rand()%48+48;
	int feet = height/12;
	int inches = height%12;
	
	
	//Sets Name 
	setName();
	//name = "Brittany";
	
	if(strBT != "Regular"){
			cout << "You see a rather " << strBT << " girl." <<endl;
	}
	
	cout << "AJD DEBUG: Hi my name is " << name <<endl;

	
	string sexuality;

	//cout.flush();
	//cout <<"";
	//string s = "Hi! I'm ";
	//s += name;
	//s+= ". I'm just here for testing purposes. I'm " ;

	
	std::cout << "Hi I'm ";
	//cout.flush();
	cout << name;
	cout << "name .size is " << name.size() <<endl;;
	cout << "HELLO> PLEASE DELETE THIS LINE. " <<endl;
	////cout.flush();
	//ostream ostr;
	//ostr << name;
	cerr;
	
		if(likesCock == true && likesPussy == true){
		sexuality = "I'M BISEXUAL";
	}else if(likesCock == true){
		sexuality = "I LOVE COCK";
	}else{
		sexuality = "I LOVE PUSSY";
	}
	cout << "Hi I'm ";
	cout << name;
	cout << ". ";
	cout <<" I'm just here for testing purposes. I'm " << feet << "' "<< inches <<"\" and my breast size is " << strBS << ". " << sexuality <<". \n"  ; 
	if(hasPenis){
		cout <<"Wow. Look at my massive cock! It's " << penisSize << " inches!\n";
	}
	
	
}

void Girl::setName(){
	ifstream fstr;
	string strLine = "";
	fstr.open("./Girls Names.txt");
	int size = 0;
	
	char c ='n';
	
	while(fstr.get(c)){
		if(c == '\n'){
		size++;
		}
	}
	
	/**
	 *while(getline(fstr, strLine)){
		size++;
	} 
	 * 
	 * 
	 * */
	//getline(fstr,strLine);
	
	//cout << size <<"\n";
	int lineNumber = rand()%size;
	cout << "lineNumber is "<< lineNumber <<endl;
	//int lineNumber = 4;
	fstr.close();
	fstr.open("./Girls Names.txt");
	
	int index = 0;
	while(index<lineNumber){
		
		getline(fstr, strLine);
		index++;
	}
	getline(fstr, strLine);;
	fstr.close();
	string name2 = strLine;
	string name3 = "";
	for(int i = 0; i <name2.size()-1; i++){
		name3 += name2.at(i);
	}
	name = name3;
//	return strLine;
	
	
	
	
}

/*
 * 
 * void customReadFile(string s){
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
 * 
 * */

/*
string Girl::calculateSize(int h){
	int newH = h/12;
	int newInches = h%12;
	string heightString = newH << "' " <<newInches <<"\"";
	return heightString;
	}
*/
