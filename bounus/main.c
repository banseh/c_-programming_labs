#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[3][3];
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            printf("please enter number at index  of array %i %i  :", i,j ) ;
            scanf( "%i", &arr1[i][j] ) ;
        }
    }

    int arr2[3][2];
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            printf("please enter number at index  of array %i %i  :", i,j ) ;
            scanf( "%i", &arr2[i][j] ) ;
        }
    }

    int arr_res[3][2]= {0} ;
    for( int i=0 ; i<3 ; i++)
    {
        for(int j=0; j<2 ; j++)
        {
            for(int k=0 ; k<3; k++)
            {
                arr_res[i][j]+= arr1[i][k] * arr2[k][j] ;

            }
        }
    }

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("%i  ", arr_res[i][j]) ;

        }
                    printf("\n") ;

    }
    return 0;
}
