C=gcc
CXX=g++
CFLAGS=-g -Wall

TESTINC=-I../../frameworks/gtest/include
TESTLIBDIR=-L../../frameworks/gtest/lib
TESTLIBS=-lgtest_main -lgtest -lpthread

all: ll testll

test: testll
	./testll

testll: LinkedList.o testll.o
	$(CXX) $(CFLAGS) -static testll.o LinkedList.o $(TESTLIBDIR) $(TESTLIBS) -o testll

testll.o: testll.cxx
	$(CXX) $(CFLAGS) $(TESTINC) -c testll.cxx

ll: main.o LinkedList.o
	$(CXX) $(CFLAGS) main.o LinkedList.o -o ll

main.o: main.cxx LinkedList.h
	$(CXX) $(CFLAGS) -c main.cxx

LinkedList.o: LinkedList.cxx LinkedList.h
	$(CXX) $(CFLAGS) -c LinkedList.cxx

clean:
	rm -f *.o ll testll
