#include "apc.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        //(*head)->prev=NULL;
        return SUCCESS;
    }
    new->next=*head;
    (*head)->prev=new;
    *head=new;
    return SUCCESS;

}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
   if(*head==NULL)
   {
       Dlist *new=malloc(sizeof(Dlist));
       if(new==NULL)
       {
           return FAILURE;
       }
       new->data=data;
       new->prev=NULL;
       new->next=NULL;
       *head=new;
       *tail=new;
       return SUCCESS;
   }
   Dlist *new=malloc(sizeof(Dlist));
   if(new==NULL)
   {
       return FAILURE;
   }
   new->data=data;
   new->prev=*tail;
   new->prev->next=new;
   new->next=NULL;
   *tail=new;
   return SUCCESS;
}



// void print_list(Dlist *head)
// {
// 	/* Cheking the list is empty or not */
// 	if (head == NULL)
// 	{
// 		printf("INFO : List is empty\n");
// 	}
// 	else
// 	{
// 	    printf("Head -> ");
// 	    while (head)		
// 	    {
// 		    /* Printing the list */
// 		    printf("%d <-", head -> data);

// 		    /* Travering in forward direction */
// 		    head = head -> next;
// 		    if (head)
// 		        printf("> ");
// 	    }
//     	printf(" Tail\n");
//     }
// }

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    //printf("Result: ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    	printf("\n");
    }
}

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    Dlist *temp=(*head);
    Dlist *prev=(*head);
    while(temp != NULL)
    {
        prev = temp;
        temp=temp-> next;
        free(prev);
    }
    *head=NULL;
    *tail = NULL;
    
}
