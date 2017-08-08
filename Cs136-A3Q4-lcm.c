/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: lcm.c 
 * CS 136 Fall 2014 - Assignment 3, Problem 4b
 * Description: Least Common Multiple 
***********************************************/

/* Purpose:  finds the greatest common divisor for the integers a and b.
 * PRE: Int >0 Int >0
 * POST: produce value >0
*/
static int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, (a%b));
}
/* lcm (int a, int b) computes least common multiple of a and b
 * PRE: a > 0, b > 0, least common multiple of a and b is < 2,147,483,648 (2^31) 
 * POST: Returns an integer > 0
*/
int lcm(int a, int b) {
	const int c=gcd(a,b);
    const int d= (a/c)*(b/c)*c;
    return d;
}
