 #include <string>
#include <iostream>
#include "ReallyLongInt.hpp"
#include <cmath>
#include <climits>

using namespace std;

long long ReallyLongInt::toLongLong() const
{
  long long num = LLONG_MAX;

  long long n = 1000000000000000000;
  unsigned* max = new unsigned[19];

  for(unsigned x = 0; x < 19; x++)
    {
      unsigned long long temp = num / n;
      max[x] = temp;
      num = num % n;
      n = n / 10;
    }
  ReallyLongInt maxRl = ReallyLongInt(max, 19, false);
  maxRl += 1;

  ReallyLongInt finalRl = *this % maxRl;
  
  long long div = 1;
  for(long long x = 0; x < finalRl.numDigits-1; x++)
    {
      div *= 10;
    }
  
  long long fin = 0;
  for(unsigned long long x = 0; x < finalRl.numDigits; x++)
    {
      fin += finalRl.digits[x] * div;
      div = div / 10;
    }

  if(this->isNeg == true)
    fin *= -1;

  return fin;
}

ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt q;
  ReallyLongInt r;
  x.div(y, q, r);
  return q;
  
}
ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y)
{

  ReallyLongInt q;
  ReallyLongInt r;
  x.div(y, q, r);
  return r;
  
}
  
ReallyLongInt& ReallyLongInt::operator/=(const ReallyLongInt& other)
{
  *this = *this / other;
  return *this;

}
ReallyLongInt& ReallyLongInt::operator%=(const ReallyLongInt& other)
{
  ReallyLongInt q;
  ReallyLongInt r;
  this->div(other, q, r);
  *this = r;
  return *this;
}


void ReallyLongInt::div(const ReallyLongInt& denominator, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{

  // -x/-y
  if(this->isNeg == true &&  denominator.isNeg == true)
    {
      this->absDiv(denominator, quotient, remainder);
      remainder.flipSign();
      
    }
  // -x/y
  else if( this->isNeg == true && denominator.isNeg == false)
    {
      this->absDiv(denominator, quotient, remainder);
      quotient.flipSign();
      remainder.flipSign();
    }
  // x/-y
  else if(this->isNeg == false && denominator.isNeg == true)
    {
      this->absDiv(denominator, quotient, remainder);
      quotient.flipSign();
    }
  // x/y
  else
    {
      this->absDiv(denominator, quotient, remainder);
    }
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
  remainder = 0;  
  unsigned*  q = new unsigned[this->numDigits];

  unsigned* tempO = new unsigned[other.numDigits];
  for(unsigned x = 0; x < other.numDigits; x++)
    {
      tempO[x] = other.digits[x];
    }
  ReallyLongInt otherTemp = ReallyLongInt(tempO, other.numDigits, false);

   
  for(long long i = 1; i <= this->numDigits; i++)
    {
      remainder *= 10;
      remainder += this->digits[i-1];
      unsigned d = 0;
      while(remainder >= otherTemp)
	{
	  remainder -= otherTemp;
	  d = d + 1;
	}
      q[i-1] = d;
    }
  
  ReallyLongInt temp = ReallyLongInt(q, this->numDigits, false);
  quotient = temp;
}

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.mult(y);
}

