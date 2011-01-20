C=gcc
CXX=g++
CFLAGS=-g -Wall -Werror

TESTINC=-I../../frameworks/gtest/include -I.
TESTLIBDIR=-L../../frameworks/gtest/lib
TESTLIBS=-lgtest_main -lgtest -lpthread

all: ll testall

test: testall
	./testall

testall: testll.o testqueue.o
	$(CXX) $(CFLAGS) -static testll.o testqueue.o $(TESTLIBDIR) $(TESTLIBS) -o testall

testqueue.o: tests/testqueue.cxx LinkedList.h Queue.h
	$(CXX) $(CFLAGS) $(TESTINC) -c tests/testqueue.cxx

testll.o: tests/testll.cxx LinkedList.h
	$(CXX) $(CFLAGS) $(TESTINC) -c tests/testll.cxx

ll: main.o
	$(CXX) $(CFLAGS) main.o -o ll

main.o: main.cxx LinkedList.h
	$(CXX) $(CFLAGS) -c main.cxx

clean:
	rm -f *.o ll testall
