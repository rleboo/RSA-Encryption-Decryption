
#include <iostream>
#include <math.h>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"
#include <fstream>
#include <string>


using namespace std;


int main(int argc, char* argv[])
{
  

  ReallyLongInt primeOne(argv[1]);
  ReallyLongInt primeTwo(argv[2]);

  // int primeOne = atoi(argv[1]);
  // int primeTwo = atoi(argv[2]);
  // May not be the best way
  
 

  ofstream fileOne(argv[3]);
  //This is public.txt
  
  ofstream fileTwo(argv[4]);
  //This is private.txt
 
 
  cout<< "You printed these : "<< primeOne << " numbers " << primeTwo<< endl;

  if(primeOne >  100000 || primeTwo > 100000)
    {
      cout << "Primaility is not being verified. Number too large. :" << endl;
    }
  else if (!isPrime(primeOne) || !isPrime(primeTwo))
    {
      cout << "One or both of your numbers aren't prime: ERROR " << endl;
      return 1;    
    }
  
  //1st input file is public
  //2nd input file is private

  ReallyLongInt n = primeOne * primeTwo;
  ReallyLongInt t = (primeOne -1)*(primeTwo -1);
  ReallyLongInt e;

  ReallyLongInt px;
  ReallyLongInt py;
  ReallyLongInt d;

  
  ReallyLongInt temp;
  ReallyLongInt x(1);
  
  while(temp != 1)
    {
      ++x;
      temp = extendedEuclid(x, t, &px, &py);
    }
   d = px;
   e = x;

  if(d < 0)
  {
    d += t;
  }
  
  fileOne << e << " " << n <<endl;
  fileTwo << d << " " << n <<endl;
  

  //Public file should contain e and n
  //Private file should contain d and n

  
}
