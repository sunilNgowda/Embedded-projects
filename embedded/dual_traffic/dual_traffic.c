// Traffic Light State Machine

#include <stdio.h>

#define RED 0
#define GREEN 1
#define YELLOW 2
#define WALK 3

struct outputs
{
  int red_light;
  int yellow_light;
  int green_light;
  int walk_light;
};
 

struct inputs 
{
  int timeout;
  int reset;
  int walk;
};

int clk; //Simulation Clock

void traffic_light(struct inputs *in, struct outputs *out);
void generate_inputs(struct inputs *in);
void checker(struct inputs *in, struct outputs *out);
void display_inputs(struct inputs *in);
void display_outputs(struct outputs *out);

int main()
{
  struct inputs my_inputsA;
  struct inputs my_inputsB;
  struct outputs my_outputsA;
  struct outputs my_outputsB;

  clk = 0;

  printf("TIME: %d -- Simulation START signal A--\n",clk);
  while(clk < 10000)
  {
    generate_inputs(&my_inputsA);
    traffic_light(&my_inputsA, &my_outputsA);
    checker(&my_inputsA, &my_outputsA); 
    clk++;
  }
  printf("TIME: %d -- Simulation END signal b--\n",clk);
  while(clk < 20000)
  {
    generate_inputs(&my_inputsB);
    traffic_light(&my_inputsB, &my_outputsB);
    checker(&my_inputsB, &my_outputsB); 
    clk++;
  }

}

void display_inputs(struct inputs *in)
{
  printf("TIME: %d -- reset = %d -- timeout = %d -- walk = %d\n",
    clk, in->reset, in->timeout, in->walk);
}

void display_outputs(struct outputs *out)
{
  printf("TIME: %d -- red_light = %d -- yellow_light = %d -- green_light = %d -- walk_light = %d\n", 
    clk, out->red_light, out->yellow_light, out->green_light, out->walk_light);
}


void checker(struct inputs *in, struct outputs *out)
{
  static struct inputs old_inputs = {0,0,0};
  static struct outputs old_outputs = {0,0,0,0};

  if ( (old_inputs.timeout != in->timeout) ||
       (old_inputs.reset != in->reset) ||
       (old_inputs.walk != in->walk) )
  {
    display_inputs(in);
    old_inputs.timeout = in->timeout; 
    old_inputs.reset = in->reset;
    old_inputs.walk = in->walk;
  }

  if ( (old_outputs.red_light != out->red_light) ||
       (old_outputs.yellow_light != out->yellow_light) ||
       (old_outputs.green_light != out->green_light) ||
       (old_outputs.walk_light != out->walk_light) )
  {
    printf("TIME: %d -- \n",clk);
    display_outputs(out);
    old_outputs.red_light = out->red_light;
    old_outputs.yellow_light = out->yellow_light;
    old_outputs.green_light = out->green_light;
    old_outputs.walk_light = out->walk_light;
  }



}
 

int timeout_counter(int reset)
{
  static int counter;
  int TIMEOUT_VALUE = 20000;

  if (reset == 1) 
    counter = 0;
  else
    counter++;

  if (counter == TIMEOUT_VALUE)
  {
    counter = 0;
    return(1);
  }
  else
    return(0);
}

 
void generate_inputs(struct inputs *in)
{
    //Reset Generation
    if (clk < 100)
      in->reset = 1;
    else
      in->reset = 0;

    in->walk = 0;
    
    in->timeout = timeout_counter(in->reset);
}

  

void traffic_light(struct inputs *in, struct outputs *out)
{
  static int ps, ns;

  //Update Present State
  ps = ns;  

  //Calculate Next State
  switch (ps)
  {
   case (RED) : if (in->reset == 1)
                  ns = RED; 
                else if (in->walk == 1)
                  ns = WALK;
                else if (in->timeout == 1)
                  ns = GREEN;
                else
                  ns = RED;
               
                out->red_light = 1; 
                out->yellow_light = 0; 
                out->green_light = 0; 
                out->walk_light = 0; 
                break;

   case (GREEN) : if (in->timeout == 1)
                    ns = YELLOW;
                  else
                    ns = GREEN;

                  out->red_light = 0; 
                  out->yellow_light = 0; 
                  out->green_light = 1; 
                  out->walk_light = 0; 
                  break;

   case (YELLOW) : if (in->timeout == 1)
                     ns = RED;
                   else
                     ns = YELLOW;

                   out->red_light = 0; 
                   out->yellow_light = 1; 
                   out->green_light = 0; 
                   out->walk_light = 0; 
                   break;

   case (WALK) : if (in->timeout == 1)
                   ns = RED;
                 else
                   ns = WALK;

                 out->red_light = 0; 
                 out->yellow_light = 0; 
                 out->green_light = 0; 
                 out->walk_light = 1; 
                 break;

   default: ns = RED;
            out->red_light = 1; 
            out->yellow_light = 0; 
            out->green_light = 0; 
            out->walk_light = 0; 
            break;
  }


              

}
