/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: rpslk.c 
 * CS 136 Fall 2014 - Assignment 5, Problem 5
 * Description:  implement an interactive Rock-Paper-Scissors-Lizard-Spock game 
***********************************************/
#include <stdio.h>
// see rpslk.h for interface
int rate;
char player;
char again;
int p_won=0;
int b_won=0;
int tie=0;
int rpslk_winner(char player, char bot) {
    if(player == 's'){
        if(bot == 'p'){
            printf("Scissors cut paper. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 'l'){
            printf("Scissors decapitate lizard. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 's'){
            printf("It's a tie!\n");
            tie++;
            return 0;
        }
        else if(bot == 'k'){
            printf("Spock smashes scissors. Bot wins!\n");
            b_won++;
            return 1;
        }
        else if(bot == 'r'){
            printf("Rock crushes scissors. Bot wins!\n");
            return 1;
            b_won++;
        }
    }
	else if(player == 'r'){
        if(bot == 's'){
            printf("Rock crushes scissors. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 'l'){
            printf("Rock crushes lizard. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 'r'){
            printf("It's a tie!\n");
            tie++;
            return 0;
        }
        else if(bot == 'k'){
            printf("Spock vaporizes rock. Bot wins!\n");
            b_won++;
            return 1;
        }
        else if(bot == 'p'){
            printf("Paper covers rock. Bot wins!\n");
            b_won++;
            return 1;
        }
    }
    else if(player == 'p'){
        if(bot == 'r'){
            printf("Paper covers rock. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 'k'){
            printf("Paper disproves Spock. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 'p'){
            printf("It's a tie!\n");
            tie++;
            return 0;
        }
        else if(bot == 's'){
            printf("Scissors cut paper. Bot wins!\n");
            b_won++;
            return 1;
        }
        else if(bot == 'l'){
            printf("Lizard eats paper. Bot wins!\n");
            b_won++;
            return 1;
        }
    }
    else if(player == 'l'){
        if(bot == 'p'){
            printf("Lizard eats paper. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 'k'){
            printf("Lizard poisons Spock. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 'l'){
            printf("It's a tie!\n");
            tie++;
            return 0;
        }
        else if(bot == 'r'){
            printf("Rock crushes lizard. Bot wins!\n");
            b_won++;
            return 1;
        }
        else if(bot == 's'){
            printf("Scissors decapitate lizard. Bot wins!\n");
            b_won++;
            return 1;
        }
    }
    else if(player == 'k'){
        if(bot == 'r'){
            printf("Spock vaporizes rock. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 's'){
            printf("Spock smashes scissors. Player wins!\n");
            p_won++;
            return -1;
        }
        else if(bot == 'k'){
            printf("It's a tie!\n");
            tie++;
            return 0;
        }
        else if(bot == 'l'){
            printf("Lizard poisons Spock. Bot wins!\n");
            b_won++;
            return 1;
        }
        else if(bot == 'p'){
            printf("Paper disproves Spock. Bot wins!\n");
            b_won++;
            return 1;
        }
    }
    return 0;
}


// see rpslk.h for interface
int get_challenge_rating(void) {
    printf("Choose a challenge rating (1 - 1000000): ");
    scanf("%d",&rate);
  return rate;
}


// see rpslk.h for interface
char get_player_throw(void) {
    printf("What do you throw (r/p/s/l/k)? ");
    scanf("%c",&player);
    do{
        scanf("%c",&player);
    }while((player != 'r')&&(player != 's')&&(player != 'p')&&(player != 'k')&&(player != 'l'));
  return player;
}


// see rpslk.h for interface
char get_play_again_response(void) {
    printf("Would you like to play again (y/n)? ");
    scanf("%c",&again);
    do{
        scanf("%c",&again);
    }while((again != 'y')&&	(again != 'n'));
  return again;
}


// see rpslk.h for interface
void print_game_summary(void) {
    printf("----- Game Summary -----\n");
    printf("Player won %d rounds...\n",p_won);
    printf("Bot won %d rounds...\n",b_won);
    printf("Player and bot tied %d rounds...\n",tie);
    if (p_won > b_won){
        printf("Player wins!\n");}
    else if (p_won < b_won){
        printf("Bot wins!\n");}
    else
        printf("Tie!\n");
  return;
}

