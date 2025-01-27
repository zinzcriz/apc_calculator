#include "apc.h"

int check_args(int argc,char *argv[])
{
    if(argc>3)
    {
        if(argv[2][0]=='+' || argv[2][0]=='-'|| argv[2][0]=='x' || argv[2][0]=='/')
        {
            char *str=argv[1];
            for(int i=0;str[i]!='\0';i++)
            {
                if(!isdigit(str[i]))
                {
                    printf("Only numbers should be entered as operands\n");
                    printf("Type --help to get details\n");
                    return FAILURE;
                }
            }
            str=argv[3];
            for(int i=0;str[i]!='\0';i++)
            {
                if(!isdigit(str[i]))
                {
                    printf("Only numbers should be entered as operands\n");
                    printf("Type --help to get details\n");
                    return FAILURE;
                }
            }
            return SUCCESS;
        }
        else{
            printf("Error in entering Arguments\n");
            printf("Type --help to get details\n");
        }
    }
    else if(argc==2 && strcmp(argv[1],"--help")==0)
    {
        call_help();
    }
    else{
        printf("The no of arguments required is 4\n");
        printf("Type --help to get details\n");
    }
    return FAILURE;
}

void call_help()
{
    printf("Enter input in this order:./a.out first_operand operator second_operand\n");
    printf("Available operators are +,-,x,/ \n");
    printf("eg:\n");
    printf("  ./a.out 1000 + 2000\n");
}