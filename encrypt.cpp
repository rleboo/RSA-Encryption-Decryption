// Program that encrypts user input using modPower
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <fstream>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"
//Uses modPower from numberTheory


using namespace std;


int main(int argc, char* argv[])
{
	
	
	/* Input files and their order
	 * 1st: public.txt
	 * 2nd: plaintext.txt
	 * 3rd: encrypted.txt
	*/
	
	
	ifstream fin(argv[1]);
	//Gets user first user input after ./encrypt
	
	string ex; //This is e
	string nu; //This is n
	
	fin >> ex;
	fin >> nu;

	ReallyLongInt exp(ex);
	ReallyLongInt num(nu);

	ifstream inpt(argv[2]);
	ofstream encrypt(argv[3]);


	char c;
	//unsigned long long newNumb; 
	while (inpt.get(c))
	{
	  int real = int(c);
	  ReallyLongInt newNumb = modPower(ReallyLongInt(real), exp, num);
	  encrypt << newNumb << endl;
	}
}
