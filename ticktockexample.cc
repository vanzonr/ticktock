#include <iostream>
#include "ticktock.h"

int main()
{
    TickTock calc;

    calc.tick();

    // do work:
    for (int i=0;i<10000;i++)
        for (int j=0;j<10000;j++)
                 j++;

    double calctime = calc.silent_tock();

    std::cout << "Timing summary:" << std::endl;

    // other timers...

    std::cout << "Calc: " << calctime << std::endl;

    return 0;
}
