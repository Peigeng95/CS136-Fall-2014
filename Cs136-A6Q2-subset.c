/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: subset.c 
 * CS 136 Fall 2014 - Assignment 6, Problem 2
 * Description: check if there exist a subset with 
 * members that have a sum is a perdutilar number.
***********************************************/
#include <stdio.h>
#include <assert.h>
#include "Cs136-A6Q2-subset.h"
// subset(arr, len, sum) outputs each combination (solution) of 3 integers in arr 
// that add to sum followed by a message with the total number of solutions or a 
// message if no solutions exist.
// PRE:  arr is not NULL, arr has no duplicates, and len >= 0
// POST: if no solutions exist, output "No solution(s)\n".
//       if one or more solutions exist, output "x1 + x2 + x3 = sum\n" 
//       where the index of x1 < index of x2 < index of x3
//       for each solution, followed by "A total of z solution(s)\n", 
//       where z is the total number of solutions.
int num = 0;
void subset(int arr[], int len, int sum) {
	assert (arr != NULL);
    assert (len >=0);
    for(int a=0; a<= len -3; a++){
        for(int b=a+1; b<= len -2; b++){
            for(int c=b+1; c<= len -1;c++){
                if(arr[a]+arr[b]+arr[c] == sum){
                    num++;
                    printf("%d + %d + %d = %d\n",arr[a],arr[b],arr[c],sum);
                }
            }
        }
    }
    if (num == 0)
        printf("No solution(s)\n");
    else{
        printf("A total of %d solution(s)\n",num);
        num=0;}
        
}
