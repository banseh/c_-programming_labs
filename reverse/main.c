#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[30]={0};  //30B //|#|#|#|...
    int i=0;
    char c;
    printf("Enter Name\n");
    while((c=getche())!=13)
    {
         name[i] =c;
        i++;
    }
    name[i]='\0';

for(int j=i-1 ; j>=0 ; j--)
{
    printf("%c",name[j]);
}
    return 0;
}
