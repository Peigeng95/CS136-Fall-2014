/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: afilter.c 
 * CS 136 Fall 2014 - Assignment 8, Problem 2
 * Description: modifies the dynamic array da by removing
 * all elements where f(element) is false
***********************************************/
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Cs136-A8Q2-afilter.h"
void afilter(struct dyn_array *da, bool (*f)(int)) {
   int *copy = da->data;
   int len = 0;
   int current = 0;
   for(int i = 0; i < da->len; i++) {
      if(f(copy[i]) == true) {
         len++;
         }
      }
   int arr[len];
   for(int i = 0; i < da->len; i++) {
      if(f(copy[i]) == true) {
         arr[current] = copy[i];
         current++;
         }
      }
   da->len = len;   
   for(int i = 0; i < len; i++) {
      copy[i] = arr[i];
   }
}
