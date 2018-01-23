// Class Definition for Tlight

#ifndef __TLIGHT_H
#define __TLIGHT_H 1



#include "mySignal.h"

class Tlight
{
  public:
    Tlight (int num);
    void update_state(struct inputs *in);
    void display(int clk);

  private:
    int ps, ns;
    struct outputs out;
    int id;
};

#endif //__TLIGHT_H


