#ifndef __LINETRACKER_H__
#define __LINETRACKER_H__
#include <PinNames.h>

class Linetracker
{
private:
  PinName AttachedPin;

public:
  Linetracker(PinName Ach);
  //TODO:: Verify > or <
  bool OnLine();
  
  bool operator==(Linetracker lt);
};

#endif