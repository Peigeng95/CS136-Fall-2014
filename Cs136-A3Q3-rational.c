/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: rational.c 
 * CS 136 Fall 2014 - Assignment 3, Problem 3
 * Description: Working with rational numbers. 
***********************************************/
#include "Cs136-A3Q3-rational.h"

// see rational.h
struct rational R(int n, int d) {
  // NOTE: we will see later why this is rarely done in C.
  // However, for now we will do this to make your code
  // easier to program and test
  const struct rational r = {n, d};
  return r;
}
// your implementation below:

/* Purpose:  finds the greatest common divisor for the integers a and b.
 * PRE: Int >0 Int >0
 * POST: produce value >0
*/
static int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, (a%b));
}
// r_simp(a,b) simplified the rational
//   PRE:  a is valid rationals
//   POST: returns simplified rational
static struct rational r_simp(struct rational a){
    const int n= a.num;
    const int d= a.den;
    int gcdn= gcd(n,d);
    if(1 != gcdn){
        const struct rational r = {n/gcdn, d/gcdn} ;
        return r;
    }
    else
        return a;
}

struct rational r_add(struct rational a, struct rational b){
    const struct rational r =r_simp (R (a.num*b.den+b.num*a.den, a.den*b.den));
    return r;
}

struct rational r_sub(struct rational a, struct rational b){
    const struct rational r =r_simp (R (a.num*b.den-b.num*a.den, a.den*b.den));
    return r;
}

struct rational r_mult(struct rational a, struct rational b){
    const struct rational r =r_simp (R (a.num*b.num, a.den*b.den));
    return r;
}

struct rational r_div(struct rational a, struct rational b){
    const struct rational r =r_simp (R (a.num*b.den, a.den*b.num));
    return r;
}
