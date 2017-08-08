/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: date.c 
 * CS 136 Fall 2014 - Assignment 4, Problem 3
 * Description: Updated date.h implementation:
 *              with POINTERS! 
***********************************************/
#include <stdbool.h>
#include "Cs136-A4Q3-date.h"
#include <assert.h>
// see header file documentation
bool is_valid(const struct date *d) {
    if(((*d).month==1)||((*d).month==3)||((*d).month==5)||((*d).month==7)||((*d).month==8)||((*d).month==10)||((*d).month==12)){
    	if(((*d).day <= 30)&&((*d).day > 0))
            return true;
        else
            return false;
    }
    else if(((*d).month==4)||((*d).month==6)||((*d).month==9)||((*d).month==11)){
    	if(((*d).day <= 31)&&((*d).day > 0))
            return true;
        else
            return false;
    }
    else if((*d).month==2)
    {
        if((((*d).year % 400)==0)||((((*d).year % 4)==0)&&(((*d).year % 100) != 0))){
            if(((*d).day <= 29)&&((*d).day > 0))
                return true;
            else
                return false;            
        }
        else{
            if(((*d).day <= 28)&&((*d).day > 0))
            	return true;
            else
            	return false;
        }      
    }
    else
        return false;

}


// see header file documentation
bool d_eq(const struct date *d1, const struct date *d2) {    if(((*d1).year==(*d2).year)&&((*d1).month==(*d2).month)&&((*d1).day==(*d2).day))
        return true;
    else
        return false;
}


// see header file documentation
bool greaterthan(const struct date *d1, const struct date *d2) {
    if((*d1).year > (*d2).year)
        return true;
    else if ((*d1).year == (*d2).year)
    {
    	if ((*d1).month > (*d2).month)
            return true;
        else if ((*d1).month == (*d2).month)
        {
            if ((*d1).day > (*d2).day)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}


// see header file documentation
void tomorrow(struct date *d) {
    const int day=(*d).day;
    const int month=(*d).month;
    const int year=(*d).year;
    struct date d1={month,day+1,year} ;
    struct date d2={month+1,1,year};
	struct date d3={1,1,year+1};
    if (is_valid  (&d1))
        *d=d1;
    else if (is_valid (&d2))
        *d=d2;
    else
        *d=d3;
}


// see header file documentation
void next_leapday(struct date *d) {
    int year1 = (*d).year+1;
    for(int year = (*d).year+1; year<= year1+8;year++){
        if((((*d).year % 400)==0)||((((*d).year % 4)==0)&&(((*d).year % 100) != 0)))
            break;
    }
}

