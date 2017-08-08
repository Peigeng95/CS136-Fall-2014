/*********************************************** 
 * Name: Peigeng Han
 * Student ID: 20533982
 * File: reservation.c 
 * CS 136 Fall 2014 - Assignment 6, Problem 1
 * Description: write part of the automated reservation software
***********************************************/
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "Cs136-A6Q1-reservation.h"
int ec_avi=0;
int fc_avi=0;
int ec_count=0;
int fc_count=0;
int fc_place=0;
int ec_place=0;
// See reserveration.h for interface
struct manifest M(int num_fc, int num_ec) {
    assert(num_fc >= 0);
  	assert(num_ec >= 0);
    assert(num_fc + num_ec <= 100);
    struct manifest plane;
    plane.num_fc=num_fc;
    plane.num_ec=num_ec;
    for(int i=0; i <= 99; i++){
        plane.seats[i]=0;}
    ec_avi=num_fc;
    fc_count=num_fc;
    ec_count=num_ec;
  return plane;
}


// See reserveration.h for interface
int get_available_seats_fc(struct manifest *man) {
  	int avi_fc = (*man).num_fc;
    return avi_fc;
}


// See reserveration.h for interface
int get_available_seats_ec(struct manifest *man) {
    int avi_ec = (*man).num_ec;
    return avi_ec;
}


// See reserveration.h for interface
int book_seat_fc(struct manifest *man) {
    if(fc_count >0){
        return fc_avi+fc_place;
   		fc_count--;
        fc_place++;}
    else 
        return -1;
}


// See reserveration.h for interface
int book_seat_ec(struct manifest *man) {
   if(ec_count >0){
       	return ec_avi+ec_place;
        ec_count--;
        ec_place++;}
    else 
        return -1;
}


// See reserveration.h for interface
void reset_manifest(struct manifest *man) {
     for(int i=0; i <= 99; i++){
       (*man).seats[i]=0;}
}

