#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10];
    for(int i=0 ; i<10 ; i++)
    {
        printf("please enter number:") ;
        scanf( "%i", &arr[i] ) ;
    }

    int number;
    printf("please enter number you want to search ");
    scanf( "%i", &number ) ;
    int flag=0;

    for(int i=0 ; i<10 ; i++)
    {
        if (arr[i] == number)
        {
            printf("the index of number you want is :");
            printf( "%i",i);
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf("the number not found");

    return 0;
}
