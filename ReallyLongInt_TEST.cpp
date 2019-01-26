#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ReallyLongInt.hpp"





TEST_CASE("Testing Really LongInt Fuctions")
{
  SECTION("TESTING ReallyLongInt Constructor")
    {
      
      REQUIRE(ReallyLongInt().toString() == "0");
    }
  
  SECTION("TESTING ReallyLongInt(String)")
    {
      ReallyLongInt s("0001234");
      REQUIRE(s.toString() == "1234");

      ReallyLongInt s1("000");
      REQUIRE(s1.toString() == "0");

      ReallyLongInt s2("-1234");
      REQUIRE(s2.toString() == "-1234");

      ReallyLongInt s3("502143523");
      REQUIRE(s3.toString() == "502143523");

      ReallyLongInt s4("00000000003");
      REQUIRE(s4.toString() == "3");
    }
  
  SECTION("TESTING ReallyLongInt(long long")
    {
      ReallyLongInt s(-123456);
      REQUIRE(s.toString() == "-123456");
      
      ReallyLongInt s2(00000);
      REQUIRE(s2.toString() == "0");

      ReallyLongInt s3(000005);
      REQUIRE(s3.toString() == "5");

      ReallyLongInt s4(051);
      REQUIRE(s4.toString() == "41");

      ReallyLongInt s5(100);
      REQUIRE(s5.toString() == "100");
    }
  
  SECTION("Making Deep Copies")
    {
      ReallyLongInt s(1234567);
      REQUIRE(s.toString() == "1234567");
      ReallyLongInt copy(s);
      REQUIRE(copy.toString() == "1234567");

      ReallyLongInt s1("00123");
      REQUIRE(s1.toString() == "123");
      ReallyLongInt copy1(s1);
      REQUIRE(copy1.toString() == "123");

      ReallyLongInt s2("00000");
      REQUIRE(s2.toString() == "0");
      ReallyLongInt copy2(s2);
      REQUIRE(copy2.toString() == "0");

      ReallyLongInt s3(00000);
      REQUIRE(s3.toString() == "0");
      ReallyLongInt copy3(s3);
      REQUIRE(copy3.toString() == "0");
    }
  /*
  SECTION("TESTING PRIVATE CONSTRUCTOR")
    {

      unsigned* temp = new unsigned[10];
      for(unsigned x = 0; x < 10; x++)
	{
	  temp[x] = 0;
	}
      ReallyLongInt s(temp, 10, false);
      REQUIRE(s.toString() == "0");

    }
  */
 
  SECTION("TESTING EQUAL OPERATOR")
    {
      ReallyLongInt s(-9801234);
      REQUIRE(s.toString() == "-9801234");

      ReallyLongInt s1("-9801234");
      REQUIRE(s1.toString() == "-9801234");
      REQUIRE(s.equal(s1) == true);

      ReallyLongInt t1("12345");
      ReallyLongInt t2("12445");
      REQUIRE(t1.equal(t2) == false);

      ReallyLongInt s2(-9801234);
      REQUIRE(s2.toString() == "-9801234");

      ReallyLongInt s3("-980123");
      REQUIRE(s3.toString() == "-980123");
      REQUIRE(s2.equal(s3) == false);

      ReallyLongInt s5(-9801234);
      REQUIRE(s5.toString() == "-9801234");

      ReallyLongInt s6("9801234");
      REQUIRE(s6.toString() == "9801234");
      REQUIRE(s5.equal(s6) == false);

      SECTION("MORE TEST")
	{
	  ReallyLongInt s(9801234);
	  REQUIRE(s.toString() == "9801234");

	  ReallyLongInt s1("-9801234");
	  REQUIRE(s1.toString() == "-9801234");
	  REQUIRE(s.equal(s1) == false);


	  ReallyLongInt s2("0001234");
	  REQUIRE(s2.toString() == "1234");
	  
	  ReallyLongInt s3("1234");
	  REQUIRE(s3.toString() == "1234");
	  REQUIRE(s2.equal(s3) == true);
	}
      
    }
  SECTION("TESTING Greater Than")
    {

      ReallyLongInt s(-9801234);
      REQUIRE(s.toString() == "-9801234");

      ReallyLongInt s1("-9801234");
      REQUIRE(s1.toString() == "-9801234");
      REQUIRE(s.greater(s1) == false);


      ReallyLongInt s2(-9801234);
      REQUIRE(s2.toString() == "-9801234");

      ReallyLongInt s3("-980123");
      REQUIRE(s3.toString() == "-980123");
      REQUIRE(s3.greater(s2) == true);

      ReallyLongInt s5(-9801234);
      REQUIRE(s5.toString() == "-9801234");

      ReallyLongInt s6("9801234");
      REQUIRE(s6.toString() == "9801234");
      REQUIRE(s5.greater(s6) == false);

      SECTION("MORE TEST")
	{
	  ReallyLongInt s(9801234);
	  REQUIRE(s.toString() == "9801234");

	  ReallyLongInt s1("-9801234");
	  REQUIRE(s1.toString() == "-9801234");
	  REQUIRE(s.greater(s1) == true);


	  ReallyLongInt s2("0001234");	  
	  ReallyLongInt s3("1234");
	  REQUIRE(s2.greater(s3) == false);


	  ReallyLongInt s4("0");
	  ReallyLongInt s5("1");
	  REQUIRE(s5.greater(s4) == true);

	  ReallyLongInt s6(-975);
	  ReallyLongInt s7("975");
	  REQUIRE(s4.greater(s5) == false);

	  ReallyLongInt s8(977);
	  ReallyLongInt s9(973);
	  REQUIRE(s8.greater(s9) == true);

	  ReallyLongInt s10(977);
	  ReallyLongInt s11(973);
	  REQUIRE(s11.greater(s10) == false);
	  
	}
      
    }

  SECTION("TESTING ADD")
    {
      ReallyLongInt s("1");
      ReallyLongInt s1("10");
      ReallyLongInt tot(s.add(s1));
      REQUIRE(tot.toString() == "11");
      
      
      ReallyLongInt s2("123");
      ReallyLongInt s3("10");
      ReallyLongInt tot1(s2.add(s3));
      REQUIRE(tot1.toString() == "133");

      ReallyLongInt p1(99999);
      ReallyLongInt p2(99999);
      REQUIRE(p1.add(p2).toString() == "199998");

      ReallyLongInt p3(123);
      ReallyLongInt p4(123);
      REQUIRE(p3.add(p4).toString() == "246");

      
      
      ReallyLongInt s6("123");
      ReallyLongInt s7("10");
      ReallyLongInt tot3(s6.add(s7));
      REQUIRE(tot3.toString() == "133");

      ReallyLongInt t1("1234567");
      ReallyLongInt t2("1000000");
      REQUIRE(t1.add(t2).toString() == "2234567");
      
      ReallyLongInt s4("01");
      ReallyLongInt s5("1");
      ReallyLongInt tot2(s4.add(s5));
      REQUIRE(tot2.toString() == "2");

      ReallyLongInt s8("99");
      ReallyLongInt s9("1");
      ReallyLongInt tot4(s8.add(s9));
      REQUIRE(tot4.toString() == "100");

      ReallyLongInt s10("99");
      ReallyLongInt s11("1");
      ReallyLongInt tot5(s11.add(s10));
      REQUIRE(tot5.toString() == "100");

      ReallyLongInt s12("0");
      ReallyLongInt s13(0);
      ReallyLongInt tot6(s12.add(s13));
      REQUIRE(tot6.toString() == "0");

    }
  
  SECTION("TESTING SUBTRACT")
    {
      ReallyLongInt s(332);
      ReallyLongInt s1(32);
      ReallyLongInt tot(s.sub(s1));
      REQUIRE(tot.toString() == "300");

      
      ReallyLongInt s2(123);
      ReallyLongInt s3(23);
      ReallyLongInt tot1(s3.sub(s2));
      REQUIRE(tot1.toString() == "-100");

      ReallyLongInt s4(100);
      ReallyLongInt s5("1");
      REQUIRE(s4.sub(s5).toString() == "99");

      ReallyLongInt s6(100);
      ReallyLongInt s7("1");
      REQUIRE(s7.sub(s6).toString() == "-99");

      ReallyLongInt s8(123456789);
      ReallyLongInt s9(123456789);
      REQUIRE(s8.sub(s9).toString() == "0");

      ReallyLongInt s12("000123");
      ReallyLongInt s13("300");
      REQUIRE(s12.sub(s13).toString() == "-177");
      
      ReallyLongInt s10(0);
      ReallyLongInt s11(12345);
      REQUIRE(s10.sub(s11).toString() == "-12345");

      ReallyLongInt t1(188);
      ReallyLongInt t2(297);
      REQUIRE(t1.sub(t2).toString() == "-109");

      ReallyLongInt t3(000);
      ReallyLongInt t4(000000);
      REQUIRE(t3.sub(t4).toString() == "0");

    }
  /*
  SECTION("overloading: output stream")
    {
      std::stringstream out;
      ReallyLongInt s(12345);
      out << s;
      REQUIRE(out == "ReallyLongInt: 12345");

      
    }
  */
  SECTION("overloading: assignment")
    {
      ReallyLongInt s(1);
      ReallyLongInt sCopy(12345);
      s = sCopy;
      REQUIRE(s.toString() == "12345");


      ReallyLongInt s2;
      REQUIRE(s2.toString() == "0");
      sCopy = s2;
      REQUIRE(sCopy.toString() == "0");
      REQUIRE(s2.toString() == "0");

      ReallyLongInt y;
      y = -58;
      REQUIRE(y.toString() == "-58");
      y = string("123456789");
      REQUIRE(y.toString() == "123456789");
      
    }
  SECTION("overloadIng: comparison")
    {
      ReallyLongInt s;
      ReallyLongInt t;
      REQUIRE(s == t);

      ReallyLongInt s1(56);
      ReallyLongInt t1(48);
      REQUIRE(s1 > t1);

      REQUIRE(s != s1);

      REQUIRE(s1 >= s);
      REQUIRE(t1 < s1);

      ReallyLongInt s2("123");
      ReallyLongInt t2(123);
      REQUIRE(s2 <= t2);

      ReallyLongInt p;
      REQUIRE(p <= s1);
    }
  SECTION("negation")
    {
      ReallyLongInt s(123);
      s = -s;
      REQUIRE(s.toString() == "-123");

      ReallyLongInt s1;
      s1 = -s1;
      REQUIRE(s1.toString() == "0");

      ReallyLongInt s2(-1123);
      s2 = -s2;
      REQUIRE(s2.toString() == "1123");
    }
  SECTION("Further Additon/Subtraction")
    {
      ReallyLongInt s(-13);
      ReallyLongInt t(58);
      REQUIRE(s.add(t).toString() == "45");
      REQUIRE(t.add(s).toString() == "45");
      REQUIRE(s.add(s).toString() == "-26");
      s = -s;
      REQUIRE(s.toString() == "13");
      REQUIRE(s.add(t).toString() == "71");

      
      ReallyLongInt s1("-15");
      ReallyLongInt t1("-96");
      REQUIRE(s1.sub(t1).toString() == "81");
      
      s1 = -s1;
      REQUIRE(s1.sub(t1).toString() == "111");
      REQUIRE(t1.sub(s1).toString() == "-111");
      t1 = -t1;
      REQUIRE(t1.sub(s1).toString() == "81");
      REQUIRE(s1.sub(t1).toString() == "-81");
    }
  SECTION("TESTING operator +")
    {
      ReallyLongInt s(5);
      ReallyLongInt t(10);
      ReallyLongInt y = s + t;
      REQUIRE(y.toString() == "15");

      ReallyLongInt s1;
      REQUIRE((s + s1).toString() == "5");
    }
  SECTION("TESTING operator -")
    {
      ReallyLongInt s(54);
      ReallyLongInt t(24);
      REQUIRE((s - t) == 30);
    }
  SECTION("TESTING ++ operator")
    {
      ReallyLongInt s;
      s++;
      REQUIRE(s.toString() == "1");

      ReallyLongInt s1(-1);
      ++s1;
      REQUIRE(s1.toString() == "0");

      ReallyLongInt s2(-99);
      s2++;
      s2++;
      REQUIRE(s2.toString() == "-97");

    }
  SECTION("TESTing -- " )
    {
      ReallyLongInt s;
      s--;
      REQUIRE(s.toString() == "-1");

      --s;
      REQUIRE(s.toString() == "-2");

      ReallyLongInt s1(99);
      --s1;
      REQUIRE(s1.toString() == "98");
      
    }
  SECTION("TESTING += and -= Operator")
    {
      ReallyLongInt s(1);
      ReallyLongInt t;
      REQUIRE((s += t).toString() == "1");

      ReallyLongInt s1(-11);
      REQUIRE((s += s1).toString() == "-10");
      
      ReallyLongInt t1(100);
      REQUIRE((t1 -= s1).toString() == "111");

      ReallyLongInt s2(-20);
      REQUIRE((s1 -= s2).toString() == "9");
    }

  
  SECTION("TESTING MULTIPLICATION")
    {
      ReallyLongInt s(56);
      ReallyLongInt t(34);
      REQUIRE(s.mult(t).toString() == "1904");

      ReallyLongInt y;
      REQUIRE(s.mult(y).toString() == "0");

      ReallyLongInt s1(999);
      ReallyLongInt t1(99);
      REQUIRE(s1.mult(t1).toString() == "98901");

      ReallyLongInt s2(-25);
      t = -t;
      REQUIRE(s2.mult(t).toString() == "850");
      REQUIRE(s2.mult(t1).toString() == "-2475");
      REQUIRE(t1.mult(s2).toString() == "-2475");

      SECTION("FURTHER TESTI")
	{
	  ReallyLongInt s(3417);
	  ReallyLongInt t(4);
	  REQUIRE((s * t) == 13668);

	  s = 6258;
	  t = 2;
	  REQUIRE((s * t) == 12516);

	  s = 7047;
	  t = 5;
	  REQUIRE((s * t) == 35235);

	  s = 9147;
	  t = 2;
	  REQUIRE((s * t) == 18294);

	  s = 5127;
	  t = 4265;
	  REQUIRE(s == 5127);
	  REQUIRE(t == 4265);
	  
	  REQUIRE((s * t) == 21866655);

	}
    }
  SECTION("Multiply Operators")
    {
      ReallyLongInt s(56);
      ReallyLongInt t(34);

      ReallyLongInt y;

      REQUIRE((s * t).toString() == "1904");
      REQUIRE((s * y).toString() == "0");
      
      s *= t;
      REQUIRE(s.toString() == "1904");
      
    }
  SECTION("TESTING DIVIDE")
    {
      ReallyLongInt Remainder;
      ReallyLongInt Quotient;

      ReallyLongInt x(15);
      ReallyLongInt t(5);

      x.div(t, Quotient, Remainder);
      REQUIRE(Remainder.toString() == "0");
      REQUIRE(Quotient.toString() == "3");

      ReallyLongInt s1;
      s1.div(x, Quotient, Remainder);
      REQUIRE(Remainder.toString() == "0");
      REQUIRE(Quotient.toString() == "0");
      
      ReallyLongInt t1(1234);
      t1.div(x, Quotient, Remainder);
      REQUIRE(Remainder.toString() == "4");
      REQUIRE(Quotient.toString() == "82");

      ReallyLongInt s2(-15);
      ReallyLongInt t2(5);
      s2.div(t2, Quotient, Remainder);
      REQUIRE(Remainder.toString() == "0");
      REQUIRE(Quotient.toString() == "-3");

      t2.div(s2, Quotient, Remainder);
      REQUIRE(Remainder.toString() == "5");
      REQUIRE(Quotient.toString() == "0");
     
      t2 = -t2;

      s2.div(t2, Quotient, Remainder);
      REQUIRE(Remainder.toString() == "0");
      REQUIRE(Quotient.toString() == "3");
    }
  SECTION("TESTING DIVIDE OPERATORS")
    {
      ReallyLongInt s(56);
      ReallyLongInt t(3);
      REQUIRE((s / t) ==  18);
      REQUIRE((s % t) ==  2);

      ReallyLongInt s1(-51);
      s1 /= t;
      REQUIRE(s1.toString() == "-17");

      ReallyLongInt s3(-15);
      ReallyLongInt s5(-124550);
      s5 %= s3;
      REQUIRE(s5.toString() == -5);
      
    }
  SECTION("TESTING toLongLong")
    {
      ReallyLongInt s(12345);
      long long t = s.toLongLong();
      REQUIRE(t == 12345);

      ReallyLongInt s1(12353024223);
      long long t1 = s1.toLongLong();
      REQUIRE(t1 == 12353024223);

      ReallyLongInt s2("00093");
      long long t2 = s2.toLongLong();
      REQUIRE(t2 == 93);

      ReallyLongInt s3(-9860547208);
      long long t3 = s3.toLongLong();
      REQUIRE(t3 == -9860547208);

      ReallyLongInt s4("9223372036854775810");
      long long t4 = s4.toLongLong();
      REQUIRE(t4 == 2);
    }
  SECTION("TESTING Modulus")
    {
      ReallyLongInt s(1263);
      ReallyLongInt t(21);
      REQUIRE((s % t) == 3);

      s = 12532;
      t = 432;
      REQUIRE((s % t) == 4);

      s = 231;
      t = 15;
      REQUIRE((s % t) ==  6);

      s = 52423;
      t = 15;
      REQUIRE((s % t) == 13);

      s  = 0;
      t = 21;
      REQUIRE((s % t) == 0);

      s =  1;
      t = 15;
      REQUIRE((s % t) == 1);

    }
}

