/**
 * File: q1/mmstack.c
 * implements a Min/Max Stack ADT (MMStack)
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Cs136-A10Q1-mmstack.h"

struct llnode{
	int min;
    int max;
    int item;
    struct llnode *next;
};
struct mmstack {
    int length;
   	struct llnode *top;
};

//see interface
////////////////////////////////////////////////////
MMStack create_MMStack(void){
    MMStack new = malloc(sizeof(struct mmstack));
    new->length = 0;
    new->top = NULL;
    return new;
}

void destroy_MMStack(MMStack mms){
    while(mms->top != NULL){
        mms_pop(mms);
    }
    free(mms);
}
        
int mms_length(MMStack mms){
    return mms->length;
}
    
void mms_push(MMStack mms, int i){
    struct llnode* new = malloc(sizeof(struct llnode));
    if(mms->top == NULL){
        new->min = i;
        new->max = i;
        new->item = i;
        new->next = NULL;
        mms->length = mms->length + 1;
        mms->top = new;
    }
    else{
        if(i < mms->top->min){
            new->min = i;
            new->max = mms->top->max;
            new->item = i;
            new->next = mms->top;
            mms->length = mms->length + 1;
            mms->top = new;
        }
        else if(i> mms->top->max){
            new->min = mms->top->min;
            new->max = i;
            new->item = i;
            new->next = mms->top;
            mms->length = mms->length + 1;
            mms->top = new;
        }
        else{
            new->min = mms->top->min;
            new->max = mms->top->max;
            new->item = i;
            new->next = mms->top;
            mms->length = mms->length + 1;
            mms->top = new;
        }
    }
}

int mms_pop(MMStack mms){
    assert(mms != NULL);
    struct llnode* backup = mms-> top;
    int item = mms->top->item;
    mms->top = mms->top->next;
    mms->length = mms->length - 1;   
    free(backup);
    return item;
}

int mms_min(MMStack mms){
    return mms->top->min;
}

int mms_max(MMStack mms){
    return mms->top->max;
}

