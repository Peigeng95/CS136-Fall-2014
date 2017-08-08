/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: char_offset.c 
 * CS 136 Fall 2014 - Assignment 3, Problem 1
 * Description: A introduction to chars! 
***********************************************/

/* Purpose: determines the absolute offset from one letter to the other, if one of them are not letter provide -1
 * PRE: char char
 * POST: produce value between -1 and 25
*/
//#include "char_offset.h"
int char_offset(char c1, char c2) {
    if ((c1 <=90) && (c1 >= 65))
    	return char_offset(c1+32,c2);
    else if ((c2 <=90) && (c2 >= 65))
       	return char_offset(c1,c2+32);
    else if((((c1 <=90) && (c1 >= 65))
        || ((c1 <= 122) && (c1 >= 97))) &&
        (((c2 <=90) && (c2 >= 65))
         || ((c2 <= 122) && (c2 >= 97)))){
		if(c2 >= c1){
    		int a = c2 - c1;
        	return a;}
    	else
           	char_offset(c2,c1);}
    else 
        return -1;
    return 0;
}
