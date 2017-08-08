/*
 *    Sort.h
 * This module provides some functions for sorting arrays
 */

// sort_str(char *a[], int len) sorts the array a
//   PRE: len >= 0; a is an array of length len
//   POST: a is sorted in ascending order
//   TIME: O(n*log n), n is len, the length of the array
void sort_str(char *a[], int len);
void sort_int(int a[], int len);
void sort_char(char a[], int len);
