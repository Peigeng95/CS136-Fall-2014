/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: mgame.c 
 * CS 136 Fall 2014 - Assignment 5, Problem 3
 * Description: Write a C program mgame.c that is an interactive teaching aid to help grade 3 students with their multiplication skills.
***********************************************/
#include <stdlib.h>
#include <stdio.h>
int z=0;
int main() {
    int correct = 0;
    if(z == 0)
        srand(1234);
    z++;
    int n;
    printf("How many problems do you wish to solve? ");
    scanf("%d",&n);
    for (int i=n ;i>=1 ;i--){
        int y=((rand() % 10 )+1);
        int z=((rand() % 10 )+1);
        printf("%d X %d = ",y,z);
        int correct_answer= y*z;
        int user_answer;
        scanf("%d",&user_answer);
        if (user_answer != correct_answer){
            int d = (rand() % 3);
            if (d==0){
                printf("Incorrect.\n");}
            else if (d==1){
                printf("That is not right.\n");}
            else{
                printf("That is wrong.\n");}
            printf("Try again: %d X %d = ",y,z);
            scanf("%d",&user_answer);
            if (user_answer != correct_answer){
                printf("Sorry. The correct answer is %d X %d = %d\n",y,z,correct_answer);
            }
            else{
                int f = (rand() % 3);
            	if (f==0){
                	printf("Give me five!\n");}
            	else if (f==1){
                	printf("Keep up the good work!\n");}
            	else{
                    printf("Way to go!\n");}
                correct++;
            }
        }
        else{
        	int f = (rand() % 3);
            if (f==0){
            	printf("Give me five!\n");}
            else if (f==1){
                printf("Keep up the good work!\n");}
            else{
                printf("Way to go!\n");}
            correct++;
        }
    }
    float per = ((float) correct)/((float) n);
    int incorrect = n - correct;
    printf("----- Session Summary -----\n");
    printf("Correct answers: %d\n",correct);
    printf("Incorrect answers: %d\n",incorrect);
    printf("Percentage correct: %.2f%%\n",per*100);
}
