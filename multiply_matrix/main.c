#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[3][2],arr2[2][1],result[3][1]={0};
    printf("Enter the first matrix :\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            scanf("%i",&arr1[i][j]);
        }
    }
       printf("Enter the second matrix :\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<1; j++)
        {
            scanf("%i",&arr2[i][j]);
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<1; j++)
        {
            for(int k=0;k<2;k++){
            result[i][j]+=arr1[i][k] * arr2[k][j];

            }
        }
    }
                printf("\n");

    for(int i=0;i<3;i++){
        for(int j=0;j<1;j++){
            printf("%i ",result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
