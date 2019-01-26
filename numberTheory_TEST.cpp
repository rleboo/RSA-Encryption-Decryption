#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE("Testing App")
{
  SECTION("Testing modPower")
    {
      ReallyLongInt s1(2);
      ReallyLongInt t1(3);
      REQUIRE(modPower(s1, s1, t1) == 1);
      REQUIRE(modPower(2, 2, 3) == 1);
      REQUIRE(modPower(2, 3, 3) == 2);
      
      ReallyLongInt s2(12);
      ReallyLongInt t2(123);
      
      REQUIRE(modPower(s2, s2, t2) == 66);
      REQUIRE(modPower(10, 19, 1019) == 776);
      
      ReallyLongInt s3(12345);
      ReallyLongInt t3(1234567);
      
      REQUIRE(modPower(s3, t3, t2) == 66);
      s3 = 12345;
      t3 = 1234567;
      s2 = 123456789;
      REQUIRE(modPower(s3, t3, s2) == 100842075);
      t3 = 123456789;
      REQUIRE(modPower(s3, t3, s3) == 0);
    }
 
  SECTION("testing primes")
    {
	  REQUIRE(isPrime(19) == true);
	  REQUIRE(isPrime(1) == false);
	  REQUIRE(isPrime(0) == false);
	  REQUIRE(isPrime(2) == true);
	  REQUIRE(isPrime(9) == false);
	  REQUIRE(isPrime(15) == false);
	  ReallyLongInt s(36);
	  
	  REQUIRE(isPrime(s) == false);
	  REQUIRE(isPrime(40) == false);
	  REQUIRE(isPrime(43) == true);
	  ReallyLongInt s2(137);
	  
	  REQUIRE(isPrime(s2) == true);
	  REQUIRE(isPrime(15) == false);
	  REQUIRE(isPrime(197) == true);
	  ReallyLongInt s3(27);
	  
	  REQUIRE(isPrime(s3) == false);
    }
  SECTION("Extentended Euclid")
    {
      unsigned long long px;
      unsigned long long py;
      ReallyLongInt s;
      ReallyLongInt t;

      ReallyLongInt q(12);
      ReallyLongInt a(24);
      
      REQUIRE(extendedEuclid(q, a, &s, &t) == 12);
      
      REQUIRE(s == 1);
      REQUIRE(t == 0);

      ReallyLongInt a1 = 5;
      ReallyLongInt q1 = 25;
      ReallyLongInt z;
      ReallyLongInt x;
      
      
      REQUIRE(extendedEuclid(a1, q1, &z, &x) == 5);
      REQUIRE(z == 1);
      REQUIRE(x == 0);

      unsigned long long a2 = 19;
      unsigned long long q2 = 48;

      REQUIRE(extendedEuclid(a2, q2, &px, &py) == 1);
      REQUIRE(px == -5);
      REQUIRE(py == 2);
      
      
      //INCLUDE AN EXAMPLE FOR ZERO
    }
  SECTION("Encrypt/Decrypt Test")
    {
      char m = 'm';
      ReallyLongInt prime1(5);
      ReallyLongInt prime2(2279);
      ReallyLongInt newNum = modPower(ReallyLongInt(int(m)), prime1, prime2);
      REQUIRE(newNum == 1780);
      cout << newNum.toString();
      
      


    }

}
    
