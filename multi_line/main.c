#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
//////////////////////////////////////////////////
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
  int num_rows;
    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    getchar();

        char **arr = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        arr[i] = (char *)malloc(30 * sizeof(char));
        memset(arr[i], 0, 30);
    }

    int first = 20, curr = 20, last = 20;
    char *pfirst, *pcurr, *plast;
    int current_row = 0;
    char ch;
    int flag = 0;

    pfirst = pcurr = plast = arr[current_row];

    for (int i = 0; i < num_rows; i++)
    {
        gotoxy(first, 10 + i);

    }

    do
    {
        gotoxy(curr, 10 + current_row);
        ch = getch();
        switch (ch)
        {
        case EXTENDED:
            ch = getch();
            switch (ch)
            {
            case Up:
                if (current_row > 0) {
                    current_row--;
                    pfirst = arr[current_row];
                    pcurr = arr[current_row] + (curr - first);
                    plast = arr[current_row] + strlen(arr[current_row]);
                }
                break;
            case Down:
                if (current_row < num_rows - 1) {
                    current_row++;
                    pfirst = arr[current_row];
                    pcurr = arr[current_row] + (curr - first);
                    plast = arr[current_row] + strlen(arr[current_row]);
                }
                break;
            case Home:
                pcurr = pfirst;
                curr = first;
                break;
            case End:
                pcurr = plast;
                curr = first + (plast - pfirst);
                break;
            case left:
                if (pcurr > pfirst) {
                    pcurr--;
                    curr--;
                }
                break;
            case right:
                if (pcurr < plast) {
                    pcurr++;
                    curr++;
                }
                break;
            case delete:
                if (pcurr < plast) {
                    char *temp = pcurr;
                    while (temp < plast) {
                        *temp = *(temp + 1);
                        temp++;
                    }
                    *(plast - 1) = '\0';
                    plast--;

                    //system("cls");
                    for (int i = 0; i < num_rows; i++) {
                        gotoxy(first, 10 + i);
                        printf("%-30s", arr[i]);
                    }
                }
                break;
            }
            break;
        case backspace:
            if (pcurr > pfirst) {
                pcurr--;
                curr--;
                char *temp = pcurr;
                while (temp < plast) {
                    *temp = *(temp + 1);
                    temp++;
                }
                *(plast - 1) = '\0';
                plast--;

               // system("cls");
                for (int i = 0; i < num_rows; i++) {
                    gotoxy(first, 10 + i);
                    printf("%-30s", arr[i]);
                }
            }
            break;
        case Enter:
            if (current_row < num_rows - 1) {
                current_row++;
                pfirst = arr[current_row];
                pcurr = plast = pfirst;
                curr = first;
            } else {
                flag = 1;
            }
            break;
        case ESC:
            flag = 1;
            break;
        default:
            if (isprint(ch)) {
                if (pcurr < pfirst + 29) {
                    *pcurr = ch;
                    printf("%c", ch);
                    pcurr++;
                    curr++;
                    plast++;
                }
            }
            break;
        }
    } while (flag == 0);

    system("cls");
    printf("You entered:\n");
    for (int i = 0; i < num_rows; i++) {
        printf("Row %d: %s\n", i + 1, arr[i]);
    }

    for (int i = 0; i < num_rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

