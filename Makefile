#
# Compilation of example code for using the TickTock class
#
# Copyright (c) January 2016 Ramses van Zon
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
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
