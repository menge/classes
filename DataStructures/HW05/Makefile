C=gcc
CXX=g++
CFLAGS=-g -Wall -Werror

TESTINC=-I../../frameworks/gtest/include -I.
TESTLIBDIR=-L../../frameworks/gtest/lib
TESTLIBS=-lgtest_main -lgtest -lpthread

all: ll testll

test: testll
	./testll

testll: testll.o
	$(CXX) $(CFLAGS) -static testll.o $(TESTLIBDIR) $(TESTLIBS) -o testll

testll.o: tests/testll.cxx LinkedList.h
	$(CXX) $(CFLAGS) $(TESTINC) -c tests/testll.cxx

ll: main.o
	$(CXX) $(CFLAGS) main.o -o ll

main.o: main.cxx LinkedList.h
	$(CXX) $(CFLAGS) -c main.cxx

clean:
	rm -f *.o ll testll
