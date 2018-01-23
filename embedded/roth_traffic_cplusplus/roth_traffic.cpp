// Roth Traffic Light Example in C++

#include <iostream>

#include "mySignal.h"
#include "Tlight.h"


void generate_inputs(struct inputs *in);

using namespace std;

  int clk;		//Global clk

int main()
{

  struct inputs my_inputs;
  Tlight light1(1);

  clk = 0;

  cout << "TIME: " << clk << "-- Simulation START" << endl;

  while(clk < 400)
  {
    generate_inputs(&my_inputs);

    light1.update_state(&my_inputs);
    light1.display(clk);
    clk = clk + 10;
  }

  cout << "TIME: " << clk << "-- Simulation END" << endl;

}

void generate_inputs(struct inputs *in)
{
    //Reset Generation
    if (clk < 100)
    {
      in->reset = 1;
      in->Sta = 1;
      in->Stb = 0;
    }
    else
      in->reset = 0;

    if (clk == 200)
    {
      in->Sta = 0;
      in->Stb = 1;
     }

    if (clk == 300)
    {
      in->Sta = 1;
      in->Stb = 1;
     }
}

