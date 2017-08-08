/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: fib.c 
 * CS 136 Fall 2014 - Assignment 7, Problem 2
 * Description: O(n) fib num.
***********************************************/
#include <assert.h>
#include <stdio.h>


// Summation:  sum[i = 1 to n] O(1)
// Time:       O(n)

int fast_fib(int n){
    assert(n > 0);
    int a=1;
    int b=1;
    int c=0;
    for(int i=2; i< n; i++){
        c = b;
        b = b + a;
        a = c;}
    return b;}