ReallyLongInt& ReallyLongInt::operator*=(const ReallyLongInt& other)
{
  *this = this->mult(other);
  return *this;
  
}

  
ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const
{
  if(this->isNeg == true && other.isNeg == true)
    {
      return this->absMult(other);
    }
  else if(this->isNeg == true || other.isNeg == true)
    {
      ReallyLongInt y = this->absMult(other);
      y.flipSign();
      return y;
    }
  else
    return this->absMult(other);
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const
{
  unsigned totalDigits = this->numDigits + other.numDigits;
  unsigned* tempArray = new unsigned[totalDigits];

  for(unsigned x = 0; x < (this->numDigits + other.numDigits); x++)
    {
      tempArray[x] = 0;
    }

  for(int x = this->numDigits-1; x != -1; x--)
    {
      for(int y = other.numDigits-1; y != -1; y--)
	{
        
	  unsigned total = this->digits[x] * other.digits[y];
	  unsigned placeIndex = x + y + 1;
	  unsigned tempDigit = tempArray[placeIndex];
	  unsigned next = tempArray[placeIndex -1];
	  total += tempDigit;
	  
	  if(total > 9)
	    {
	      tempArray[placeIndex] = total % 10;
	      tempArray[placeIndex - 1] = next + total / 10;
	    }
	  else
	    {
	      tempArray[placeIndex] = total;  
	    }

	}
    }
  return ReallyLongInt(tempArray, totalDigits, false);
  
}

ReallyLongInt ReallyLongInt::operator++(int dummy)
{
  ReallyLongInt temp = *this;
  ReallyLongInt add(1);
  *this += add;
  return temp;
  
}
ReallyLongInt ReallyLongInt::operator--(int dummy)
{
  ReallyLongInt temp = *this;
  ReallyLongInt sub(1);
  *this -= sub;
  return temp;

}

ReallyLongInt& ReallyLongInt::operator++()
{
  ReallyLongInt add(1);
  return (*this += add);
}
ReallyLongInt& ReallyLongInt::operator--()
{
  ReallyLongInt sub(1);
  return (*this -= sub);
}


ReallyLongInt& ReallyLongInt::operator+=(const ReallyLongInt& other)
{
  *this = this->add(other);
  return *this;
}

ReallyLongInt& ReallyLongInt::operator-=(const ReallyLongInt& other)
{
  *this = this->sub(other);
  return *this;
  
}


ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.add(y);
}
ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.sub(y);
}

ReallyLongInt ReallyLongInt::operator-() const
{
  ReallyLongInt temp = *this;
  temp.flipSign();
  return temp;
  
}

void ReallyLongInt::flipSign()
{
  if(this->digits[0] == 0)
    {
      this->isNeg = false;
    }
  else
    {
      if(this->isNeg == false)
        this->isNeg = true;
      else
	{
	this->isNeg = false;
	}
    }
}


bool operator==(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.equal(y);
}
bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return !x.equal(y);
}
bool operator>(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.greater(y);
}
bool operator<(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return y.greater(x);
}

bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.greater(y) || x.equal(y);
}

bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return y.greater(x) || x.equal(y);
}



void ReallyLongInt::swap(ReallyLongInt other)
{
  unsigned numDigTemp = other.numDigits;
  other.numDigits = this->numDigits;
  this->numDigits = numDigTemp;

  bool isNegTemp = other.isNeg;
  other.isNeg = this->isNeg;
  this->isNeg = isNegTemp;

  const unsigned* numArray = other.digits;
  other.digits = this->digits;
  this->digits = numArray;
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other)
{
  swap(other);
  return *this;
}

