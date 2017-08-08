/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: balanced.c
 * CS 136 Fall 2014 - Assignment 6, Problem 5
 * Description: returns true if str is balanced, otherwise false.
***********************************************/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "Cs136-A6Q5-balanced.h"
// is_balanced(str) determines if str is balanced.
// PRE:  str is not NULL
// POST: returns true if str is balanced, otherwise false. str is balanced if
//       every parenthesis is closed in the reverse order that it is opened. '('
//       is an opening parenthesis and ')' is a closing parenthesis. Other chars
//       in str are ignored.
bool is_balanced(char str[]) {
    assert(str != NULL);
  	int count=0;
    int len = 0;
    while(str[len]){
        if(count < 0){
            return 0;
        }
        else{
            if(str[len] == '('){
                count++;
            }
            else if(str[len] == ')'){
                count--;
            }
        }
        len++;
        
    }
    if(count == 0)
        return 1;
    else
        return 0;
}
