// ticktock.h
//
// Supplies the class TickTock to measure walltime
//
// Ramses van Zon, SciNet, 2015-2016
//
#ifndef _TICKTOCKH_
#define _TICKTOCKH_

class TickTock 
{
  public:
    void tick();                              // start measuring time
    void tock(const char* prefix=0) const;    // done measuring time; print elapsed seconds, optionally prefixed with 'prefix'
    double silent_tock() const;               // done measuring time; give elapsed seconds
  private:
    double tick_; // stores starting point in seconds
};

#endif
