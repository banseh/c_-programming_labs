#include <stdio.h>
#include <stdlib.h>


void SwapA(int* left,int* right)
{
    int tmp;
    tmp=*left;
    *left=*right;
    *right=tmp;
}

int main()
{
    int x,y;
    printf("Before Swap enter 2 numbers\n");
    scanf("%i %i" , &x,&y);
    printf("x=%i\n",x);
    printf("y=%i\n",y);
    SwapA(&x,&y);   //pass by addresses
    printf("After Swap\n");
    printf("x=%i\n",x);
    printf("y=%i\n",y);
        return 0;

}




