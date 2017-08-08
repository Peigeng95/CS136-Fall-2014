//list.c

#include "Cs136-A9Q1-list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// see list.h for documentation
struct llist *create_list(void) {
	struct llist *lst = malloc(sizeof(struct llist));
	lst->front = NULL;
	lst->back = NULL;
	lst->length = 0;
	return lst;
}

// see list.h for documentation
void destroy_list(struct llist *lst) {
	assert(lst);
	struct llnode *current = lst->front; 
	struct llnode *next;
	while (current != NULL) {
		next = current->next; // note the next pointer
		free(current); // delete the node
		current = next; // advance to the next node
	}
	free(lst); 
}	


// see list.h for documentation
int list_length(struct llist *lst) {
	return lst->length;
}


// see list.h for documentation
void print_list(struct llist *lst) {
	struct llnode *current;
	for (current = lst->front; current != NULL; current = current->next)
		printf("  %d", current->item);
	printf("\n");
}

// YOUR IMPLEMENTATION STARTS HERE

void add_to_front(int n, struct llist *lst){
    struct llnode *new = malloc(sizeof(struct llnode));
    new -> item = n;
    new -> next = NULL;
    if(lst->length == 0){
        lst->front=new;
        lst->back=new;
    }
    else{
        new -> next = lst -> front;
    	lst -> front = new;
    }
    lst -> length = lst -> length +1;
}

void add_to_back(int n, struct llist *lst){
	struct llnode *new = malloc(sizeof(struct llnode));
	new->item = n;
	new->next = NULL;
	if (lst->length == 0) {
		lst->front = new;
		lst->back = new;
	} 
    else {
		lst->back->next = new;
		lst->back = new;
	}
	lst->length++;
}

int delete_from_front(struct llist *lst){
    assert(lst->front != NULL);
    struct llnode *backup = lst->front;
    int a = backup-> item;
    lst->front = (lst->front)->next;
    lst->length = lst->length -1;
    free(backup);
    return a;
}

int get_nth(struct llist *lst, int index){
    assert(index >= 0);
    assert(index <= lst->length-1);
    struct llnode *current = lst->front;
    for(int i=0; i<index; i++){
        current = current->next;
    }
    return current->item;
}

void insert_nth(struct llist *lst, int index, int data){
    assert(index >= 0);
    assert(index <= lst->length);
    if(index == 0){
        add_to_front(data,lst);
    }
    else if(index == lst->length){
        add_to_back(data,lst);
    }
    else{
        struct llnode *cur = lst->front;
        for(int i = 0;i < index ;i++) {
        	cur = cur->next;
        }
        struct llnode *new = malloc(sizeof(struct llnode));
        new->item = data;
        new->next = cur->next;
        cur->next = new;
        lst->length = lst->length + 1;
    }
}

void lst_append(struct llist *lst1, struct llist *lst2){
    while(lst2->front != NULL){
        add_to_back(lst2->front->item,lst1);
        lst1->length = lst1->length +1;
        delete_from_front(lst2);
    }
    lst2->back = NULL;
    lst2->length = 0;
}

bool eq_list(struct llist *lst1, struct llist *lst2){
    if(lst1->length != lst2->length)
        return 0;
    int a=1;
    struct llnode *cur1 = lst1->front;
    struct llnode *cur2 = lst2->front;
    while(cur1 != NULL){
        if(cur1->item != cur2->item){
            a=0;
            break;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return a;
}

int maxminlist(struct llist *lst, int *max, int *min){
    if(lst->length == 0){
        return 0;
    }
    *max = lst->front->item;
    *min = lst->front->item;
    int i=0;
    int cur = 0;
    struct llist *current = lst;
    while(i < current->length){
        cur = get_nth(lst,i);
        if( *max <cur){
            *max = cur;}
        if(*min > cur){
            *min = cur;}
        i++;
    }
    return 1;
}
       	
