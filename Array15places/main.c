#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10];
    for(int i=0 ; i<10 ; i++){
        printf("please enter num") ;
        scanf( "%i" , &arr[i] ) ;
    }
    int max= arr[0] ;
    for( int i=0 ; i<10 ; i++){
        if (arr[i]> max)
            max= arr[i];
    }
    printf(" max_value is :%i\n" , max);

     int min= arr[0] ;
    for( int i=0 ; i<10 ; i++){
        if (arr[i]< min)
            min= arr[i];
    }
    printf(" min_value is :%i" , min);
    return 0;
}


