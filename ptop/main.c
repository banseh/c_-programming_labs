#include <stdio.h>
#include <stdlib.h>


//Pointer to Pointer to integer
int main()
{
    int x=200;
    int *ptr;
    int* *ptrTptr;
    ptr=&x;
    ptrTptr=&ptr;
    printf("%x", **ptrTptr);


        return 0;

}
