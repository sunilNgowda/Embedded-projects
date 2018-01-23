// mySignal.h
// input and output signals structure

#ifndef __MYSIGNAL_H
#define __MYSIGNAL_H 1

struct outputs
{
  int A_red_light;
  int A_yellow_light;
  int A_green_light;
  int B_red_light;
  int B_yellow_light;
  int B_green_light;
};

struct inputs
{
  int reset;
  int Sta;
  int Stb;
};

#endif // __MYSIGNAL_H
