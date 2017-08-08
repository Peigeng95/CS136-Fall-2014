/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: closest.c 
 * CS 136 Fall 2014 - Assignment 7, Problem 4
 * Description:  provide a solution that is no worse than
***********************************************/
#include "sort.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
int closest(int arr[], int len, int *a, int *b){
    assert(len >= 2);
    sort_int(arr,len);
    int diff=100000;
    for(int i=0;i<len-1; i++){
        if(arr[i+1]-arr[i] < diff){
        	*a = arr[i];
           	*b = arr[i+1];
            diff = arr[i+1]-arr[i];
        }
    }
    return diff;
}