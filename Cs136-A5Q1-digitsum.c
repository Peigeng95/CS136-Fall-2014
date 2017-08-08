/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: digitsum.c 
 * CS 136 Fall 2014 - Assignment 5, Problem 1
 * Description: returns true if the sum of the first and last digit of n is equal to the sum of the second and second last digit of n and is equal to ... and so on; false otherwise.
***********************************************/
#include <stdio.h>
#include <stdbool.h>

// is_digitsum(i) returns true if the sum of the first and last digit of n is equal to the sum of the second and second last digit of n and is equal to ... and so on; false otherwise.
// PRE: a > 0
// POST: true if the sum of each pair digit are equal, false otherwise.
bool is_digitsum(int i) {
	int dig=0;
    int l = i;
    while (l != 0){
    	l=l/10;
        dig++;
    }
    int dig2=dig;
    int first=1;
    int sum1;
    while (dig2 != 1){
        first = first *10;
        dig2--;
    }
    sum1 = i/first + i%10;
	int last =1;
    int sum2;
    if(dig % 2 == 0){
        while (dig != 2 ){
        	dig =dig -2;
            first = first/10;
            last = last *10;
            sum2 = (i / first) % 10 +( i /last )%10;
            if (sum1 != sum2){
                return false; 
                break;
            }
        }
        return true;        
    }
    else if (1 == dig)
        return true;
    else{
    	while (dig != 3 ){
        	dig =dig -2;
            first = first/10;
            last = last *10;
            sum2 = (i / first) % 10 + (i /last) %10;
            if (sum1 != sum2){
                return false; 
                break;
            }
        }
        if (sum1 == (i/(last*10) %10)){

                return true;}
        
        else return false;
            
    }
}