ostream& operator<<(ostream& out, const ReallyLongInt& x)
{
  out << x.toString();
  return out;
}


ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const
{
  if(this->isNeg == true && other.isNeg == true)
    {
      ReallyLongInt temp = this->absSub(other);
      temp.flipSign();
      return temp;
    }
  else if(this->isNeg == true && other.isNeg == false)
    {
      ReallyLongInt temp = this->absAdd(other);
      temp.flipSign();
      return temp;
    }
  else if(this->isNeg == false && other.isNeg == true)
    {
      return this->absAdd(other);
    }
  else
    {
      return this->absSub(other);
    }
}


ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const
{
  bool truth;
  bool firstGreater;

 
  unsigned maxNum;
  unsigned minNum;

  if(this->equal(other))
    {
      unsigned len = 1;
      unsigned* ar = new unsigned[len];
      ar[0] = 0;
      return ReallyLongInt(ar, len, false);
    }
  if(other.absGreater(*this))
    {
      truth = true;
      firstGreater = false;
      maxNum = other.numDigits-1;
      minNum = this->numDigits-1;
    }
  else
    {
      truth = false;
      firstGreater = true;
      maxNum = this->numDigits-1;
      minNum = other.numDigits-1;
    }

  unsigned* tempArray = new unsigned[maxNum+1];

  int difTrack = maxNum - minNum;
  int loopTrack = 1; 
  int inTrack = 0;
  for(unsigned x = 0; x<maxNum +1; x++)
    {
      if((loopTrack) > difTrack)
	{
	  if(firstGreater)
	    tempArray[ x] = other.digits[inTrack];
	  else
	    tempArray[x] = this->digits[inTrack];

	  inTrack++;
	}
      else
	{
	  tempArray[x] = 0;
	  loopTrack++;
	}
    }


  
  unsigned* arry = new unsigned[maxNum+1];
  unsigned finalReturn = maxNum+1;
  int carry = 0;
 
  for(int x = finalReturn-1; x != -1; x--)
    {
      int num = 0;
      if(firstGreater)
	{
	  num = this->digits[x];
	}
      else
	{ 
	  num = other.digits[x];
	}
      
      num =  num - carry;
      carry = 0;
      int tem = tempArray[x];
      if(num > tem)
	{
	  arry[x] = num - tempArray[x];
	}
      else if(num == tem)
	{
	  arry[x] = 0;
	}
      else
	{
	  carry++;
	  arry[x] = (num + 10) - tempArray[x];
	}
    }
  
  delete [] tempArray;
  return ReallyLongInt(arry, finalReturn, truth);
}



ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const
{
 
  unsigned max;
  unsigned min;
  bool otherIsMin;

  if(this->numDigits > other.numDigits)
    {
      max = this->numDigits -1;
      min = other.numDigits -1;
      otherIsMin = true;

    }
  else if(other.numDigits > this->numDigits)
    {
      max = other.numDigits -1;
      min = this->numDigits -1;
      otherIsMin = false;
    }
  else{
    max = this->numDigits -1;
    min = other.numDigits -1;
    otherIsMin = true;
  }

  //unsigned minTracker = min;
  unsigned maxTracker = max;
  unsigned ndigits = max + 2;
  unsigned* arra = new unsigned[ndigits];
  arra[0] = 0;

  unsigned carry = 0;
  //Keep track of carry over

  //changed to max +1
  bool lastMin = false;
  
  for(int x = max; x != -1; x--)
    {
      unsigned total;
      //Checks if I should use other or this as biggest
      if(lastMin)
	{
	  if(otherIsMin)
	    {
	      total = this->digits[maxTracker] + carry;
	      --maxTracker;
	    }
	  else
	    {
	      total = other.digits[maxTracker] + carry;
	      --maxTracker;
	    }
	}
      else
	{
	  if(otherIsMin)
	    {
	      total = this->digits[maxTracker] + other.digits[min] + carry;
	      --maxTracker;
	      if(min == 0)
		lastMin = true;
	      else
		--min;
	    }
	  else
	    {
	      total = this->digits[min] + other.digits[maxTracker] + carry;
	      --maxTracker;
	      if(min == 0)
		lastMin = true;
	      else
		--min;
	    }
	}

      if(total > 9)
	{
	  carry = 1;
	  arra[x+1] = total - 10;
	  
	}
      else
	{
	  carry = 0;
	  arra[x+1] = total;
	}
    }
  
  if(carry != 0)
    {
      arra[0] = carry;
    }

    

  
  return ReallyLongInt(arra, max +2, false);
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const
{
  if(this->isNeg == true && other.isNeg == true)
    {
      ReallyLongInt temp = this->absAdd(other);
      temp.flipSign();
      return temp;
    }
  else if(this->isNeg == true && other.isNeg == false)
    {
      return other.absSub(*this);
    }
  else if(this->isNeg == false && other.isNeg == true)
    {
      return this->absSub(other);
    }
  else
    {
      return this->absAdd(other);
    }
}



bool ReallyLongInt::greater(const ReallyLongInt& other) const
{

  // If the number is Negative, The smaller the greater

  if(this->isNeg == true && other.isNeg == true)
    {
			 //return this->absGreater(other);
      return other.absGreater(*this);
    }
  
  if(this->isNeg == other.isNeg)
    {
      return this->absGreater(other);
    }
  else if(this->isNeg > other.isNeg)
    {
      return false;
    }
  else
    {
     return true;
    }
}


bool ReallyLongInt::absGreater(const ReallyLongInt& other) const
{
  if(this->numDigits > other.numDigits)
    {
      return true;
    }
  else if(other.numDigits > this->numDigits)
    {
      return false;
    }

  unsigned min = this->numDigits;

  for(unsigned i = 0; i < min; i++)
    {
      if(this->digits[i] > other.digits[i])
	{
	  return true;
	}
      else if(this->digits[i] < other.digits[i])
	{
	  return false;
	}
    }
  return false;
}



bool ReallyLongInt::equal(const ReallyLongInt& other) const
{

  //is *this-> used to access this?
  //QUESTION
  
  if(this->isNeg != other.isNeg)
    {
      return false;
    }
  else if(this->numDigits != other.numDigits)
   {
     return false;
   }

  for(unsigned i = 0; i < other.numDigits; i++)
    {
      if(this->digits[i] != other.digits[i])
	{
	  return false;
	}
    }
  return true;
  
  
}



ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg)
{

  removeLeadingZeros(digitsArr, arrSize);

  this->numDigits = arrSize;
  this->digits = digitsArr;
  if(digitsArr[0] == 0)
    {
      this->isNeg = false;
    }
  else
    this->isNeg = isNeg;

}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other)
{
  isNeg = other.isNeg;
  numDigits = other.numDigits;
  
 
  unsigned* digit = new unsigned[numDigits];
  for(unsigned x = 0; x < numDigits; x++)
    {
      digit[x] = other.digits[x];
    }
  
  digits = digit;
}


