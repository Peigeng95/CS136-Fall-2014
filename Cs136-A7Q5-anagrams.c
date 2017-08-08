/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: anagrams.c 
 * CS 136 Fall 2014 - Assignment 7, Problem 5
 * Description: return the number of anagram pairs in the array.
***********************************************/
#include "sort.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

static bool is_anagrams(char *st1,char *st2){
    int len1=0;
    while(st1[len1]){
        len1++;}
    int len2=0;
    while(st2[len2]){
        len2++;}
	if(len1 != len2)
        return 0;
    int equal = 1;
    for(int j=0; j<len1; j++){
        if(st1[j] != st2 [j])
            equal = 0;
    }
    return equal;          
}

int count_anagrams(char* strs[], int len){
    int count=0;
    for(int i=0; i<len; i++){
        int len_inner=0;        
        while(strs[i][len_inner]){
            len_inner++;
        }
        sort_char(strs[i],len_inner);
    }
    sort_str(strs,len);
    for(int i=0; i<len-1; i++){
        if(is_anagrams(strs[i],strs[i+1]))
           count++;
    }
    return count;
}
