#include <stdio.h>
#include <stdlib.h>

int main()
{
char  fn[10]  , ln[10]   ,   fullname[21];
printf("please enter first name :") ;
gets(fn);
printf("please enter last name:") ;
gets(ln);

    strcpy(fullname,fn);
    strcat(fullname," ");
    strcat(fullname,ln);
    printf("the full name is :") ;
    puts(fullname) ;

    return 0;
}
