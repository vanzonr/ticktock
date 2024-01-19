// ticktockexample.cc
//
// Example code to show how to use the class TickTock to measure walltime
//
// Copyright (c) 2015-2016  Ramses van Zon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <iostream>
#include "ticktock.h"

int main()
{
    // define a stopwatch timer:

    TickTock stopwatch;

    // start timer:

    stopwatch.tick();

    // do work:

    double result = 0;
    for (int i=0;i<100000000;i++)
        result += i*i*1e-10;

    // measure time and save elapsed time

    double calctime = stopwatch.silent_tock();

    // time output as well:

    stopwatch.tick();

    // output of the result of the calculation:

    std::cout << "Calculation summary:" << std::endl;
    std::cout << "result = " << result << std::endl;

    // Stop and print out all timings

    std::cout << "Timing summary:" << std::endl;
    std::cout << "#Calculation took:\t" << calctime << " sec" << std::endl;
    stopwatch.tock("#Report took:     "); // this combines the elapsed time measurement and output

    return 0;
}
