#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *argv[])
{
	/* Definition goes here */
	int c1 = strlen(argv[1]);
	int c2 = strlen(argv[3]);
	int l1, l2;
	if (c1 > c2)
	{
		digit_to_list(head1, tail1, head2, tail2, argv);
	}
	else if (c1 < c2)
	{
		printf("0\n");
		return 0;
	}
	else if (c1 == c2)
	{
		if (strcmp(argv[1], argv[3]) > 0)
		{
			digit_to_list(head1, tail1, head2, tail2, argv);
		}
		else if (strcmp(argv[1], argv[3]) < 0)
		{
			printf("0\n");
			return 0;
		}
		else if (strcmp(argv[1], argv[3]) == 0)
		{
			printf("1\n");
			return 0;
		}
	}
	int flag = 0, count = 0;
	Dlist *temp1, *temp2;
	l2 = 0;
	temp2 = *head2;
	while (temp2 != NULL)
	{
		l2++;
		temp2 = temp2->next;
	}
	while (flag != 1)
	{   
		subtraction(head1, tail1, head2, tail2, headR, tailR, NULL);
		count++;
		//print_list(*headR);
		dl_delete_list(head1,tail1);
		*head1 = *headR;
		*tail1 = *tailR;
		if ((*head1) == (*tail1) && (*head1)->data == 0)
		{
			flag = 1;
		}
		else
		{
			temp1 = *head1;
			temp2 = *head2;
			int flag1 = 0, l1 = 0;
			while (temp1 != NULL)
			{
				l1++;
				temp1 = temp1->next;
			}
			temp1 = *headR;
			while (flag1 != 1)
			{
				if (l1 < l2)
				{
					flag = 1;
					flag1 = 1;
				}
				else if(l1>l2)
				{
					flag1=1;
				}
				else if (l1 == l2)
				{
					if (temp1 == NULL || temp2 == NULL)
					{   
						flag1 = 1;
					}
					else if (temp1->data == temp2->data)
					{
						temp1 = temp1->next;
						temp2 = temp2->next;
					}
					else if (temp1->data < temp2->data)
					{
						flag = 1;
						flag1 = 1;
					}
					else if (temp1->data > temp2->data)
					{
						flag1 = 1;
					}
				}
			}
		}
		*headR = NULL;
		*tailR = NULL;
	}
	printf("%d\n", count);
}
