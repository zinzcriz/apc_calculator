#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
    	/* 67 + 12 ( both equal ) */
	/* 88 + 12 ( carry ) */
	/* 88 + 2 ( 2nd_opernad < 1st_opernad ) */
	/* 2 + 88 ( 1st_operand < 2nd_opernad ) */

	/*(i) => temp1 != NULL || temp2 != NULL 
	{
	    (ii) => temp1 != NULL && temp2 != NULL 
	
		(iii) temp1 != NULL && temp2 == NULL 

		(iv) temp1 == NULL && temp2 != NULL 
	}
	carry == 1 
	{
	    / * add * /
		/ * reset carry with 0 * /*/
	int carry=0;
	Dlist *temp1,*temp2;
	temp1=*tail1;
	temp2=*tail2;
	int sum,num1,num2;
	while(temp1!=NULL || temp2!=NULL)
	{   
		//printf("hai\n");
		if(temp1!=NULL)
		{
			num1=temp1->data;
		}
		else{
			num1=0;
		}
		if(temp2!=NULL)
		{
			num2=temp2->data;
		}
		else{
			num2=0;
		}
		sum=num1+num2;
		sum=sum+carry;
		if(sum>9)
		{
          carry=sum/10;
		  sum=sum-(carry*10);
		}
		else{
			carry=0;
		}
		dl_insert_first(headR,tailR,sum);
		sum=0;
		if(temp1!=NULL)
		    temp1=temp1->prev;
		if(temp2!=NULL)
		    temp2=temp2->prev;
	}
	if(carry!=0)
		    dl_insert_first(headR,tailR,carry);
	//print_list(*headR);
}
