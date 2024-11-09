#include <stdio.h>
#include <stdlib.h>

int main()
{
    char defult;
    do
    {


        int num1, num2;
        char or ;
        printf("please enter the first number:")  ;
        scanf("%i", &num1) ;
        printf("please enter the second number:") ;
        scanf("%i", &num2);
        _flushall() ;

        printf("please enter operator:") ;
        scanf("%c", &or) ;
        switch (or)
        {
        case '+' :
            printf( "the result=%i",num1+ num2);
            printf( "\n");

            break;
        case '*' :
            printf( "the result=%i",num1* num2);
            printf( "\n");

            break;
        case '-' :
            printf(  "the result=%i",num1- num2);
            printf( "\n");

            break;
        case '/' :
            if(num2!=0)
            {
                printf( "the result=%i",num1/ num2);
                printf( "\n");

                break;
            }
            else
            {
                printf(" sorry number divided by 0 nt allowed");

            }
defult:
            printf("NA!!!!!!!!!!!");
            printf( "\n");

            break;
        }
        _flushall() ;

        printf("please enter y if you want to continue") ;
        scanf("%c", &defult) ;
    }
    while (defult==121);





    return 0;
}
