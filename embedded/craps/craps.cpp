#include <iostream>


extern int roll_dice();
extern int check_result(int roll, int winner, int player_sum);
extern int get_player_bet();


using namespace std;
void update_states();
int roll = 1;;
void craps(int num_rolls)
{
	int i = 0;
	
	while(i<num_rolls)
	{
		update_states();
		i++;
		//cout<<i<<endl;
		roll++;
	}
}

void update_states()
{
	int dice, ps, winner, error, point = 0;
	static int ns = 1;
	int bet;
	ps = ns;
	switch(ps)
	{
	case 1: dice = roll_dice();
	        //cout<<dice<<endl;
	        if( dice == 7 || dice == 11){
			winner = 1;
			ns = 1;
			}	
	        else if (dice== 2 || dice == 3 || dice == 12 ) {
				winner = 2;
				ns = 1;	
			}
			else if (dice == 4 || dice == 5 || dice == 6 || dice == 8 || dice == 9 || dice == 10 ){
				winner = 0;
				ns = 2;
				point = dice;
			}
			error = check_result(roll,winner,0);
			//cout<< error<<endl;
			break;
	case 2: dice = roll_dice();
	        bet = get_player_bet();
	        if (dice == 2 || dice == 3 || dice == 12 || dice == 11){
				winner = 0;
				ns = 2;
				
			}
			else if(dice == point)
			{
				winner = 1;
				ns = 1;
			}
			else if(dice == 7)
			{
				winner = 2;
				ns = 2;
			}
			else if(dice != point)
			{
				winner = 0;
				ns = 2;
			}
			
			error = check_result(roll,winner,bet);
			//cout<< error<<endl;
			break;
			
	}		
	
}