// ticktock.cc
//
// Supplies implementation of the class TickTock to measure wall-time
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

#include "ticktock.h"
#include <iostream>
#include <iomanip>

// checking for C++11 support, which has a standard timing library called chrono
#if __cplusplus > 199711L
  #include <chrono>
  // define a reference point:
  const static std::chrono::steady_clock::time_point reference_time = std::chrono::steady_clock::now();
#else
  // if not c++11, fall back on c calls from sys/time.h
  #include <sys/time.h>
#endif

static void print(const char* prefix, const double dt)
{
    // helper function to print elapsed time	
    if (prefix!=0)
        std::cout << prefix << "\t" << std::setprecision(4) << dt << " sec\n";
    else
        std::cout << "    \t" << std::setprecision(4) << dt << " sec\n";
}

static double elapsed_time()
{
  #if __cplusplus > 199711L
    std::chrono::steady_clock::time_point this_time = std::chrono::steady_clock::now();
    double dt = std::chrono::duration<double>(this_time - reference_time).count();
    return dt;
  #else
    struct timeval t;
    gettimeofday(&t, 0);
    return t.tv_sec + 0.000001 * t.tv_usec;
  #endif
}

void TickTock::tick()
{
    // start measuring time
    tick_ = elapsed_time();
}

void TickTock::tock(const char* prefix) const
{
    // done measuring time; print elapsed seconds
    print(prefix, silent_tock()); 
}

double TickTock::silent_tock() const
{
    // done measuring time; give elapsed seconds
    double tock = elapsed_time();
    double dt = tock-tick_;
    return dt;
}

