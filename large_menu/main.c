///Highlighted menu
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#define EXTENDED -32
#define Enter 13
#define ESC 27
#define TAB 9
#define Up 72
#define Home 71
#define Down 80
#define End 79

void gotoxy( int column, int row )
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
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
int main()
{
    char menu[4][10]={"File","New","Display","Exit"};
    int cursor=0;
    int flag=555;
    char ch;
    do
    {
        //clear screen
        system("cls");
        for (int i = 0; i < 4; i++)
        {
            if(i==cursor){textattr(4);} //R
            else{textattr(7);} //W
            gotoxy(15,15+i);
            _cprintf("%s",menu[i]);
        }
        //
        ch=getch();  //Enter
        switch(ch)
        {
            case EXTENDED:
            ch=getch();
            switch(ch)
            {
                case Up:
                cursor--;
                if(cursor<0){cursor=3;}
                break;
                case Down:
                cursor++;
                if(cursor>3){cursor=0;}
                break;
                case Home:
                cursor=0;
                break;
                case End:
                cursor=3;
                break;
            }
            break;
            case Enter:
            switch(cursor)
            {
                case 0:
                system("cls");
                printf("File Page");
                //wait to see
                getch();
                break;
                case 1:
                system("cls");
                printf("New Page");
                //wait to see
                getch();
                break;
                case 2:
                system("cls");
                printf("Display Page");
                //wait to see
                getch();
                break;
                case 3:
                flag=0;
                break;
            }
            break;
            case ESC:
            flag=0;
            break;
            case TAB:
            cursor++;
            if(cursor>3){cursor=0;}
            break;
        }

    }
    while(flag==555);


    return 0;
}

