#include <math.h>
#include <iostream>

template <class X>
bool isPrime(const X& num)
{

	if (num == 1 ||	num == 0)
	  {
	    return false;
	  }

	if (num == 2)
	  {
	    
	    return true;
	  }

	for (int x = 2; x <= num/2; x++) 
	  {
	    if (num % x == 0)
	      {
	      return false;
	      }
	  }
	return true;	

}

template <class X>
X modPower(const X& base, const X& exponent, const X& modulus)
{
	//Remove floor(exponent/ 2);
	//long long recursion = exponent/ 2;
  
  if (exponent == 0)
    {
      return 1;
    }
  else if (exponent % 2 == 0)
    {

      X mod = modPower(base, exponent / 2, modulus);
      return (mod * mod) % modulus;
    }
  
  else
    {
      X mod = modPower(base, exponent / 2, modulus);
      return ((base * mod % modulus)* mod) % modulus;
    }	

}

template <class X>
X extendedEuclid(const X& a, const X& b, X* x, X* y)
{
  if(b == 0)
    {
      *x = 1;
      *y = 0;
      return a;
    }	         
  else	  
   {
      X temp = extendedEuclid(b, a % b, x, y);
      X px = *y;
      X py = *x - *y * (a/b);
      *x = px;
      *y = py;
      return temp;
   }
   
}



// Local Variables:
// mode: c++
// End:
