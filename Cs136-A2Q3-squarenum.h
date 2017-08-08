// squarenum.h
// module for working with square numbers
// a square number is a non negative integer bigger than 1 that is the square of an integer bigger than one.
// examples of squarenum:  4 (the smallest), 9, 16, 25, 36, ...

#include <stdbool.h>

//is_squarenum(i) determines if i is a square number
//PRE: i>=1
//POST: returns true if i is a square number, false otherwise
bool is_squarenum(int i);

//next_squarenum(i) returns the smallest square number greater than i
//PRE: i>=0
//POST: returns square number > i
int next_squarenum(int i);


//count_sqnum(a,b) counts the number of  square numbers between a and b (inclusive)
//PRE: a>1,  b>1, b>a
//POST: returns the number of  square numbers between a and b (inclusive)
int count_sqnum(int a, int b);
