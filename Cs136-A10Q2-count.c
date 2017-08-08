#include "Cs136-A10Q2-count.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

struct bstnode {
   	int item;
   	int times;
	struct bstnode *right;
   	struct bstnode *left;
};

struct count {
   	struct bstnode *bst;
   	int total;
   	int unique;
   	int mostfreq_item;
   	int mostfreq_times;
};

Count create_Count(void){
    Count new = malloc(sizeof(struct count));
    new->bst = NULL;
    new->total = 0;
   	new->unique = 0;
   	new->mostfreq_item = 0;
   	new->mostfreq_times = 0;
   	return new;
}

void destroy_bst(struct bstnode *bst) {
	if (bst == NULL){
        return;
    }
	destroy_bst(bst->right);
	destroy_bst(bst->left);
	free(bst);
}

void destroy_Count(Count c){
    assert(c != NULL);
    destroy_bst(c->bst);
    free(c);
}
    
void next(Count c, int i) {
   	c->total = c->total+1;
   	struct bstnode *pre = NULL;
   	struct bstnode *cur = c->bst;
   	while(cur != NULL) {
      	if(i == cur->item){
         	cur->times++;
         	if(c->mostfreq_times < cur->times){
            	c->mostfreq_times = cur->times;
            	c->mostfreq_item = i;
      		}
        return;
        }
      	pre = cur;
      	if(i < cur->item){
         	cur = cur->left;
        }
      	else{
         	cur = cur->right;
        }
 	}
   	struct bstnode *new = malloc(sizeof(struct bstnode));
   	new->item = i;
   	new->times = 1;
    new->right = NULL;
   	new->left = NULL;
   	if(pre == NULL) {
      	c->unique++;
      	c->mostfreq_times = 1;
      	c->mostfreq_item = i;
      	c->bst = new;
    }
   	else if(i < pre->item) {
      	c->unique++;
      	pre->left = new;
    }
   	else{
      	c->unique++;
      	pre->right = new;
    }
}
    
int total(Count c){
    return c->total;
}

int unique(Count c){
    return c->unique;
}

int count_helper(struct bstnode *bst, int n) {
   	if(bst == NULL){
      	return 0;
	}
    else{
   		if(n == bst->item){
      		return bst->times;
      	}
   		else if(n < bst->item){
      		return count_helper(bst->left, n);
      	}
   		else{
      		return count_helper(bst->right, n);
      	}
   	}
}

int count(Count c, int i){
	return count_helper(c->bst,i);
}
    
int mostfreq(Count c){
	return c->mostfreq_item;
}

void stats_helper(struct bstnode *bst) {
   	if(bst == NULL) {
        return;
    }
   	stats_helper(bst->left);
   	printf("%d: %d\n", bst->item, bst->times);
   	stats_helper(bst->right);
}

void stats(Count c){
	stats_helper(c->bst);
}











