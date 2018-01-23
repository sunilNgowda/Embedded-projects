// myhello.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


 
int deck[52];
int value[53];
int clk;
int hit;
int player_value = 0;
int dealer_value = 0;
int hidden_card = 0;

void shuffle();
void display_deck();
void update_state();
void deal();
void get_hit();
void deal_player_card();
void deal_dealer_card();
void determine_winner();


void main()
{
  
	shuffle();

	//display_deck();
	//update_state();

	
	for (clk = 0; clk < 10; clk++)
	{
		update_state();

	}

	
}
void update_state()
{
	static int ps, ns = 0;

	ps = ns;
    int start = 1;
	switch (ps)
	{
	    case (0) : 
		if (start == 0)
		  ns = 0;
		else
		  ns = 1;
		break;

		case(1) :
			shuffle();
			ns = 2;
			break;
		case(2) :
			deal();
			ns = 3;
			break;
		case(3) :
			get_hit();
			if (hit == 1)
				ns = 4;
			else
				ns = 5;
			break;
		case(4) :
			deal_player_card();
			ns = 3;
			break;
		case(5) :
			//check_dealer();
			if (dealer_value >= 17)
				ns = 6;
			else
			{
				deal_dealer_card();
				ns = 5;
			}
			break;
		case(6) :
			determine_winner();
			ns = 7;
			break;
		case(7) :
			//game_done();
			ns = 7;
			break;
	}

}


void shuffle()
{
	int i;

	for (i = 0; i <= 12; i++)
	{
		deck[i] = i + 1;
		deck[i + 13] = 100 + i + 1;
		deck[i + 26] = 200 + i + 1;
		deck[i + 39] = 300 + i + 1;
	}
	
}
void deal()
{   
    
	static int j = 0;
	player_value = player_value + deck[j];
	j++;
	player_value = player_value + deck[j];
	j++;
	dealer_value = dealer_value + deck[j];
	hidden_card = deck[j+1];
	
}
void get_hit()
{
	char answer;
	
	printf("hit ? y/n \n");
	
	scanf("%c",&answer);
	switch(answer){
		case 'y': hit = 1;
		          break;
	    case 'n': hit = 0;
		          break;
	    default : puts("Invalid option\n" );
		          break;
	}
	
}

void display_deck()
{
	int i;

	for (i = 0; i < 52; i++)
		//cout << "deck[" << i << "] = " << deck[i] << endl;
	printf("deck[%d] = %d",i + 1,deck[i]);

}
void deal_player_card()
{
	static int k = 4;
	player_value = player_value + deck[k];
	k = k + 2;
	
}
void deal_dealer_card()
{
	static int h = 5;
	dealer_value = dealer_value + hidden_card;
	dealer_value = dealer_value + deck[h];
	h = h + 2;
}
void determine_winner()
{
	int dealer_win;
	int player_win;
	if(dealer_value <= 21 && dealer_value > player_value){
		dealer_win = 1;
		player_win = 0;}
	else if(player_value <= 21 && player_value > dealer_value){
		dealer_win = 0;
		player_win = 1;}
	else if(dealer_value == 21 && player_value == 21){
		dealer_win = 1;
		player_win = 1;}
		
}


