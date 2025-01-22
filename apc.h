#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char* argv[]);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);


/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *argv[]);

//Double linked list functions
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
int dl_delete_list(Dlist **head, Dlist **tail);

#endif
