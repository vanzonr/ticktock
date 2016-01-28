#include <iostream>
#include "ticktock.h"

int main()
{
    TickTock calc;

    // start timer:
    calc.tick();

    // do work:
    double result = 0;
    for (int i=0;i<100000000;i++)
        result += i*i*1e-10;

    // measure time:
    double calctime = calc.silent_tock();

    // report
    std::cout << result << std::endl;
    
    // perhaps other timers...

    std::cout << "Timing summary:" << std::endl;
    std::cout << "Calc: " << calctime << std::endl;

    return 0;
}
