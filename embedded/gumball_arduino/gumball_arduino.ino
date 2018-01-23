#include<stdio.h>
struct inputs{
  int nickel;
  int dime;
  int quarter;};
struct outputs{
  int sum;
  int vend;};

void generateInputs(struct inputs *in);
void nextState(struct inputs *in1, struct outputs *out1);
void print(struct outputs *out2);
int clk=0;
const int nickel_b=2;
const int dime_b=3;
const int quarter_b=4;
const int out=13;
void setup() 
{
  pinMode(nickel_b, INPUT);
  pinMode(dime_b,INPUT);
  pinMode(quarter_b,INPUT);
  pinMode(out,OUTPUT);
}

void loop() {
  struct inputs input;
  struct outputs output;
  generateInputs(&input);
  /*input.nickel=DigitalRead(nickel_b);
  input.dime=DigitalRead(dime_b);
  input.quarter=DigitalRead(quarter_b);*/
  nextState(&input,&output);
  printfunc(&output);

}
void generateInputs(struct inputs *in)
{
 
    in->nickel=digitalRead(nickel_b);
    in->dime=digitalRead(dime_b);
    in->quarter=digitalRead(quarter_b);
}
void nextState(struct inputs *in1, struct outputs *out1)
{
  static int ps=0;
  static int ns=0;
  ps=ns;
  out1->sum=ps;
  out1->vend=0;
  switch(ps)
  {
    case 0:if(in1->nickel==1)
             ns=5;
           else if(in1->dime==1)
             ns=10;
           else if(in1->quarter==1)
             ns=25;
           else
        ns=0;
           break;
    case 5:if(in1->nickel==1)
             ns=10;
           else if(in1->dime==1)
             ns=15;
           else if(in1->quarter==1)
             ns=30;
           else
       ns=5;
           break;
    case 10:if(in1->nickel==1)
             ns=15;
           else if(in1->dime==1)
             ns=20;
           else if(in1->quarter==1)
             ns=30;
           else
       ns=10;
           break;
    case 15:if(in1->nickel==1)
             ns=20;
           else if(in1->dime==1)
             ns=25;
           else if(in1->quarter==1)
             ns=30;
           else
       ns=15;
           break;
    case 20:if(in1->nickel==1)
             ns=25;
           else if(in1->dime==1)
             ns=30;
           else if(in1->quarter==1)
             ns=35;
           else
       ns=20;
           break;
    case 25:if(in1->nickel==1)
             ns=30;
           else if(in1->dime==1)
             ns=30;
           else if(in1->quarter==1)
             ns=30;
           else
       ns=25;
           break;
    case 30:ns=100;
            break;
    case 100:ns=0;
             out1->vend=1;
             digitalWrite(out,HIGH);
             break;

  }
}
void printfunc(struct outputs *out2)
{
  printf("sum=%d\n",out2->sum);
  printf("vend=%d\n",out2->vend);
}
