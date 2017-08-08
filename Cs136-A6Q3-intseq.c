/*********************************************** 
 * Name: 
 * Student ID:
 * File: intseq.c 
 * CS 136 Fall 2014 - Assignment 6, Problem 3b
 * Description: Implementing intseq.h with pointer
 *              arithmetic. 
***********************************************/

#include "Cs136-A6Q3-intseq.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


// See intseq.h for interface
int number_sum(int *seq, int len) {
  assert(seq != NULL);
    assert(len >=0);
    int sum=0;
    for(int i=0; i< len; i++){
        sum = *(seq+i) +sum;
    }
  return sum;
}


// See intseq.h for interface
int max_number(int *seq, int len) {
    assert(seq != NULL);
    assert(len >=0);
    int max=0;
    for(int i=0; i< len; i++){
        if(*(seq+i) > max)
            max = *(seq+i);
    }
  return max;
}


// See intseq.h for interface
int min_number(int *seq, int len) {
    assert(seq != NULL);
    assert(len >=0);
    int min=100000000;
    for(int i=0; i< len; i++){
        if(*(seq+i) < min)
            min = *(seq+i);
    }
  return min;
}


// See intseq.h for interface
int minmax_dist(int *seq, int len) {
    assert(seq != NULL);
    assert(len >=0);
    int count=0;
	int max = max_number(seq,len);
    int min = min_number(seq,len);
    for(int i=0; i< len; i++){
        if(*(seq+i) == min){
            for(int j=i; *(seq+j) != max; j++){
                count++;
            }
        }
    }
    return count;
}


// See intseq.h for interface
float seq_avg(int *seq, int len) {
    assert(seq != NULL);
    assert(len >=0);
    float sum=0;
    float n=0;
    for(int i=0; i< len; i++){
        sum = *(seq+i) +sum;
        n++;
    }
  return sum/n;
}


// See intseq.h for interface
bool seq_has_duplicates(int *seq, int len) {
    assert(seq != NULL);
    assert(len >=0);
    for(int i=0; i<len ; i++){
        for(int j=i; j<len ;j++){
            if(*(seq+i) == *(seq+j))
                return false;}}
	return true;
}


// See intseq.h for interface
int seq_most_occurrences(int *seq, int len) {
    assert(seq != NULL);
    assert(len >=0);
  	int i=0;
    int j=0;
    int count1=0;
    int count2=0;
    int a=0;
    int b=0;
    int c=0;
    while(i<len && j<len){
        for(int k=0;k<len;k++){
            a = *(seq + i);
            b = *(seq + j);
            c = *(seq + k);
            if (a == c)
                count1++;
            else if (b == c)
                count2++;
        }
        if(count2>count1)
            i++;
        else
            j++;
        count1=0;
        count2=0;
    }
    if(i == len)
        return *(seq + j);
    else
        return *(seq + i);
}

