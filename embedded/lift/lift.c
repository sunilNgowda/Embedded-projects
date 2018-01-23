#include<stdio.h>

struct input{
  int button;
  int reset;
};

struct output{
  int floor;
  int up;
  int down;
};

void generate_input();
void update_floor();
void display();
int clk = 0;

void main(){
    struct input in1;
    struct output out1;
    while(clk < 20)
    {
      generate_input(&in1);
	  update_floor(&in1, &out1);
	  display(&in1, &out1);
	  clk++;
    }
  
} 

void generate_input(struct input *in2)
{
	/* if(clk < 5)
	  in2 -> reset = 1; */
	  
	  
	if(clk < 5)
	  in2 -> button = 1;
      
    else if(clk < 10)
	  in2 -> button = 2;
      
    else if(clk < 15)
	  in2 -> button = 3;
      
    else if(clk < 20)
	  in2 -> button = 4;
      
}
void display(struct input *inputs, struct output *out2)
{
	printf("button = %d", inputs -> button);
	printf("--floor = %d -- up = %d -- down = %d --\n",out2 -> floor, out2 -> up, out2 -> down );
}
void update_floor(struct input *in3, struct output *out3)
{
	static int ns = 0;
	int ps;
	static int next_floor = 1;
	int current_floor;
	current_floor = next_floor ;
	ps = ns;
	switch (ps){
	  case(0): 
	           ns = 1;
	           out3 -> down = 0;
			   out3 -> up = 0;
			   out3 -> floor = 1;
	           next_floor = 1;
			  
			   
			   break;
	  
	  case(1): /* if(in3 -> reset == 1)
	           ns = 0; */
			   
				 
			   if(in3 -> button > current_floor)
			    ns = 2;
			   else if (in3 -> button < current_floor)
			     ns = 3;
			   else
			     ns = 4;
			   break;
	  case(2): ns = 5;
	           out3 -> up = in3 -> button - current_floor;
			   out3 -> down = 0;
			   next_floor = in3 -> button;
	           out3 -> floor = in3 -> button;
			   break;
	  case(3): ns = 5;
	           out3 -> down = in3 -> button - current_floor;
			   out3 -> up = 0;
			   next_floor = in3 -> button;
	           out3	-> floor = in3 -> button;
	  case(4): ns =5;
	           out3 -> down = 0;
			   out3 -> up = 0;
			   next_floor = in3 -> button;
	           out3	-> floor = in3 -> button;
	  case(5): ns = 1;
	}
	
}