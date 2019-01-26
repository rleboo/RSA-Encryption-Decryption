// This program decrypts encrypted text and coverts them(from numbers) to words
//
#include <iostream>
#include <fstream>
#include <math.h>
#include <fstream>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"



using namespace std;


int main(int argc, char* argv[])
{
	/* Input files and their order
	 * 1st: private.txt
	 * 2nd: encrypted.txt
	 * 3rd: decrypted.txt
	*/
  
  
	ifstream fin(argv[1]);

	
	string dcryp; //This is d
	string nu; //This is n
	fin >> dcryp;
	fin >> nu;

	ReallyLongInt dcrypt(dcryp);
	ReallyLongInt num(nu);


	ifstream inpt(argv[2]);
	ofstream decrypt(argv[3]);
	
	unsigned long long encryptedNum;
	ReallyLongInt numMessage;

		
	while(inpt >> encryptedNum)
	  {
	    ReallyLongInt encrypt(encryptedNum);
	    numMessage = modPower(encrypt, dcrypt, num);
	    long long longMessage = numMessage.toLongLong();
	    char mes = (char)longMessage;
	    decrypt << mes;
	  }
    
	
}
