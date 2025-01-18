#include "apc.h"
#include <stdio.h>
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    /*/ * run a loop for argc -1 times * /
    / * First operand * /

    / * Store the argv[1] into an char pointer * /
	char *str=agrv[1];
    / * Run a loop from str[i] != '\0' * /
	/ * get one by one char and convert that into an digit * /
	create a node and store the data 
	/ * by call insert at last function * /

     / * Second operand * /
     / * do the same steps * /*/
    
    char *str=argv[1];
    int i=0;
    int digit;
    while(str[i]!='\0')
    {
        digit=str[i]-48;
        dl_insert_last(head1,tail1,digit);
        i++;
    }
    //print_list(*head1);

    str=argv[3];
    i=0;
    while(str[i]!='\0')
    {
        digit=str[i]-48;
        dl_insert_last(head2,tail2,digit);
        i++;
    }
    //printf("\n");
    //print_list(*head2);

}
