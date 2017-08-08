/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: strappend.c 
 * CS 136 Fall 2014 - Assignment 8, Problem 1
 * Description: returns a NEW string that contains all of the characters  * from s1, followed by all of the characters from s2
***********************************************/
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
char *strappend(const char *s1, const char *s2){
    int lens1=0;
    int lens2=0;
    while(s1[lens1] != '\0'){
        lens1++;
    }
    while(s2[lens2] != '\0'){
        lens2++;
    }
	int len = lens1 +lens2+1;
    char *str = malloc(sizeof(char) * len);
    int currents1=0;
    int currents2=0;
    int now=0;
    while(1){
        if(s1[currents1]!='\0'){
            str[now]=s1[currents1];
            currents1++;
            now++;
        }
        else if((s1[currents1] == '\0') && (s2[currents2] != 0)){
            str[now]=s2[currents2];
            currents2++;
            now++;
        }
        else{
            str[now] = '\0';
            break;
        }
    }        
    return str;
}