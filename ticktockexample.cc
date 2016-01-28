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
