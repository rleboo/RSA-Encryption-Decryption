OPTS = -Wall
Cov = --coverage

all: encrypt decrypt keygen 

ReallyLongInt.o: ReallyLongInt.hpp ReallyLongInt.cpp
	g++ ${OPTS} -c ReallyLongInt.cpp

keygen: encrypt.cpp ReallyLongInt.o
	g++ ${OPTS} -g -o keygen keygen.cpp ReallyLongInt.o

encrypt: encrypt.cpp ReallyLongInt.o
	g++ ${OPTS} -g -o encrypt encrypt.cpp ReallyLongInt.o

decrypt: decrypt.cpp ReallyLongInt.o
	g++ ${OPTS} -o decrypt decrypt.cpp ReallyLongInt.o

numberTheory_TEST: numberTheory_TEST.cpp 
	g++ ${Cov} -o numberTheory_TEST numberTheory_TEST.cpp ReallyLongInt.cpp

tests: numberTheory_TEST reallyLongInt_TEST

ReallyLongInt_TEST: ReallyLongInt_TEST.cpp
	g++ ${Cov} -g -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.cpp

clean:
	rm *.o ReallyLongInt_TEST numberTheory_TEST 
