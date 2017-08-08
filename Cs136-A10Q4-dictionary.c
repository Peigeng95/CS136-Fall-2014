#include "Cs136-A10Q4-dictionary.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct bstnode {
   	void *key;
   	void *val;
   	struct bstnode *left;
   	struct bstnode *right;
};

struct dictionary {
   	struct bstnode *root;
   	CompareFunction ComF;
   	FreeFunction f_key;
   	FreeFunction f_val;
};

Dictionary create_Dictionary(CompareFunction comp_k, FreeFunction free_k, FreeFunction free_v){
   	struct dictionary *new = malloc(sizeof(struct dictionary));
   	new->ComF = comp_k;
   	new->root = NULL;
   	new->f_val = free_v;
   	new->f_key = free_k;
   	return new;
}

void destroy_bst(Dictionary dict,struct bstnode *bst){
   	if(bst == NULL){
       	return;
   	}
   	destroy_bst(dict, bst->left); 
   	destroy_bst(dict, bst->right);
   	dict->f_key(bst->key);
   	dict->f_val(bst->val);
   	free(bst);
}

void destroy_Dictionary(Dictionary dict){
   	destroy_bst(dict, dict->root);
   	free(dict);
}

void insert(Dictionary dict, void *k, void *v){
   	struct bstnode *pre = NULL;
   	struct bstnode *cur = dict->root;
   	while(cur != NULL){
      	int result = dict->ComF(k, cur->key);
      	pre = cur;
      	if(result < 0){
       	}
      	else if (result > 0) {
         	cur = cur->right;
       	}  
      	else {
         	cur->val = v;
         	return;
       	}
 	}
   	struct bstnode *new = malloc(sizeof(struct bstnode));
   	new->key = k;
   	new->val = v;
   	new->left = NULL;
   	new->right = NULL;
   	if(pre == NULL) {
      	dict->root = new;
      	return;
   	}
   	if(dict->ComF(k, pre->key) < 0) {
      	pre->left = new;
      	return;
   	}
   	if(dict->ComF(k, pre->key) > 0) {
      	pre->right = new;
      	return;
   	}
}

void *lookup(Dictionary dict, void *k) {
   	struct bstnode *bst = dict->root;
   	while(bst != NULL) {
      	int result = dict->ComF(k, bst->key);
      	if(result < 0) {
         	bst = bst->left;
       	}
      	else if(result > 0) {
         	bst = bst->right;
       	}
      	else {
         	return bst->val;
       	}
  	}
   	return NULL;
}
