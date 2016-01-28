#
# Compilation of exmaple code for using the TickTock class
#
# Ramses van Zon, SciNet, January 2016
#
CXX=g++
CXXFLAGS=-std=c++11 -O2 -g
LDFLAGS=-g
LDLIBS=

all: ticktockexample

ticktockexample: ticktockexample.o ticktock.o
	${CXX} ${LDFLAGS} -o ticktockexample ticktockexample.o ticktock.o ${LDLIBS}

ticktock.o: ticktock.cc ticktock.h
	${CXX} ${CXXFLAGS} -c -o ticktock.o ticktock.cc

ticktockexample.o: ticktockexample.cc ticktock.h
	${CXX} ${CXXFLAGS} -c -o ticktockexample.o ticktockexample.cc


run: ticktockexample
	./ticktockexample

clean:
	\rm -f  ticktockexample.o ticktock.o
