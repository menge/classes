C=gcc
CXX=g++
CFLAGS=-g -Wall

all: bank

test: bank
	tests/run_test.sh

bank: main.o Account.o Bank.o
	$(CXX) $(CFLAGS) main.o Account.o Bank.o -o bank

main.o: main.cxx Account.h Bank.h
	$(CXX) $(CFLAGS) -c main.cxx

Account.o: Account.cxx Account.h
	$(CXX) $(CFLAGS) -c Account.cxx

Bank.o: Bank.cxx Bank.h Account.h
	$(CXX) $(CFLAGS) -c Bank.cxx

clean:
	rm -f *.o bank
