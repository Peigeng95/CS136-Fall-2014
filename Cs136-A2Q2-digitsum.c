/*********************************************** 
 * Name: 
 * Student ID:
 * File: digitsum.c 
 * CS 136 Fall 2014 - Assignment 2, Problem 2
 * Description: Given a number, sums the digits
 * and returns if a certain condition holds. 
***********************************************/

/* Purpose:
 * PRE:
 * POST:
*/
#include <assert.h>
#include <stdio.h>
#include "Cs136-A2Q2-digitsum.h"
#include <stdbool.h>
int is_digitsum(int n) {
  int a_1 = n%10;
  n = n /10;
  int a_2 = n%10;
  n = n /10;
  int a_3 = n%10;
  n = n /10;
  int a_4 = n%10;
  n = n /10;
  int a_5 = n%10;
  n = n /10;
  int a_6 = n%10;
  n = n /10;
  int a_7 = n%10;
  n = n /10;
  int a_8 = n%10;
  n = n /10;
  int a_9 = n%10;
  n = n /10;
  return (a_9 != 0) ? ((((a_1+a_9)==(a_2+a_8))&&(a_5==(a_3+a_7))&&(a_5==(a_4+a_6))&&((a_1+a_9)==a_5)) ? 1 : 0) :
    (
        (a_8 != 0) ? ((((a_1+a_8)==(a_2+a_7))&&((a_1+a_8)==(a_3+a_6))&&((a_1+a_8)==(a_4+a_6))) ? 1 : 0) :
        (
            (a_7 != 0) ? ((((a_1+a_7)==(a_2+a_6))&&((a_1+a_7)==(a_3+a_5))&&((a_1+a_7)==a_4)) ? 1 : 0) :
            (
                (a_6 != 0) ? ((((a_1+a_6)==(a_2+a_5))&&((a_1+a_6)==(a_3+a_4))) ? 1 : 0) :
                (
                    (a_5 != 0) ? ((((a_1+a_5)==(a_2+a_4))&&(a_1+a_5)==(a_3)) ? 1 : 0) :
                    (
                        (a_4 !=0) ? (((a_1+a_4)==(a_2+a_3)) ? 1 : 0) :
                        (
                            (a_3 != 0) ? (((a_1+a_3)==a_2) ? 1 : 0) : 1)
                        )
                    )
                )
            )
        );

}
