//texp.c

#include "Cs136-A9Q3-texp.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
//see texp.h for documentation
struct enode *newnode(void) { 
  struct enode *t=malloc(sizeof(struct enode)); 
  t->left=NULL; 
  t->right=NULL; 
  return t; 
}

//see texp.h for documentation
void destroy_tree(struct enode *t){
  if (NULL == t) {return;}
  destroy_tree(t->left);
  destroy_tree(t->right);
  free(t);
}



//YOUR IMPLEMENTATION STARTS HERE
int eval(struct enode *t){
    if((t->left == NULL)&&(t->right == NULL)){//Empty
        return t->arg;
    }
    else if(t->op == '+'){
        return (eval(t->left) + eval(t->right));
    }
    else if(t->op == '-'){
        return (eval(t->left) - eval(t->right));
    }
    else if(t->op == '*'){
        return (eval(t->left) * eval(t->right));
    }
    else {//(t->op == '/')
        assert(eval(t->right) !=0);
        return (eval(t->left) / eval(t->right));
    }	
}

//helper 1: To creat a tree in heap, user need to free it.
static struct enode *makenode(int num, char op){
   struct enode *new = malloc(sizeof(struct enode));
   new->arg = num;
   new->op = op;
   new->left = NULL;
   new->right = NULL;
   return new;
}


//helper 2: To break the string into 3 part to make a tree with left and right.

static struct enode *tree_helper(char* arr, int begin, int over){
   	if((arr[begin] >= '0') && (arr[begin] <= '9')){
   		return makenode(arr[begin] - '0', 'i');//base case(num) i means invaild
   	}
   	else if((arr[begin] == '+') || (arr[begin] == '-') || (arr[begin] == '*') || (arr[begin] == '/')){//when op
      	return makenode(INT_MIN, arr[begin]);//INT_MIN means invalid
   	}
   	else{//break arr into three parts to form three trees.
    	int place1;//indecate arr1 begin
      	int place2;//indecate arr1 over & arr2 start
      	place1 = begin + 1;
      	int count = 0;//count the bracket 
      	if((arr[place1] <= '9') && (arr[place1] >= '0')) {
         	place2 = place1+1;
        }//first one is a num (basecase)
      	else{//is bracket
         	count++;
         	place2 = place1+1;
         	while(count != 0){
            	if(arr[place2] == '('){
               		count++;
         		}
            	else if(arr[place2] == ')'){
               		count--;
            	}
            	place2++;
           	}
      	}
        int place3;//indecate arr2 over & arr3 start
      	int place4;//indecate arr3 over
      	place3 = place2+1;
      	count = 0;
        if((arr[place3] <= '9') && (arr[place3] >= '0')){
        	place4 = place3+1;
        }//first one is a num (basecase)	
        else{//is bracket
         	count++;
         	place4 = place3+1;
         	while(count != 0){
            	if(arr[place4] == '('){
               		count++;
             	}
            	else if(arr[place4] == ')'){
               		count--;
            	}
            	place4++;
          	}  
     	}
      	struct enode *left = tree_helper(arr, place1, place2);
        //make the left node call
      	struct enode *current = tree_helper(arr, place2, place3);
        //make the current node call
      	struct enode *right = tree_helper(arr, place3, place4);
        //make the right node call
      	current->left = left;
      	current->right = right;
      	return current;
   	}
}
//


struct enode *build_tree(char c[]){
    struct enode *tree = tree_helper(c,0,0); //call helper with indates
	return tree;

}



//helper to print all things, recur calls.
static int traverse_helper(struct enode *t){
    if ((t->left == NULL) && (t->right == NULL)){//basecase num print num.
      	printf("%d", t->arg);    
    }
   	else{//subtree print bracket and the op
      	printf("(");
      	traverse_helper(t->left);
      	printf("%c", t->op);
      	traverse_helper(t->right);
      	printf(")");
   	}
    return 0;
}
    
void traverse_inorder(struct enode *t){
	traverse_helper(t);//print all the arr 
    printf("\n");
}
            
            
    

    
    
    

    
