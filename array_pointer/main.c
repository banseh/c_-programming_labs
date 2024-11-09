#include <stdio.h>
#include <stdlib.h>
//2- pointer to array  read and write   3 ways

int main()
{
 int arr[5];
    int *ptr=arr;
        /////////////////////////way1//////////////////////////////


    for (int i = 0; i < 5; i++,ptr++)
    {
        printf("Enter number at index %i\n",i);
        scanf("%i",ptr);
        //ptr++;
    }
    ptr=arr;
    for (int i = 0; i < 5; i++,ptr++)
    {
        printf("number at index %i=%i\n",i,*ptr);
    }
    ptr=arr;

/////////////////////way2///////////////////////////////

/*
     for (int i = 0; i < 5; i++)
    {
        printf("Enter number at index %i\n",i);
        scanf("%i",ptr+i);

    }
    for (int i = 0; i < 5; i++)
    {
        printf("number at index %i=%i\n",i,*(ptr+i));
    }
    */
    /////////////////////////way3//////////////////////////////

    /*
    for (int i = 0; i < 5; i++)
    {
        printf("Enter number at index %i\n",i);
        scanf("%i",&ptr[i]);

    }
    for (int i = 0; i < 5; i++)
    {
        printf("number at index %i=%i\n",i,ptr[i]);
    }
*/
        return 0;
}

