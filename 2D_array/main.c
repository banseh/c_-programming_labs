#include <stdio.h>
#include <stdlib.h>

int main()
{

    int arr[3][4];
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            printf("please enter number at index  of array %i %i  :", i,j ) ;
            scanf( "%i", &arr[i][j] ) ;
        }
    }



    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            printf("%i ",arr[i][j] ) ;

        }
        printf("\n") ;

    }

    printf("\n") ;

    int sum[3]= {0};
    for(int i=0 ; i<4 ; i++)
    {
        for(int j = 0; j <3;j++)
        {
            sum[i] += arr[j][i];

        }


    }
    printf("avg of first col is:%i",  sum[0]/3) ;
    printf("\n") ;

    printf("avg of second col is:%i",  sum[1]/3);
    printf("\n") ;

    printf("avg of third col is:%i",  sum[2]/3);



    return 0;
}
