/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: exp.c 
 * CS 136 Fall 2014 - Assignment 7, Problem 3
 * Description: Fast exp
***********************************************/

#include <assert.h>
#include <stdio.h>

// Summation:  sum[i = n to 0] O(1)
// Time:       O(logn)

int fast_exp(int x, int n){
    assert(n >= 0);
    if (n == 0)
        return 1;
    int help_memory = x;
    int result=1;
    for (int i=n; i>0; i=i/2){
        if(i%2 == 0){
            help_memory = help_memory*help_memory;
        }
        else{
            result = help_memory * result;
            help_memory=help_memory*help_memory;
        }
    }
    return result;
}
