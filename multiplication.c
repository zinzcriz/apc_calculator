#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	Dlist *headR2 = NULL, *tailR2 = NULL;
	Dlist *headB = NULL, *tailB = NULL;
	int count = 0, sum, carry = 0,i;
	while (temp2 != NULL)
	{
		if (count == 0)
		{
			while (temp1 != NULL)
			{
				sum = (temp1->data) * (temp2->data);
				sum = sum + carry;
				if (sum > 9)
				{
					carry = sum / 10;
					sum = sum - (carry * 10);
				}
				else
				{
					carry = 0;
				}
				// printf("%d\n",sum);
				dl_insert_first(headR, tailR, sum);
				sum = 0;
				temp1 = temp1->prev;
			}
			if (carry != 0)
			{
				dl_insert_first(headR, tailR, carry);
				carry=0;
			}
			temp1=*tail1;
			//printf("count1\n");
		}
		//count++;
		if (count == 1)
		{
			dl_insert_first(&headR2,&tailR2,0);
			while (temp1 != NULL)
			{
				sum = (temp1->data) * (temp2->data);
				sum = sum + carry;
				if (sum > 9)
				{
					carry = sum / 10;
					sum = sum - (carry * 10);
				}
				else
				{
					carry = 0;
				}
				//printf("sum is %d\n",sum);
				dl_insert_first(&headR2,&tailR2,sum);
				sum = 0;
				temp1 = temp1->prev;
			}
			if (carry != 0)
			{
				dl_insert_first(&headR2, &tailR2, carry);
				carry=0;
			}
			temp1=*tail1;
			//printf("count2\n");
		    //print_list(headR2);
			
		}
		if (count == 1)
		{
			addition(headR, tailR, &headR2, &tailR2, &headB, &tailB);
			//dl_delete_list(headR,tailR);
			*headR = headB;
			*tailR = tailB;
			dl_delete_list(&headR2,&tailR2);
			//dl_delete_list(&headB,&tailB);
			//print_list(*headR);
		}
		//print_list(*headR);
		if(count>=2)
		{
			//dl_delete_list(&headB,&tailB);
			//dl_delete_list(&headR2,&tailR2);
			headB=NULL;
			tailB=NULL;
			for(i=0;i<count;i++)
			{
				dl_insert_first(&headR2,&tailR2,0);
			}
			while (temp1 != NULL)
			{
				sum = (temp1->data) * (temp2->data);
				sum = sum + carry;
				if (sum > 9)
				{
					carry = sum / 10;
					sum = sum - (carry * 10);
				}
				else
				{
					carry = 0;
				}
				//printf("sum is %d\n",sum);
				dl_insert_first(&headR2,&tailR2,sum);
				sum = 0;
				temp1 = temp1->prev;
			}
			if (carry != 0)
			{
				dl_insert_first(&headR2, &tailR2, carry);
				carry=0;
			}
			//print_list(*headR);
			//print_list(headR2);
			addition(headR, tailR, &headR2, &tailR2, &headB, &tailB);
			//printf("count2\n");
			dl_delete_list(headR,tailR);
			*headR = headB;
			*tailR = tailB;
			//temp1=*tail1;
			dl_delete_list(&headR2,&tailR2);
			//dl_delete_list(&headB,&tailB);
			//printf("Hai\n");
		}
		temp2 = temp2->prev;
		temp1=*tail1;
		count++;
	}
	print_list(*headR);
}
