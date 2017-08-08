/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: fibonacci.c 
 * CS 136 Fall 2014 - Assignment 4, Problem 2
 * Description: Fibonacci implementation. 
***********************************************/

#include "Cs136-A4Q2-fibonacci.h"
int a=0;
int b=1;
int next_fibonacci(void) {
    int c=a+b;
    a=b;
    b=c;
    return c;
}
