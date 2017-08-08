/*********************************************** 
 * Name: 
 * Student ID:
 * File: date.c 
 * CS 136 Fall 2014 - Assignment 2, Problem 4
 * Description: Implementation for the date
 * functions in date.h 
***********************************************/
#include "Cs136-A2Q4-date.h"
#include <stdio.h>
#include <stdbool.h>

bool is_valid(struct date d) {
    return ((((d.month == 12)||(d.month == 10)||(d.month == 8)||(d.month == 7)||(d.month == 5)||(d.month == 3)||(d.month == 1))&&(d.day < 32))||(((d.month == 11)||(d.month == 9)||(d.month == 6)||(d.month == 4))&&(d.day < 31))||((d.month == 2)&&(d.day < 29))|| ((((((d.year % 4)==0)&&((d.year % 100) !=0))||((d.year % 400) ==0))&&(d.month == 2))&&(d.day < 30)) ) ? 1 :0;
}

bool d_eq(struct date d1, struct date d2) { 
  return ((d1.year==d2.year)&&(d1.month)==(d2.month)&&(d1.day)==(d2.day)) ? 1 : 0;
}

bool greaterthan(struct date d1, struct date d2) {
  return ((d1.year > d2.year)||((d1.year==d2.year)&&(d1.month > d2.month))||((d1.year==d2.year)&&(d1.month==d2.month)&&(d1.day > d2.day))) ? 1 : 0 ;
}

