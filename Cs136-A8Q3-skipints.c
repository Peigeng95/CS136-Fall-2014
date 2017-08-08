/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: skipints.c 
 * CS 136 Fall 2014 - Assignment 8, Problem 3
 * Description: prints every k-th integer from the original sequence
***********************************************/
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
int main(void){
    int *arr = malloc(sizeof(int)*5);
    int max=5;
    int count=0;
    int current;
    int n=0;
    while(1){
        if(count == max){
            max *=2 ;
            arr=realloc(arr,sizeof(int)*max);
        }
        scanf("%d",&current);
        if(current != 0){
            arr[count]=current;
            count++;
        }
        else if(current == 0){
            scanf("%d",&n);
            break;
        }
    }
    for(int i=1; i<=count; i++){
        if(i%n == 0){
            printf("%d\n",arr[i-1]);
        }
    }
    free(arr);
    return 0;
}

