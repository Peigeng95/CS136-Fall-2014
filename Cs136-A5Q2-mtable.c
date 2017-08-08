/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: mtable.c 
 * CS 136 Fall 2014 - Assignment 5, Problem 2
 * Description: that prints a multiplication table with w columns and h rows. Each row must be exactly 6*(w+1) characters wide, followed by a newline.
***********************************************/
#include <stdio.h>
// mtable(w,h)
// PRE: 1 <= w <= 12 and 1 <= h <= 70
// POST:
void mtable(int w, int h) {
    printf("   X |");
    for(int a=1; a<=w; a++)
        printf("  %2d |",a);
    printf("\n");
    for(int b=1; b<=w+1; b++)
        printf("------");
    printf("\n");
    
    
    for(int x=1; x<= h; x++){
        printf("  %2d |",x);
        for(int y=1; y<= w; y++){
        	printf(" %3d |",x*y);
        }
        printf("\n");
    }
}

