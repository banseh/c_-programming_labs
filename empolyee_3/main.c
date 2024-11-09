#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
void gotoxy( int column, int row )
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

void PrintEmployee(struct Employee param)
{
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

    printf("net_salary is =%f\n", (param.netsalary));


}

//one Employee Read and write
int main()
{

  struct Employee e[3]; //30*3B
    for (int i = 0; i < 3; i++)
    {
    printf("empolye %i ",i);

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

    gotoxy(15,5);
    scanf("%i",&e[i].ssd);
    _flushall();
    gotoxy(67,5);
    gets(e[i].name);
    gotoxy(15,10);
    scanf("%i",&e[i].age);
    gotoxy(70,10);
    scanf("%f",&e[i].salary);
    gotoxy(22,15);
    scanf("%f",&e[i].commision);
    gotoxy(72,15);
    scanf("%f",&e[i].deduction);
    system("cls");
     e[i].netsalary=  e[i].salary+e[i].commision-e[i].deduction;
    }
     for (int i = 0; i < 3; i++)
    {

           printf("empolye %i\n age is=%i\n salary is =%f\n  commision is %f\n  deductionis= %f\n  net_salary is =%f\n",i+1,e[i].name , e[i].age,e[i].salary,e[i].commision,e[i].deduction,e[i].netsalary);

           printf("-----------------------------------------\n");

    }

           printf("-----------------------------------------\n");





    return 0;

}

