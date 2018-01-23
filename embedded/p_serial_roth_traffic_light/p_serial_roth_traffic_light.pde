// Transmit and Receive Line of Data from Serial Port

import processing.serial.*;

Serial myPort;

int portIndex = 0;
short LF = 10;
int SYNC = 0;
int clk = 0;

int old_reset = 0;
int old_Sta = 0;
int old_Stb = 0;
int old_walk_a = 0;
int old_walk_b = 0;

int reset;
int Sta;
int Stb;
int walk_a;
int walk_b;

int A_red_light;
int A_yellow_light;
int A_green_light;
int A_walk;
int B_red_light;
int B_yellow_light;
int B_green_light;
int B_walk;

int a = 0;

class struct_outputs
{
  public int A_red_light;
  public int A_yellow_light;
  public int A_green_light;
  public int A_walk;
  public int B_red_light;
  public int B_yellow_light;
  public int B_green_light;
  public int B_walk;
};

class struct_inputs
{
  public int reset;
  public int Sta;
  public int Stb;
  public int walk_a;
  public int walk_b;
};
  
 boolean rectOverA = false;
 boolean rectOverB = false;
 color rectColor, currentColor;
 struct_outputs my_outputs;
 //struct_inputs my_inputs;

void setup()
{
  size(700,700);
  currentColor = #ff0000;
   rectColor = #00ff00;
  printArray(Serial.list());
  println("Connecting to -> " + Serial.list()[portIndex]);
  myPort = new Serial(this,Serial.list()[portIndex],115200);
  
  fill(#ff0000);
  rect(200,600,100,100);
  rect(500,600,100,100);
  
  
  
  fill(#000000);
  rect(100,100,200,400);
  rect(400,100,200,400);
  
  fill(#CCFFAA);
  fill(#FF0000);
  ellipse(200,200,100,100);
  
  fill(#FFFF00);
  ellipse(200,300,100,100);
  
  fill(#00FF00);
  ellipse(200,400,100,100);
  
  
  
  
  fill(#FF0000);
  ellipse(500,200,100,100);
  
  fill(#FFFF00);
  ellipse(500,300,100,100);
  
  fill(#00FF00);
  ellipse(500,400,100,100);  
  
  
  
  
  fill(#000000);
  textSize(32);
  text("Light A",150,50);
  text("Light B",450,50);
  text("walk A", 200,590);
  text("walk B", 500,590);
  
}  
  
void draw()
{
  int i;
  String test1;
  
  update(mouseX,mouseY);
  
   if (rectOverA) {
    fill(#00ff00);
  } else {
    fill(#ff0000);
  }
  stroke(255);
  rect(200, 600, 100, 100);
  
  if (rectOverB) {
    fill(#00ff00);
  } else {
    fill(#ff0000);
  }
  stroke(255);
  rect(500, 600, 100, 100);
  
  if (SYNC == 0)
  {
    myPort.write('\n');
    myPort.write('\n');
    myPort.write("SYNC\n");
    SYNC = 1;
  }
  else
  {
    generate_inputs();
    transmit_inputs();
    update_lights();
  }
  
   
  delay(1000);
}


void update_lights()
{
  
  if (A_red_light == 1 || rectOverA)
    fill(#FF0000);
  else 
    fill(#000000);
  ellipse(200,200,100,100);
  
  if (A_yellow_light == 1 && !rectOverA)
    fill(#FFFF00);
  else
    fill(#000000);
  ellipse(200,300,100,100);
  
  if (A_green_light == 1 && !rectOverA)
    fill(#00FF00);
  
  else
  fill(#000000);
  ellipse(200,400,100,100);
  
  
  if (B_red_light == 1 || rectOverB)
    fill(#FF0000);
  else
    fill(#000000);
  ellipse(500,200,100,100);
  
  if (B_yellow_light == 1 && !rectOverB)
    fill(#FFFF00);
  else
    fill(#000000);
  ellipse(500,300,100,100);
  
  if (B_green_light == 1 && !rectOverB)
    fill(#00FF00);
  else
    fill(#000000); 
  ellipse(500,400,100,100);
    
    if(rectOverA){
    A_green_light = 0;
    A_red_light = 1;
    B_green_light = 1;
    B_red_light = 0;
   }
   if(rectOverB){
    A_green_light = 1;
    A_yellow_light = 0;
    A_red_light = 0;
    B_green_light = 0;
    B_yellow_light = 0;
    B_red_light = 1; }
}





void transmit_inputs()
{
  if ( (reset != old_reset) || 
       (Sta != old_Sta) ||
       (Stb != old_Stb) || 
       (walk_a != old_walk_a) || 
       (walk_b != old_walk_b) )
  {
    myPort.write("INPUT,");
    myPort.write(str(reset));
    myPort.write(',');
    myPort.write(str(Sta));
    myPort.write(',');
    myPort.write(str(Stb));
    myPort.write(',');
    myPort.write(str(walk_a));
    myPort.write(',');
    myPort.write(str(walk_b));
    myPort.write(str(','));
    myPort.write('\n');
  }
  
  old_reset = reset;
  old_Sta = Sta;
  old_Stb = Stb;
  walk_a =  old_walk_a;
  walk_b = old_walk_b;
}
           

void generate_inputs()
{
  
  
  if (clk <= 5)
  {
    reset = 1;
    Sta = 0;
    Stb = 0;
  }
    else if (clk >5 && clk <=10)
   {
    reset = 0;
    Sta = 1;
    Stb = 0;
  
   }
    else if (clk >10 && clk <15)
   {
    reset = 0;
    Sta = 0;
    Stb = 1;
   }
    else
  {
    reset = 0;
    Sta = 1;
    Stb = 0;
  } 
  
  clk++;
}


void serialEvent(Serial p)
{
  String message;
  String header;
  
  message = p.readStringUntil(LF);  //read serial data
  
 
  if (message != null)
  {
    println(message);
    
    if (message.charAt(0) != '#') 
    {
      header = message.substring(0,6);
      
      if (header.equals("OUTPUT") )
      {
        //my_outputs.A_red_light = int(message.charAt(7)) - 48;
        A_red_light = int(message.charAt(7)) - 48;
        A_yellow_light = int(message.charAt(9)) - 48;
        A_green_light = int(message.charAt(11)) - 48;
        A_walk = int(message.charAt(13))- 48;
        B_red_light = int(message.charAt(15)) - 48;
        B_yellow_light = int(message.charAt(17)) - 48;
        B_green_light = int(message.charAt(19)) -48;
        B_walk = int(message.charAt(21)) - 48;
      
        println("STATUS A:" + A_red_light + " " + A_yellow_light + " " + A_green_light + " " + A_walk);
        println("STATUS B:" + B_red_light + " " + B_yellow_light + " " + B_green_light + " " + B_walk);
      }
    }
  }
}
void update(int x, int y) 
{
  if ( overRect(200, 600, 100, 100) ) {
    rectOverA = true;
    rectOverB = false;
  } else if (overRect(500,600,100,100) ){
    rectOverA = false;
    rectOverB = true;
  }
  else{
    rectOverA = false;
    rectOverB = false;
  }
}

void mousePressed() 
{
 
  if (rectOverA) {
    currentColor = rectColor;
  }
  else if(rectOverB){
    currentColor = rectColor;
}
}
boolean overRect(int x, int y, int width, int height)  {
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}

  