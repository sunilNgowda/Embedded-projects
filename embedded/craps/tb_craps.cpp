// Testbench for craps.cpp

#include <iostream>

using namespace std;

int roll_dice();
int check_result(int roll, int winner, int player_sum);
int get_player_bet();

extern void craps(int num_rolls);

int main()
{

  craps(10);
  //cout << "helloworld" << endl;

}


int roll_dice()
{
  int current_dice;
  static int roll_num = 0;

  int dice_sequence[] = {7,11,2,4,5,6,7,8,9,8};
  //int dice_sequence[] = {7,5,6,8,9,5,7,4,7};

  current_dice = dice_sequence[roll_num];
  roll_num++;

  return(current_dice);

}

int check_result(int roll, int winner, int player_sum)
{
  //winner -- 0 = push, 1 = player, 2 = machine

  static int roll_number = 0;
  int result[]={1,1,2,0,0,0,2,0,0,1};
  //int result[]={1,0,1,0,1,0,2,0,2};
  int total_win[] = {1,0,2,0,3,3,-1,0,-2};
  int error;
  
  error = 0;

  cout << "Roll = " << roll << endl;
 
  if (winner != result[roll_number])
  {
    cout << "ERROR -- MISMATCH: winner = " << winner << " EXPECTED = " << result[roll_number] << endl;
    error = 1;
  }
  else
    cout << "MATCH: winner = " << winner << " EXPECTED = " << result[roll_number] << endl;

  roll_number++;

  return(error);

}


int get_player_bet()
{
  int current_bet;
  static int bet_num = 0;

  int bet_sequence[] = {7,11,7,0,0,0,0,0,0,0};
  //int bet_sequence[] = {0,6,9,0,0,8,0,0,0};
  
  current_bet = bet_sequence[bet_num];
  bet_num++;

  return(current_bet);
}


