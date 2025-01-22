#include "apc.h"

int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *argv[])
{
	/* Definition goes here */
	int c1=strlen(argv[1]);
	int c2=strlen(argv[3]);
	if(c1>c2)
	{
		digit_to_list(head1,tail1,head2,tail2,argv);
	}
	else if(c1<c2)
	{
		printf("0\n");
		return 0;
	}
	else if(c1==c2)
	{
		if(strcmp(argv[1],argv[3])>0)
		{
			digit_to_list(head1,tail1,head2,tail2,argv);
		}
		else if(strcmp(argv[1],argv[3])<0)
		{
			printf("0\n");
		    return 0;
		}
		else if(strcmp(argv[1],argv[3])==0)
		{
			printf("1\n");
			return 0;
		}
	}
	int flag=0,count=0;
	Dlist *temp1,*temp2;
	while(flag!=1)
	{
		subtraction(head1,tail1,head2,tail2,headR,tailR,NULL);
		count++;
		//dl_delete_list(head1,tail1);
		*head1=*headR;
		*tail1=*tailR;
		print_list(*head1);
		if((*headR)==(*tailR) && (*headR)->data==0)
		{
			flag=1;
		}
		/*else{
			temp1=*headR;
			temp2=*head2;
			int flag1=0;
			while(flag1!=1)
			{
				if(temp1==NULL || temp2==NULL)
				       flag1=1;
				if(temp1->data==temp2->data)
				{
					temp1=temp1->next;
					temp2=temp2->next;
				}
				else if(temp1->data<temp2->data)
				{
					flag=1;
					flag1=1;
				}
				else if(temp1->data>temp2->data)
				{
					flag1=1;
				}
			}

		}*/
		//printf("Hai\n");
		*headR=NULL;
		*tailR=NULL;
	}
	printf("%d\n",count);
}
