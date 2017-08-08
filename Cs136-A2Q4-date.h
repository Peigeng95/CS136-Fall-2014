//date.h
// module for working with date which consists of day,month and year values

#include <stdbool.h>

struct date{
	int month;
	int day;
	int year;
};

//is_valid(d) determines if d is a valid date
//PRE: d is a date
//POST: returns true if d is a valid date, false otherwise
bool is_valid(struct date d);

//d_eq(d1,d2) determines if date d1 and d2 are equal
//PRE: d1, d2 are valid dates
//POST: returns true if d1 and d2 are the same date, false otherwise
bool d_eq(struct date d1, struct date d2);


//greaterthan(d1,d2) determines if d1 is after the d2 date
//PRE: d1, d2 are valid dates
//POST: returns true if d1 is after the d2 date, false otherwise
bool greaterthan(struct date d1, struct date d2);
