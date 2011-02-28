C=gcc
CXX=g++
CFLAGS=-g -Wall

all: strtest

strtest: main.o strmemfuncs.o
	$(CXX) $(CFLAGS) main.o strmemfuncs.o -o strtest

main.o: main.cxx strmemfuncs.h
	$(CXX) $(CFLAGS) -c main.cxx

strmemfuncs.o: strmemfuncs.cxx strmemfuncs.h
	$(CXX) $(CFLAGS) -c strmemfuncs.cxx

clean:
	rm -f *.o strtest
