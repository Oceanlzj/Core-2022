#ifndef __BEEPER_H__
#define __BEEPER_H__


class Beeper
{
private:
  uint32_t AttachedPin;
public:
  Beeper(uint32_t Att);

  void Beep(uint32_t Freq, uint32_t Duration = 100);
  void Stop();
  

};



#endif