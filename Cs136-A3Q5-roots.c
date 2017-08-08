/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: roots.c 
 * CS 136 Fall 2014 - Assignment 3, Problem 5
 * Description: Module that works with the
 *              bisection method 
***********************************************/
#include <stdio.h>
/* Purpose:
 * PRE:
 * POST:
*/
float find_root(float a, float b, float c, float p, float q) {
    const float epsilon= 0.00001;
	const float r = (p+q)/2;
    const float v_p = a*p*p+b*p+c;
    const float v_q = a*q*q+b*q+c;
    const float v_r = a*r*r+b*r+c;
    if((-epsilon <= v_r)&&(epsilon >= v_r))
        return r;
    else{
    	if(v_p > 0){
    		if (v_r >0)
           		return find_root(a, b, c, r, q);
        	else
            	return find_root( a, b, c, p, r);
    	}
    	else{
        	if (v_r >0)
                return find_root( a, b, c, p, r);
        	else
            	return find_root( a, b, c, r, q);
    	}
    }
}