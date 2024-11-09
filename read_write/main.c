#include <stdio.h>
#include <stdlib.h>
//1- pointer to integer  read & write

int main()
{
    int x;
    int *ptr;
    ptr=&x;
    printf("please enter int num") ;
    scanf("%i",ptr) ;
    printf("nmber is %i",*ptr);
    return 0;
}

