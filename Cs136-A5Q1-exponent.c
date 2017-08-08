/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: exponent.c 
 * CS 136 Fall 2014 - Assignment 5, Problem 1
 * Description: read two int and output their exponent
***********************************************/

// exponent(a,b) returns a raised to the power of b (a^b)
// PRE: a>0, b>0
// POST: returns integer > 0
int exponent(int a, int b) {
    int c = 1;
    while(0 != b){
        c= a*c;
        b--;
    }
    return c;
}