ReallyLongInt::ReallyLongInt()
{
  isNeg = false;
  numDigits = 1;
  unsigned* digit = new unsigned[numDigits];

  digit[0] = 0;
  digits = digit;
}

ReallyLongInt::ReallyLongInt(long long num)
{

  //Check if its a negative
  //Take long long num
  if(num < 0 )
  {
    num = num * -1;
    isNeg = true;
  }
  else 
    isNeg = false;

  //You gotta remember to add in 000

  if(num == 0)
    {
      numDigits = 1;
      isNeg = false;

    }
  else
    numDigits = floor(log10(num)) + 1;

  unsigned* numArray = new unsigned[numDigits];

  unsigned long long div = 1;
  //Will keep track of what to divide numDigits is in order to extract number
  for(unsigned long long x = 0; x < (numDigits -1); x++)
    {
      div *= 10;
    }
  
  for(unsigned long long x = 0; x < numDigits; x++)
    {
      unsigned long long temp = num / div;
      numArray[x] = temp;
      num = num % div;
      div = div / 10;
    }
  digits = numArray;
}

ReallyLongInt::ReallyLongInt(const string& numStr)
{

  numDigits = numStr.size();
  
  unsigned* numArray = new unsigned[numDigits];

  char temp = numStr[0];
  if(temp == '-')
  {
    isNeg = true;
    numDigits = numStr.size() - 1;
    for(unsigned i = 0; i < numDigits; i++)
    {
      unsigned numValue = ((unsigned) numStr[i+1]) - 48;
      numArray[i] = numValue;
    }
    
  }
  else
    {
      isNeg = false;
      numDigits = numStr.size();
      for(unsigned i = 0; i < numDigits; i++)
	{
	  unsigned numValue = ((unsigned) numStr[i]) - 48;
	  numArray[i] = numValue;
	}
    }

  removeLeadingZeros(numArray, numDigits);

  //If there's still a zero remaining change isNeg to positive(so no -0)
  if(numArray[0] == 0)
    {
      isNeg = false;
    }
  digits = numArray;

}

ReallyLongInt::~ReallyLongInt()
{
  delete[] digits;
}


void ReallyLongInt::removeLeadingZeros(unsigned*x, unsigned& xSize) const
{
  long long numZeros = 0;


  while(x[numZeros] == 0)
    {
      if(numZeros == xSize - 1)
      {
	break;
      }
      ++numZeros;
    }
  
  if(xSize == numZeros)
  {
    xSize = 1;
  }
  else
  {
    long long newSize =  xSize - numZeros;

    for(long long i = 0; i < newSize; i++)
    {
      x[i] = x[i + numZeros];
    }
     xSize = newSize;
  }

  
}

string ReallyLongInt::toString() const
{
  string fin; 
  if(isNeg == true)
    {
      fin += '-';
    }
  for(unsigned i = 0; i < numDigits; i++) 
    {
      fin +=to_string(digits[i]);
    }
  return fin;
  
}
