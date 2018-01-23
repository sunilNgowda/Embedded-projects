#include<stdio.h>
struct input{
  int light_A;
  int light_B;
  int walk_A;
  int walk_B;
  int reset;
};
struct output{
  int A_red;
  int A_Yellow;
  int A_Green;
  int A_walk;
  int B_red;
  int B_Yellow;
  int B_Green;
  int B_walk;
};
void update_states(struct input *in2,struct output *light2);
void inputs(struct input *in1);
void outputs(struct input *in3,struct output *light);
int clk = 0;
void main(){
  struct input input1;
  struct output output1;
  while(clk < 25)
  {
	inputs(&input1);
    update_states(&input1, &output1); 
	outputs(&input1,&output1);
	clk++;
  }
}
void inputs(struct input *in1)
{
  if(clk < 5)
  {
	in1 -> reset = 1;
	in1 -> light_A = 0;
	in1 -> light_B = 0;
	in1 -> walk_A = 0;
	in1 -> walk_B = 0;
  }
  else if(clk < 10)
  {
	in1 -> reset = 0;
	in1 -> light_A = 1;
	in1 -> light_B = 0;
	in1 -> walk_A = 0;
	in1 -> walk_B = 0;
  }
  else if(clk < 15)
  {
	in1 -> reset = 0;
	in1 -> light_A = 1;
	in1 -> light_B = 0;
	in1 -> walk_A = 1;
	in1 -> walk_B = 0;
  }
  else if(clk < 20)
  {
	in1 -> reset = 0;
	in1 -> light_A = 0;
	in1 -> light_B = 1;
	in1 -> walk_A = 0;
	in1 -> walk_B = 0;
  }
  else if(clk < 25)
  {
	in1 -> reset = 0;
	in1 -> light_A = 0;
	in1 -> light_B = 1;
	in1 -> walk_A = 0;
	in1 -> walk_B = 1;
  }
}
void outputs(struct input *in3,struct output *light )
{
	//printf("A - %d , B - %d , walkA - %d, walkb - %d , reset - %d\n",in3 -> light_A,in3 -> light_B,in3 -> walk_A,in3 -> walk_B,in3 -> reset);
	printf("A_red - %d , A_Yellow - %d , A_Green - %d , A_walk - %d \t" , light -> A_red, light -> A_Yellow,light -> A_Green,light -> A_walk);
	printf("B_red - %d , B_Yellow - %d , B_Green - %d , B_walk - %d \n" , light -> B_red, light -> B_Yellow,light -> B_Green,light -> B_walk);
}


void update_states(struct input *in,struct output *light)
{
  int ps;
  static int ns = 0;
  ps = ns;
  //printf("%d \n",ps);
  switch(ps)
  {
		      
    case 0: ns = 1;
	        light -> A_red = 1;
	        light -> A_Yellow = 0;
			light -> A_Green = 0;
			light -> A_walk = 0;
			light -> B_red = 1;
	        light -> B_Yellow = 0;
			light -> B_Green = 0;
			light -> B_walk = 0;
			break;
			
	case 1: if(in -> reset == 1)
			ns = 0;
		     
		    else {
				ns = 2;
	        if(in -> light_A == 1 && in -> light_B == 0 ){
		    light -> A_red = 0;
	        light -> A_Yellow = 0;
			light -> A_Green = 1;
			light -> A_walk = 0;
			light -> B_red = 1;
	        light -> B_Yellow = 0;
			light -> B_Green = 0;
			light -> B_walk = 0;
			}
			}
			if(in -> walk_A == 1 ){
			light -> A_red = 1;
	        light -> A_Yellow = 0;
			light -> A_Green = 0;
			light -> A_walk = 1;
			light -> B_red = 0;
	        light -> B_Yellow = 0;
			light -> B_Green = 1;
			light -> B_walk = 0;
			}
			 
			
			break;
			
	case 2: if(in -> reset == 1)
		       ns = 0;
		    
		    else {
			ns = 3;}
	        if(in -> walk_A == 1){
			light -> A_red = 1;
	        light -> A_Yellow = 0;
			light -> A_Green = 0;
			light -> A_walk = 1;
			light -> B_red = 0;
	        light -> B_Yellow = 0;
			light -> B_Green = 1;
			light -> B_walk = 0;
			
			}
            break;
			
	case 3: if(in -> reset == 1)
		       ns = 0;
		       
		    else {
			ns = 4;}
	        if(in -> walk_A == 1 ){
			light -> A_red = 1;
	        light -> A_Yellow = 0;
			light -> A_Green = 0;
			light -> A_walk = 1;
			light -> B_red = 0;
	        light -> B_Yellow = 0;
			light -> B_Green = 1;
			light -> B_walk = 0;
			
			}
	        break;
		
	case 4: if(in -> reset == 1)
		       ns = 0;
		      
		    else {
			ns = 5;}
	        if(in -> walk_A == 1 ){
			light -> A_red = 1;
	        light -> A_Yellow = 0;
			light -> A_Green = 0;
			light -> A_walk = 1;
			light -> B_red = 0;
	        light -> B_Yellow = 0;
			light -> B_Green = 1;
			light -> B_walk = 0;
			
			}
	        break;
			
	case 5: if(in -> reset == 1)
		       ns = 0;
		       
		    else {
			ns = 6;
	        if(in -> light_B == 1){
		    light -> A_red = 1;
	        light -> A_Yellow = 0;
			light -> A_Green = 0;
			light -> A_walk = 1;
			light -> B_red = 0;
	        light -> B_Yellow = 0;
			light -> B_Green = 1;
			light -> B_walk = 0;
			}
			}
			if(in -> walk_B == 1){
			light -> A_red = 0;
	        light -> A_Yellow = 0;
			light -> A_Green = 1;
			light -> A_walk = 0;
			light -> B_red = 1;
	        light -> B_Yellow = 0;
			light -> B_Green = 0;
			light -> B_walk = 1;
			}
			
			
			break;
			
	case 6: if(in -> reset == 1)
		       ns = 0;
		      
		    else {
			ns = 7;}
	        if(in -> walk_B == 1){
			light -> A_red = 0;
	        light -> A_Yellow = 0;
			light -> A_Green = 1;
			light -> A_walk = 0;
			light -> B_red = 1;
	        light -> B_Yellow = 0;
			light -> B_Green = 0;
			light -> B_walk = 1;
			
			}
	        break;
			
	case 7: if(in -> reset == 1)
		       ns = 0;
		      
		    else {
			ns = 8;}
	        if(in -> walk_B == 1){
			light -> A_red = 0;
	        light -> A_Yellow = 0;
			light -> A_Green = 1;
			light -> A_walk = 0;
			light -> B_red = 1;
	        light -> B_Yellow = 0;
			light -> B_Green = 0;
			light -> B_walk = 1;
			
			}
	        break;	
    case 8: if(in -> reset == 1)
		       ns = 0;
		       
		    else {
			ns = 9;}
	        if(in -> walk_B == 1){
			light -> A_red = 0;
	        light -> A_Yellow = 0;
			light -> A_Green = 1;
			light -> A_walk = 0;
			light -> B_red = 1;
	        light -> B_Yellow = 0;
			light -> B_Green = 0;
			light -> B_walk = 1;
			
			}
	        break;	
    			
    case 9: if(in -> reset == 1)
		       ns = 0;
		       
		    else 
				ns = 1;
			break;
             	
  }
}