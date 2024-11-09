#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
////////////////////////////////
#define EXTENDED -32
#define Enter 13
#define ESC 27
#define TAB 9
#define Up 72
#define Home 71
#define Down 80
#define End 79
#define delete 83
#define left 75
#define right 77
#define backspace 8


void gotoxy(int column, int row)
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

int main()
{
    char arr[30]= {0};
    int first,curr, last;
    char *pfirst, *pcurr, *plast;
    char ch ;
    first=curr= last=20;
    pfirst= pcurr=plast=arr;

    int flag=0;
    gotoxy(curr,10);
    for(int i=0 ; i<30; i++)
    {
        printf("_ ") ;
    }
    do
    {
        gotoxy(curr,10);
        ch=getch();
        switch (ch)
        {

        case EXTENDED:
            ch=getch();
            switch(ch)
            {
            case Home:
                pcurr=pfirst ;
                curr=first ;

                break;
            case End:
                pcurr=plast;
                curr=last;
                break;
            case left:
                if(pcurr>pfirst)
                {
                    pcurr-- ;
                    curr-- ;
                }
                break;

            case right:
                if(pcurr<plast)
                {
                    pcurr++ ;
                    curr++ ;
                }
                break;

            case delete:
    if (pcurr < plast) {
        char *temp1 = pcurr;

        while (temp1 < plast) {
            *temp1 = *(temp1 + 1);
            temp1++;
        }

        *(plast - 1) = '\0';
        plast--;
        last--;

        gotoxy(curr, 10);
                system("cls") ;
                gotoxy(first, 10);
        printf("%-30s", arr);
    }
    break;


            }
            break;
///////////////////////////////////////////////////new//////////////////////////////////
        case backspace:
            if (pcurr > pfirst)
            {
                pcurr--;
                curr--;
                char *temp = pcurr;
                while (temp < plast)
                {
                    *temp = *(temp + 1);
                    temp++;
                }
                *(plast - 1) = '\0';
                plast--;
                last--;
                gotoxy(curr, 10);
                system("cls") ;
                gotoxy(first, 10);

                printf("%-30s", arr);
            }
            break;
/////////////////////////////////////////////////////////
        case Enter:
        case ESC :
            *plast='\0' ;
            flag=1;
            system("cls") ;

            for(int i=0 ; i<30; i++)
            {
                printf("%c", arr[i]); // Print modified array with padding;
            }
            break;

        default:
            if(isprint(ch))
            {
                if(pcurr <pfirst+29)
                {
                    *pcurr=ch;
                    printf("%c", ch);
                    pcurr++;
                    curr++;
                    plast++;
                    last++;
                }
            }
            else
            {
                *pcurr=ch;
                *pcurr++;
                curr++;
            }
            break;
        }
    }
    while(flag==0);


    return 0;
}
