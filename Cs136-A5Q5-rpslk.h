// rplsk.h

// This module provides a number of utility functions 
// for playing a game of rpslk.

// rpslk_winner(player, bot) determines the winner of a round of rpslk
//   PRE:  player and bot are one of 'r', 'p', 's', 'l', 'k'
//   POST: returns -1 if player beats bot,
//                  0 if player ties bot,
//                  1 if bot beats player 
//         updates statistics on who won (player, bot or tie)
//         displays winner message 
//           (e.g., "Paper covers rock. Player wins!\n")
//           hint: check out messages.txt
int rpslk_winner(char player, char bot);


// get_challenge_rating() prompts the user for the difficulty rating
//   PRE:  true
//   POST: Displays a prompt message, and reads in input
//         returns the integer entered by user
int get_challenge_rating(void);


// get_player_throw() prompts the user for their throw
//   PRE:  true
//   POST: Displays a prompt message, and reads in input
//         returns 'r', 'p', 's', 'l', or 'k'
char get_player_throw(void);


// get_play_again_response() prompts the user to play again
//   PRE:  true
//   POST: Displays a prompt message, and reads in input
//         returns 'y' or 'n'
char get_play_again_response(void);


// Prints the results of an rpslk game
//   PRE:  true
//   POST: Displays several game statistics
void print_game_summary(void);

