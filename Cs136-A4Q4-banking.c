/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: banking.c 
 * CS 136 Fall 2014 - Assignment 4, Problem 4
 * Description: Working with bank accounts!  
***********************************************/
#include <assert.h>
#include "Cs136-A4Q4-banking.h"
#include <stdio.h>
#include <stdbool.h>
int* pid;
int* pbal;
int take = 0;
int save = 0;
int count = 0;


struct bank_acct create_acct(int new_id, int new_bal){
    assert(new_id>0);
    assert(new_bal >=0);
    struct bank_acct acct={new_id,new_bal};
    return acct;
}

// see interface file
void set_active_acct(struct bank_acct *acct) {
    pid =&(*acct).id;
    pbal =&(*acct).balance;
    take = 0;
    save = 0;
    count = 0;
}


// see interface file
void deposit(int amt) {
    assert(amt >=0);
    *pbal = *pbal + amt;
    count++;
    if(amt > save)
        save = amt;
}


// see interface file
bool withdraw(int amt) {
    assert(amt >=0);
    if(*pbal >= amt){
        count++;
        *pbal = *pbal - amt;
        if(amt > take)
            take = amt;
    }
    return false;
}


// see interface file
int max_withdrawal(void) {
  return take;
}


// see interface file
int max_deposit(void) {
  return save;
}


// see interface file

int transaction_count(void) {
  return count;
}

