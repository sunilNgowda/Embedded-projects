#ifndef CRAPS_H
#define CRAPS_H
int roll_dice();
int check_result(int roll, int winner, int player_sum);
int get_player_bet();
extern void craps(int num_rolls);
#endif