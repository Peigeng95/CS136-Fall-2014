#include "Cs136-A10Q3-strqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct llnode{
   	char *item;
   	struct llnode *next;
};

struct strqueue{
   	struct llnode *front;
   	struct llnode *back;
   	int length;
};

StrQueue create_StrQueue(void) {
   	StrQueue new = malloc(sizeof(struct strqueue));
   	new->front = NULL;
   	new->back = NULL;
   	new->length = 0;
   	return new;
}

void destroy_StrQueue(StrQueue sq){
   	struct llnode *cur = sq->front;
   	struct llnode *next = NULL;
   	while(cur != NULL) {
      	next = cur->next;
      	free(cur->item);
      	free(cur);
      	cur = next;
  	}
   	free(sq);
}

void sq_add_back(StrQueue sq, const char *str){
   	struct llnode *new = malloc(sizeof(struct llnode));
   	char *mystr = malloc(sizeof(char) * strlen(str) + 1);
   	strcpy(mystr, str);
   	new->item = mystr;
   	new->next = NULL;
   	if(sq->length == 0) {
        sq->length++;
      	sq->front = new;
     	sq->back = new;
   	}
   	else{
      	sq->length++;
      	sq->back->next = new;
      	sq->back = new;
  	}
}

char *sq_remove_front(StrQueue sq) {
   	if(sq->length == 0) {
      	return NULL;
    }
   	else {
      	struct llnode *cur = sq->front;
      	char *a = NULL;
        if(sq->length == 1) {
         	sq->length = sq->length -1;
         	sq->front = NULL;
         	sq->back = NULL;
         	a = cur->item;
         	free(cur);
       	}
        if(sq->length > 1) {
         	sq->length = sq->length - 1;
         	sq->front = sq->front->next;
         	a = cur->item;
         	free(cur);
        }      	
      	return a;
  	}
}

int sq_length(StrQueue sq) {
   	return sq->length;
}  
