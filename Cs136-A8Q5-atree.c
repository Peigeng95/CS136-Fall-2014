/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: atree.c 
 * CS 136 Fall 2014 - Assignment 8, Problem 5
 * Description:  storing a Binary Search Tree (BST) in an array
***********************************************/

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "Cs136-A8Q5-atree.h"

const int EMPTY = INT_MIN;

int pow1 (int a, int b){
    if(b==0)
        return 1;
    else{
        return a * pow1(a,b-1);
    }
}

struct atree *create_atree(int maxheight){
    struct atree *new = malloc(sizeof(struct atree));
    new -> maxheight = maxheight;
    int len = pow1(2,maxheight);
    int *arr = malloc(sizeof(int) * len);
    for(int i=0; i<len; i++){
        arr[i]=EMPTY;
    }
    new->data = arr;
    return new;
}

void destroy_atree(struct atree *at){
    free(at->data);
    free(at);
}

void atree_add(struct atree *at, int i){
    int current=0;
    int max = at->maxheight;
    int maxnum = pow1(2,max);
    int newmaxnum = pow1(2,max+1);
    while(1){
        if (current >= maxnum){
            at->maxheight= max +1;
            at->data = realloc (at->data, sizeof(int)*newmaxnum);
            for(int i=maxnum;i< newmaxnum;i++){
                at->data[i]=EMPTY;
            }
        }
        
        if ((at->data)[current] == EMPTY){
            (at->data)[current] = i;
            break;
        }
        else{
        	if((at->data)[current] == i){
            	break;}
        	else if((at->data)[current] < i){
                current = 2*current + 2;}
        	else if((at->data)[current] > i){
                current = 2*current + 1;}
        }
    }
    current=0;
}

bool atree_search(struct atree *at, int i){
    int *arr = at->data;
    int current=0;
    int bo =0;
    while(1){
        if (arr[current] == EMPTY){
            break;
        }
        else{
        	if(arr[current] == i){
                bo = 1;
            	break;}
        	else if(arr[current] < i){
            	current = 2*current + 2;}
        	else if(arr[current] > i){
                current = 2*current + 1;}
        }
    }
    current =0;
    return bo;
}
/*
int main(void){
    struct atree *a = create_atree(1);
    atree_add(a,2);
    atree_add(a,1);
    atree_add(a,3);
    for(int i=0; i<4; i++){
        printf("%d,",a->data[i]);
    }
}
*/
