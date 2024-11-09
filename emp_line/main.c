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

//////////////////////////////
struct Employee
{
    int ssd;
    char name[18];
    int age;
    float salary;
    float commision ;
    float deduction;
    float netsalary;

};

void PrintEmployee(struct Employee param)
{
    system("cls");
    gotoxy(50,5);
    printf("sdd=%i\n",param.ssd);
    gotoxy(50,6);

    printf("name=%s\n",param.name);  //puts(param.name)
        gotoxy(50,7);


    printf("age=%i\n",param.age);
        gotoxy(50,8);


    printf("salary=%f\n",param.salary);
        gotoxy(50,9);


    printf("commision=%f\n",param.commision);
        gotoxy(50,10);


    printf("deduction=%f\n",param.deduction);
        gotoxy(50,11);

    printf("net_salary is =%f\n", (param.salary+param.commision-param.deduction));


}
//////////////////////////////////////////////////

char* LineEditor(int _size, int col, int row, int startKey, int endKey)
{
    char *arr = malloc(_size * sizeof(char));
    int first = col, curr = col, last = col;
    char *pfirst, *plast, *pcurr;
    char ch;
    int flag = 0;

    gotoxy(col, row);
    /*for (int i = 0; i < _size; i++)
    {
        printf("_");
    }
*/
    pfirst = pcurr = plast = arr;
    gotoxy(curr, row);

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
                    char *temp = pcurr;
                    while (temp < plast)
                    {
                        *temp = *(temp + 1);
                        temp++;
                    }
                    plast--;
                    last--;

                    gotoxy(first, row);
                    printf("%-30s", arr);
                    gotoxy(curr, row);
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

                gotoxy(col, row);
                printf("%-30s", arr);
                gotoxy(curr, row);
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

    return arr;
}


//one Employee Read and write
int main()
{


    gotoxy(5,5);
    printf("Enter ssd:\n");
    gotoxy(55,5);
    printf("Enter Name:\n");
    _flushall();
    gotoxy(5,10);
    printf("Enter Age:\n");
    gotoxy(55,10);
    printf("Enter Salary:\n");
    gotoxy(5,15);
    printf("Enter commision:\n");
    gotoxy(55,15);
    printf("Enter deduction:\n");
///////////////////////////
    struct Employee e;
    //gotoxy(15,5);
      e.ssd = atoi(LineEditor(10, 15, 5, 48, 57)); // Convert string to int
          _flushall();

    strcpy(e.name, LineEditor(20, 67, 5, 65, 90)); // Correct function name
        _flushall();

    e.age = atoi(LineEditor(10, 15, 10, 48, 57)); // Convert string to int
        _flushall();

    e.salary = atof(LineEditor(10, 70, 10, 48, 57)); // Convert string to float
        _flushall();

    e.commision = atof(LineEditor(10, 22, 15, 48, 57)); // Convert string to float
        _flushall();

    e.deduction = atof(LineEditor(10, 72, 15, 48, 57)); // Convert string to float

    float netsalary=  e.salary+e.commision-e.deduction;
    PrintEmployee(e);
    return 0;

}

