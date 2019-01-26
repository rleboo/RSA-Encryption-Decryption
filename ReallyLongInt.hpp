#ifndef REALLY_LONG_INT
#define REALLY_LONG_INT

#include <string>
#include <ostream>

using namespace std;

class ReallyLongInt
{
  private:
   bool isNeg;
   const unsigned* digits;
   unsigned numDigits;

   ReallyLongInt(unsigned* digitArr, unsigned arrSize, bool isNeg);

   void removeLeadingZeros(unsigned* x, unsigned& xSize) const;

   void swap(ReallyLongInt other);
   
   bool absGreater(const ReallyLongInt& other) const;

   ReallyLongInt absAdd(const ReallyLongInt& other) const;
   ReallyLongInt absSub(const ReallyLongInt& other) const;
   ReallyLongInt absMult(const ReallyLongInt& other) const;
   void absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
   
   void flipSign();

  public:
   ReallyLongInt();
   ReallyLongInt(long long num);
   ReallyLongInt(const string& numStr);
   ReallyLongInt(const ReallyLongInt& other);
   ~ReallyLongInt();

   string toString() const;

   long long toLongLong() const;

   bool equal(const ReallyLongInt& other) const;
   bool greater(const ReallyLongInt& other) const;

   ReallyLongInt add(const ReallyLongInt& other) const;
   ReallyLongInt sub(const ReallyLongInt& other) const;
   ReallyLongInt mult(const ReallyLongInt& other) const;
   void div(const ReallyLongInt& denominator, ReallyLongInt& quotient, ReallyLongInt& remainder) const;

   //This is the negation operator. It should return a ReallyLongInt
   //with the same absolute value as *this, but the opposite sign.
   ReallyLongInt operator-() const;

   ReallyLongInt& operator=(const ReallyLongInt& other);
   ReallyLongInt& operator+=(const ReallyLongInt& other);
   ReallyLongInt& operator-=(const ReallyLongInt& other);
   ReallyLongInt& operator*=(const ReallyLongInt& other);
   ReallyLongInt& operator/=(const ReallyLongInt& other);
   ReallyLongInt& operator%=(const ReallyLongInt& other);

   //Prefix operators (i.e. ++x)
   ReallyLongInt& operator++();
   ReallyLongInt& operator--();

   //Suffix operators (i.e. x++)
   ReallyLongInt operator++(int dummy);
   ReallyLongInt operator--(int dummy);

  //friend int main(int argc, char** argv);   
};

//The following are *functions*, not members of the ReallyLongInt class.

bool operator==(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator>(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator<(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y);

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y);

ostream& operator<<(ostream& out, const ReallyLongInt& x);

#endif
