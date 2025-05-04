#include<cstdio>
#include<cstdlib>
#include"6h.h"

bool checkbalance(char *str)
        {
            stack st;
            for(int i=0;str[i]!='\0';i++)
            {
                if(str[i]=='(')
                {
                    st.push(str[i]);
                }
                else if(str[i]==')')
                {
                        if(st.isempty()){return false;}
                        else
                        {
                            st.pop();
                        }
                }
                else {return false;}
            }
            return st.isempty();
        }

int main()
{
    char str[100];
    int choose;
    do
    {
        printf("\nChoose the operation to be performed from the following menu: \n");
    printf("1 To Check Balance\n2 To Exit\n");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
        printf("Enter the string which has only paranthesis: ");
        scanf("%s",str);
        if(checkbalance(str))
        {
            printf("The string %s is balanced with paranthesis stack.\n",str);
        }
        else
        {
            printf("The string %s is not balanced with paranthesis stack.\n",str);
        }

        case 2:
        printf("Exiting...\n");
        break;
        
        default:
        printf("Invalid Number.Please Try Again.\n");
    }
    }while(choose!=2);

    return 0;
}