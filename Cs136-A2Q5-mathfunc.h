/*********************************************** 
 * Name: 
 * Student ID:
 * File: mathfunc.h 
 * CS 136 Fall 2014 - Assignment 2, Problem 5
 * Description: A module containing miscellaneous 
 * math functions. 
***********************************************/

/* Purpose: produce the maximum value between integers a and b
 * PRE: Int Int
 * POST: produce an Int is the maximum of two.
*/
int max2(int a, int b);


/* Purpose: produce the minimum value between integers a and b
 * PRE: Int Int
 * POST: Produce an Int is the minimum of two
*/
int min2(int a, int b);


/* Purpose: produce the largest factor of an integer a, where a is 2
            or greater
 * PRE: Int Int
 * POST: produce int >= 1
*/
int maxfactor(int a);


/* Purpose: produce true if positive integers a and b are coprime,
            and false otherwise.
 * PRE: a>0 b>0
 * POST: produce boolean.
*/
int coprime(int a, int b);
