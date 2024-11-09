#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

#define EXTENDED -32
#define Enter 13
#define ESC 27
#define TAB 9
#define Up 72
#define Home 71
#define Down 80
#define End 79
#define Left 75
#define Right 77
#define Delete 83
#define Backspace 8

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

char* LineEditor(int _size, int col, int row, int startKey, int endKey)
{
    char *arr = malloc(_size * sizeof(char));
    int first = col, curr = col, last = col;
    char *pfirst, *plast, *pcurr;
    char ch;
    int flag = 0;

    // Draw initial underscores for the line editor
    gotoxy(col, row);
    for (int i = 0; i < _size; i++)
    {
        printf("_");
    }

    // Initialize pointers
    pfirst = pcurr = plast = arr;
    gotoxy(curr, row);  // Set cursor to the starting position

    do
    {
        gotoxy(curr, row);
        ch = getch();

        switch (ch)
        {
        case EXTENDED:
            ch = getch();
            switch (ch)
            {
            case Left:
                if (pcurr > pfirst)
                {
                    pcurr--;
                    curr--;
                }
                break;

            case Right:
                if (pcurr < plast)
                {
                    pcurr++;
                    curr++;
                }
                break;

            case Home:
                pcurr = pfirst;
                curr = first;
                break;

            case End:
                pcurr = plast;
                curr = last;
                break;
            case Delete:
                if (pcurr < plast)
                {
                    char *temp1 = pcurr;

                    while (temp1 < plast)
                    {
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

        case Enter:
        case ESC:
            *pcurr = '\0';
            flag = 1;
            break;

        case Backspace:
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

        default:
            if (isprint(ch) && (int)ch >= startKey && (int)ch <= endKey)
            {
                if (pcurr < pfirst + _size - 1)
                {
                    *pcurr = ch;
                    printf("%c", ch);
                    pcurr++;
                    curr++;
                    plast++;
                    last++;
                }
            }
            break;
        }
    }
    while (flag == 0);

    gotoxy(0, row + 1);
    printf("Input: %s\n", arr);

    return arr;
}

int main()
{
    char *arr = LineEditor(30, 20, 10, 97, 122);
    if (arr != NULL)
    {
        free(arr);
    }
    return 0;
}
