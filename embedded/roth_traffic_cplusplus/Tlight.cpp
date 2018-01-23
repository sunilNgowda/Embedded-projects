// Class Implementation of Tlight

#include "Tlight.h"

#include <iostream>

using namespace std;

Tlight::Tlight(int num)
       : id {num}, ps {100}, ns {100}, out {1,0,0,1,0,0}
{
}

void Tlight::update_state(struct inputs *in)
{

  //Update Present State
  ps = ns;

  cout << "DEBUG: ps = " << ps << endl;
 
  //Calculate Next State
  switch (ps)
  {
   case (100) : if (in->reset == 1)
                  ns = 100;
                else
                  ns = 0;
           
                out = {1,0,0,1,0,0};
                break;

   case (0) :  ns = 1;
                out = {0,0,1,1,0,0};
                break;

   case (1) :  
   case (2) :  
   case (3) :  
   case (4) :  
                ns++;
                break;

   case (5) :  if (in->Stb == 0)
                 ns = 5;
               else
                 ns = 6;
                break;

   case (6) :  ns = 7;
                out = {0,1,0,1,0,0};
                break;

   case (7) :  ns = 8;
                out = {1,0,0,0,0,1};
                break;

   case (8) :  
   case (9) :  
   case (10) :  ns++; 
                break;

   case (11) : if ((in->Sta == 0) && (in->Stb==1))
                 ns = 11;
               else
                 ns = 12;
               break;

   case (12) :  ns = 0;
                out = {1,0,0,0,1,0};
                break;
  }



}

void Tlight::display(int clk)
{

  cout << "TIME:" << clk << ": A ";
  cout << "-- RL = " << out.A_red_light;
  cout << "-- YL = " << out.A_yellow_light;
  cout << "-- GL = " << out.A_green_light << endl;

  cout << "TIME:" << clk << ": B ";
  cout << "-- RL = " << out.B_red_light;
  cout << "-- YL = " << out.B_yellow_light;
  cout << "-- GL = " << out.B_green_light << endl;

}
