//date.h
// module for working with date which consists of day, month and year values

#include <stdbool.h>

struct date{
	int month;
	int day;
	int year;
};

//  is_valid(&d) determines if d is a valid date
//  PRE:  true
//  POST: returns true if *d is a valid date, false otherwise
bool is_valid(const struct date *d);

//  d_eq(&d1, &d2) determines if date d1 and d2 are equal
//  PRE:  *d1, *d2 are valid dates
//  POST: returns true if *d1 and *d2 are the same date, false otherwise
bool d_eq(const struct date *d1, const struct date *d2);


//  greaterthan(&d1, &d2) determines if d1 is after the d2 date
//  PRE:  *d1, *d2 are valid dates
//  POST: returns true if *d1 is after the *d2 date, false otherwise
bool greaterthan(const struct date *d1, const struct date *d2);


//  tomorrow(&d) adds one day to the date d
//  PRE:  *d is a valid date
//  POST: modifies (increments) the date in *d
//        new value of *d is a valid date 
void tomorrow(struct date *d);


//  next_leapday(&d) finds the date of the next leap day after the date d
//  PRE:  *d is a valid date
//  POST: modifies the date in *d to the date of the next leap day 
//        new value of *d is a valid date
void next_leapday(struct date *d);
