#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *argv[])
{
	/* Definition goes here */
	int c1, c2;
	c1 = strlen(argv[1]);
	c2 = strlen(argv[3]);
	int flag = 0;
	Dlist *temp1, *temp2;
	if (c1 > c2)
	{
	}
	else if (c1 < c2)
	{
		temp1 = *head1;
		temp2 = *tail1;
		*head1 = *head2;
		*tail1 = *tail2;
		*head2 = temp1;
		*tail2 = temp2;
		flag = 1;
	}
	else if (c1 == c2)
	{
		if (strcmp(argv[1], argv[3]) > 0)
		{
		}
		else if (strcmp(argv[1], argv[3]) < 0)
		{
			temp1 = *head1;
			temp2 = *tail1;
			*head1 = *head2;
			*tail1 = *tail2;
			*head2 = temp1;
			*tail2 = temp2;
			flag = 1;
		}
		else{
			printf("0\n");
			return 0;
		}

	}
	temp1=*tail1;
	temp2=*tail2;
	int num1,num2,sub,carry=0;
	while(temp1!=NULL || temp2!=NULL)
	{
		if(temp1!=NULL)
		     num1=temp1->data;
		else
		     num1=0;
		if(temp2!=NULL)
		     num2=temp2->data;
		else
		     num2=0;
        if(carry==1)
		{
			num1=num1-1;
			carry=0;
		}
		if((num1-num2)<0)
		{
           carry=1;
		   num1=num1+10;
		}
		sub=num1-num2;
		if(sub==0 && temp1->prev==NULL)
		{

		}
		else
            dl_insert_first(headR,tailR,sub);
		if(temp1!=NULL)
		    temp1=temp1->prev;
		if(temp2!=NULL)
		    temp2=temp2->prev;
		 
	}
	if(flag==1)
	     printf("-");
	print_list(*headR);

}
