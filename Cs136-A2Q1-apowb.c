/*********************************************** 
 * Name: 
 * Student ID:
 * File: apowb.c 
 * CS 136 Fall 2014 - Assignment 2, Problem 1
 * Description: Function to find whether a number
 * is a power of another number.
***********************************************/

/* Purpose: add up the base
 * PRE: j >0 , u > 0
 * POST: num
*/
#include "Cs136-A2Q1-apowb.h"
static int return_num (int j,int u){
    return (u == 1) ? j : (j+ return_num(j,u-1));
}
/* Purpose: that determines what power is a of b;
 * PRE: h>0 j>0 k>0 l>=0
 * POST: num of power
*/
static int apowb_helper (int h, int j, int k, int l){
	return (h < j) ? 0 : ((h == j) ? (l+1) : (apowb_helper (h, return_num (j, k), k, (l+1))));
}
/* Purpose: that determines if a is some power of b;
 * PRE: a > b
 * POST: Union (false, num)
*/
int is_apowb(int a, int b) {
  return apowb_helper(a ,b ,b ,0);
}

