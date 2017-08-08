/*********************************************** 
 * Name: 
 * Student ID:
 * File: mathfunc.c 
 * CS 136 Fall 2014 - Assignment 2, Problem 5
 * Description: An implementation of the math
 * functions declared in mathfunc.h 
***********************************************/

#include "Cs136-A2Q5-mathfunc.h"
#include <stdio.h>
static int max_helper (int a, int b){
    return ((a%b) == 0) ? (a/b) : (max_helper (a, b+1));}

int max2(int a, int b) {
  return (a > b) ? a : b;
}


int min2(int a, int b) {
  return (a < b) ? a : b;
}


int maxfactor(int a) {
  return max_helper (a,2);
}


int coprime(int a, int b) {
  return ((maxfactor (a)==1) && (maxfactor (b)==1)) ? 1 :
    (
    (((max2 (a,b))%(min2 (a,b)))==0) ? 0 : 
        0
    )
      ;
}

    
