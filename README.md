
TickTock
========

This is a little library to easily instrument c++ code with timing
information.



Interface
---------

The header file ticktock.h defined a single class, TickTock, which
works as a stopwatch.

One defines a stopwatch with 

    TickTock stopwatch;

One then starts the stopwatch with

    stopwatch.tick();

One then stops the stopwatch with
    
    stopwatch.tock();

This will print out the elapsed time between the tick and the
tock. This line can be prefixed with an arbitrary string, as follows:

    stopwatch.tock("Time measurement:");

After the tock, the 'stopwatch' can be reused.


To suppress all output and just get the time difference between the
tick and the tock, instead of just 'tock', use 'tock_silent' i.e.:

   double elapsedSeconds = stopwatch.tock_silent();


Implementation
--------------

The implementation is in the source file ticktock.cc, which needs to be
compiled and linked in to any program using the TickTock class.


Files
-----

README.md            The file you are currently reading  
ticktock.h           Header file to include for code using TickTock  
ticktock.cc          Source file to compile and link for applications using TickTock  
ticktockexample.cc   Example of how to use TickTock objects    
Makefile             To compile and run the example ('make run')    
WARRANTEE            File that expresses that there is no warranty  
LICENSE              Text of the MIT license  
AUTHOR                 Name and email address of the author
