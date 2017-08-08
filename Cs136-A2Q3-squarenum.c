/*********************************************** 
 * Name: 
 * Student ID:
 * File: squarenum.c 
 * CS 136 Fall 2014 - Assignment 2, Problem 3
 * Description: Implements the interface for
 * working with squared numbers from squarenum.h 
***********************************************/
#include "Cs136-A2Q3-squarenum.h"
#include  <stdbool.h>
#include <stdio.h>
int c = 1;
static int count_helper(int a, int b, int d){
    c=1;
    return (a==b) ? d : ((is_squarenum(a)) ? count_helper(a+1,b,d+1) : count_helper (a+1,b,d));
}


bool is_squarenum(int i) {
  c = c + 2;
  return (i < 1) ? 0 : ((i == 1) ? 1 : is_squarenum(i= i-c));
}


int next_squarenum (int i) {
   
	c=1;
  return  (is_squarenum(i+1) == 1) ? i+1 : next_squarenum (i+ 1);
} 

int count_sqnum(int a, int b) {
   c=1;
  return count_helper(a,b,0);
}
