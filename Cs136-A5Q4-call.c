/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: call.c 
 * CS 136 Fall 2014 - Assignment 5, Problem 4
 * Description: For each character of input, your program must print the character, UNLESS it is one of the following upper-case letters, in which case the corresponding number must be printed.
***********************************************/
#include <stdio.h>
int main() {
	char func;
  		do {
    		func = getchar();
            if ((func == 'A')||(func == 'B')||(func == 'C')){
                printf("%d",2);}
            else if ((func == 'D')||(func == 'E')||(func == 'F')){
                printf("%d",3);}
            else if ((func == 'G')||(func == 'H')||(func == 'I')){
                printf("%d",4);}
            else if ((func == 'J')||(func == 'K')||(func == 'L')){
                printf("%d",5);}
            else if ((func == 'M')||(func == 'N')||(func == 'O')){
                printf("%d",6);}
            else if ((func == 'P')||(func == 'Q')||(func == 'R')||(func == 'S')){
                printf("%d",7);}
            else if ((func == 'T')||(func == 'U')||(func == 'V')){
                printf("%d",8);}
            else if ((func == 'W')||(func == 'X')||(func == 'Y')||(func == 'Z')){
                printf("%d",9);}
            else if (func == EOF){
                break;}
            else
                printf("%c",func);
  } while (func != EOF);
    return 0;
}
