#include <stdbool.h>
#include <limits.h>
// a module for storing a BST in an array

extern const int EMPTY;
// in your atree.c, define:
// const int EMPTY = INT_MIN;

struct atree {
   int *data;
   int maxheight;
};
// data will be an array of length 2^maxheight


// create_atree(maxheight) returns a new atree structure 
//     that can support a BST with maximum height maxheight
//     initially, all nodes will be EMPTY
//   PRE:  maxheight >= 1
//   POST: caller must eventually call destroy_atree() to free
//   TIME: O(2^n), where n = maxheight
struct atree *create_atree(int maxheight);

// destroy_atree(at) will free the nodes
//     and then free the structure at itself
//   PRE:  at was previously returned from create_atree
//   POST: at is no longer valid
//   TIME: O(1)
void destroy_atree(struct atree *at);

// atree_add(at, i) adds the integer i to at
//     increasing the maxheight of the tree by 1 if necessary
//     if i already exists in at, this function does nothing
//   PRE:  at is valid
//         i != EMPTY
//   POST:  i will be in the tree
//          if necessary, the maxheight of the tree will be increased by 1, 
//          and the data array will be resized accordingly
//   TIME: [amortized] O(h), where h = at->maxheight
void atree_add(struct atree *at, int i);

// atree_search(a, i) will return true if i is in at
//     and false otherwise
//   PRE:  at is valid
//         i != EMPTY
//   POST: true or false
//   TIME: O(h), where h = at->maxheight
bool atree_search(struct atree *at, int i);

