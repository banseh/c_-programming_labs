#include <stdio.h>
#include <stdlib.h>

int main()
{
    int current_day =28 ;
    int current_month =10 ;
    int current_year =2024 ;

    int  day, month, year;

    do
    {
        printf("please enter the year:") ;
        scanf( "%i",&year );
    }
    while(year <1973 ||year >2024   ) ;

    do
    {
        printf("please enter the month:") ;
        scanf( "%i",&month );
    }
    while (month <1 || month>12) ;

    int max_days ;
    if ( month == 1 ||  month == 3 ||month == 5 || month == 7|| month == 8  ||month == 10  || month == 12)
    {
        max_days=31;
    }

    else     if ( month == 4 ||  month == 6 ||month == 9 || month == 11)

    {
        max_days=30;

    }

    else if (month==2)
    {
        if (year%4==0 &&  year%100!=0  || year%400==0)
            max_days=29 ;
        else
            max_days=28 ;
    }
    do
    {
        printf("please enter the day:") ;
        scanf( "%i",&day );
    }
    while(day<1 || day>max_days) ;

// Determine max days for the current month
    int current_max_days;
    if (current_month == 1 || current_month == 3 || current_month == 5 || current_month == 7 || current_month == 8 || current_month == 10 || current_month == 12) {
        current_max_days = 31;
    } else if (current_month == 4 || current_month == 6 || current_month == 9 || current_month == 11) {
        current_max_days = 30;
    } else if (current_month == 2) {
        if ((current_year % 4 == 0 && current_year % 100 != 0) || current_year % 400 == 0)
            current_max_days = 29;
        else
            current_max_days = 28;
    }

    if (current_day< day)
    {
        current_day+= current_max_days;
        current_month--;
    }
    if(current_month< month)
    {
        current_month+=12 ;
                       current_year-- ;
    }
    printf(" you are:%i", current_year-year);
    printf("y ");

    printf( "%i", current_month-month);
    printf("m ");

    printf(   "%i", current_day-day);
    printf("d ");


    return 0;
}
