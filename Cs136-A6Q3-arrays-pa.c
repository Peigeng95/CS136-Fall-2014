// =======================================
// = CS136, S14: Assignment 6, Problem 3 =
// = =================================== =
// = Author: C Master [1337]             =
// =======================================

// Example of arrays with pointer arithmetic.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// sum_arr(arr, len) sums all of the elements in arr.
// PRE:  arr is not NULL and len > 0
// POST: returns an int.
static int sum_arr(int *arr, int len) {
  // Checks pre-conditions.
  assert(arr != NULL);
  assert(len > 0);

  int sum = 0;

  for (int i = 0; i < len; ++i) {
    sum += *(arr + i);
  }

  return sum;
}

int main(void) {
  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // can't change this.

  printf("Sum from 1...10 = %d\n", sum_arr(arr, 10));

  return 0;
}
