C=gcc
CXX=g++
CFLAGS=-g -Wall -Werror

all: ll

ll: main.o LinkedList.o
	$(CXX) $(CFLAGS) main.o LinkedList.o -o ll

main.o: main.cxx LinkedList.h
	$(CXX) $(CFLAGS) -c main.cxx

LinkedList.o: LinkedList.cxx LinkedList.h
	$(CXX) $(CFLAGS) -c LinkedList.cxx

clean:
	rm -f *.o ll
