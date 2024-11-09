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

struct Employee
{
    int ssd;
    char name[18];
    int age;
    float salary;
    float commision;
    float deduction;
    float netsalary;
};

void PrintEmployee(struct Employee param)
{
    system("cls");
    gotoxy(50, 5);
    printf("ssd=%i\n", param.ssd);

    gotoxy(50, 6);
    printf("name=%s\n", param.name);

    gotoxy(50, 7);
    printf("age=%i\n", param.age);

    gotoxy(50, 8);
    printf("salary=%f\n", param.salary);

    gotoxy(50, 9);
    printf("commision=%f\n", param.commision);

    gotoxy(50, 10);
    printf("deduction=%f\n", param.deduction);

    gotoxy(50, 11);
    printf("net_salary=%f\n", param.netsalary);
    _flushall();
}

int main()
{
    system("cls");
    struct Employee emp[10];
    char menu[8][20] = {"New", "DisplayAll","Display by name", "Display by ssn","Delete by id", "Delete by name", "Delete ALL", "EXIT"};
    int cursor = 0;
    int flag = 555;
    char ch;
    int used[10] = {0};
    int employeeCount = 0;

    do
    {
        // Clear screen
        system("cls");
        for (int i = 0; i < 8; i++)
        {
            if (i == cursor)
            {
                textattr(3);   // Highlighted
            }
            else
            {
                textattr(7);   // Normal
            }
            gotoxy(15, 15 + i);
            printf("%s", menu[i]);

        }

        ch = getch();  // Get key press
        switch (ch)
        {

        case EXTENDED:
            ch = getch();
            /////////////////////////////////////////////
            switch (ch)
            {
            case Up:
                cursor--;
                if (cursor < 0)
                {
                    cursor = 7;
                }
                break;
            case Down:
                cursor++;
                if (cursor > 7)
                {
                    cursor = 0;
                }
                break;
            case Home:
                cursor = 0;
                break;
            case End:
                cursor = 7;
                break;
            }
            break;
        ///////////////////////////////////////////////////
        case Enter:
            switch (cursor)
            {
            case 0: // Add New Employee
                system("cls");
                int index;
                char accept;
                do
                {
                    do
                    {
                        system("cls");
                        printf("Please enter index from 1 to 10: ");
                        if (scanf("%i", &index) != 1) // If scanf fails to read an integer
                        {
                            printf("Invalid input! Please enter a number.\n");
                            while (getchar() != '\n'); // Clear the buffer
                            index = -1; // Set index to an invalid number to trigger the loop again
                        }
                    }
                    while (index < 1 || index > 10);
                    index--;

                    if (used[index])
                    {
                        printf("Index %d is already used. Override? (y/n): ", index + 1);
                        char choice;
                        scanf(" %c", &choice);
                        if (choice != 'y') continue;
                    }

                    used[index] = 1;
                    struct Employee e;

                    gotoxy(5, 5);
                    printf("Enter ssd:\n");
                    gotoxy(55, 5);
                    printf("Enter Name:\n");
                    _flushall();
                    gotoxy(5, 10);
                    printf("Enter Age:\n");
                    gotoxy(55, 10);
                    printf("Enter Salary:\n");
                    gotoxy(5, 15);
                    printf("Enter commision:\n");
                    gotoxy(55, 15);
                    printf("Enter deduction:\n");
                    _flushall();

                    gotoxy(15, 5);
                    scanf("%i", &e.ssd);
                    _flushall();
                    gotoxy(67, 5);
                    fgets(e.name, sizeof(e.name), stdin);
                    e.name[strcspn(e.name, "\n")] = '\0'; // Remove newline
                    gotoxy(15, 10);
                    scanf("%i", &e.age);
                    _flushall();
                    gotoxy(70, 10);
                    scanf("%f", &e.salary);
                    _flushall();
                    gotoxy(22, 15);
                    scanf("%f", &e.commision);
                    _flushall();
                    gotoxy(72, 15);
                    scanf("%f", &e.deduction);
                    _flushall();

                    e.netsalary = e.salary + e.commision - e.deduction;
                    emp[index] = e;
                    employeeCount++;

                    printf("If you want to add another employee, please enter 'y': ");
                    scanf(" %c", &accept);
                    _flushall();
                }
                while (accept == 'y');

                printf("Thanks.....you are finished\n");
                getch(); // Wait to see
                cursor++; // Move to the next menu item
                break;

            case 1: // Display All Employees
                system("cls");
                printf("Display all employees:\n");
                printf("------------------------------\n");
                for (int i = 0; i < 10; i++)
                {
                    if (used[i])
                    {
                        printf("Employee %i\n", i + 1);
                        printf("SSD: %d\n", emp[i].ssd);
                        printf("Name: %s\n", emp[i].name);
                        printf("Age: %d\n", emp[i].age);
                        printf("Salary: %.2f\n", emp[i].salary);
                        printf("Commission: %.2f\n", emp[i].commision);
                        printf("Deduction: %.2f\n", emp[i].deduction);
                        printf("Net Salary: %.2f\n", emp[i].netsalary);
                        printf("-----------------------------------------\n");
                    }
                }
                getch(); // Wait to see
                cursor++; // Move to the next menu item
                break;
////////////////////////////////////////////////////////////////////////////////////////////
            case 2: // Display by name
                system("cls");
                //printf("Display by name\n");
                char name[30] = {0}; //30B //|#|#|#|...
                printf("please enter name that you want to display data about name\n");
                int i = 0;
                char c;
                printf("Enter Name:");
                while ((c = getche()) != 13) // Wait for Enter key
                {
                    name[i] = c;
                    i++;
                }
                name[i] = '\0';
                int flag = 0;
                for (int i = 0; i < 10; i++)
                {
                    int result = strcmp(name, emp[i].name);
                    if (result == 0)
                    {
                        printf("Employee %i\n", i + 1);
                        printf("Name: %s\n", emp[i].name);
                        printf("Age: %i\n", emp[i].age);
                        printf("Salary: %f\n", emp[i].salary);
                        printf("Commission: %f\n", emp[i].commision);
                        printf("Deduction: %f\n", emp[i].deduction);
                        printf("Net Salary: %f\n", emp[i].salary + emp[i].commision - emp[i].deduction);
                        printf("-----------------------------------------\n");
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("We don't have a customer with this name");
                getch(); // Wait to see
                cursor++; // Move to the next menu item
                break;
            /////////////////////////////////////3/////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////
            case 3: // Display by ssd
                system("cls");
                printf(" please enter SSD that you want to display data about  SSD:");
                int s ; //  //|#|#|#|...
                _flushall();
                scanf("%i", &s);
                //int i = 0;
                int flag2 = 0;
                for (int i = 0; i < 10; i++)
                {
                    if( s ==emp[i].ssd)
                    {


                        printf("Employee %i\n", i + 1);
                        printf("Name: %s\n", emp[i].name);
                        printf("Age: %i\n", emp[i].age);
                        printf("Salary: %f\n", emp[i].salary);
                        printf("Commission: %f\n", emp[i].commision);
                        printf("Deduction: %f\n", emp[i].deduction);
                        printf("Net Salary: %f\n", emp[i].salary + emp[i].commision - emp[i].deduction);
                        printf("-----------------------------------------\n");
                        flag2 = 1;
                    }
                }
                if (flag2 == 0)
                    printf("We don't have a customer with this SSD");
                getch(); // Wait to see
                cursor++; // Move to the next menu item
                break;
            ///////////////////////case4444/////////////////////
            case 4:
                system("cls");
                printf(" please enter SSD that you want to delete data about  SSD\n");
                int ss ; //  //|#|#|#|...
                _flushall();
                scanf("%i", &ss);
                //int i = 0;
                int flag3 = 0;
                for (int i = 0; i < 10; i++)
                {
                    if( ss ==emp[i].ssd)
                    {

                        printf("Employee with SSD %i found. Deleting data...\n", ss);
// Clear the data for the employee at index `i`
                        emp[i].ssd = 0;
                        strcpy(emp[i].name, "");
                        emp[i].age = 0;
                        emp[i].salary = 0.0;
                        emp[i].commision = 0.0;
                        emp[i].deduction = 0.0;
                        emp[i].netsalary = 0.0;
                        employeeCount--;
                        printf("Employee data deleted successfully.\n");

                        printf("-----------------------------------------\n");
                                                used[i]=0;

                        flag3 = 1;
                    }
                }
                if (flag3 == 0)
                    printf("We don't have a customer with this SSD");
                getch(); // Wait to see
                cursor++; // Move to the next menu item
                break;
            ///////////////////////////5//////////////////////////////////////
            case 5:
                system("cls");
                //printf("Display by name\n");
                char del[30] = {0}; //30B //|#|#|#|...
                printf("please enter name that you want to delete data about \n");
                int z = 0;
                char cc;
                printf("Enter Name:");
                while ((cc = getche()) != 13) // Wait for Enter key
                {
                    del[z] = cc;
                    z++;
                }
                del[z] = '\0';
                int flag4 = 0;
                for (int i = 0; i < 10; i++)
                {
                    int result = strcmp(del, emp[i].name);
                    if (result == 0)
                    {
                        printf("Employee with SSD %i found. Deleting data...\n", ss);
// Clear the data for the employee at index `i`
                        emp[i].ssd = 0;
                        strcpy(emp[i].name, "");
                        emp[i].age = 0;
                        emp[i].salary = 0.0;
                        emp[i].commision = 0.0;
                        emp[i].deduction = 0.0;
                        emp[i].netsalary = 0.0;
                        employeeCount--;
                        printf("Employee data deleted successfully.\n");

                        printf("-----------------------------------------\n");
                        used[i]=0;
                        flag4 = 1;
                    }
                }
                if (flag4 == 0)
                    printf("We don't have a customer with this name");
                getch(); // Wait to see
                cursor++; // Move to the next menu item
                break;
            case 6:
                ///////////////////////////////////6/////////////////////////////////////
                system("cls");
                printf("Delete all employees:\n");
                printf("------------------------------\n");
                for (int i = 0; i < 10; i++)
                {
                    if (used[i])
                    {
// Clear the data for the employee at index `i`
                        emp[i].ssd = 0;
                        strcpy(emp[i].name, "");
                        emp[i].age = 0;
                        emp[i].salary = 0.0;
                        emp[i].commision = 0.0;
                        emp[i].deduction = 0.0;
                        emp[i].netsalary = 0.0;
                        employeeCount=0;
                        printf(" Employees%i data deleted successfully.\n",&i);
                        printf("-----------------------------------------\n");
                        used[i]=0;

                    }
                }
                getch(); // Wait to see
                cursor++; // Move to the next menu item
                break;
            case 7:
                system("cls");
                printf("Thank you !\n");
                flag = 0;
                getch();
                break;
            }

            ////////////////////////////////////////////////////////////////////////

            //////////////////////////
            if (cursor >= 7) // Assuming 8 menu items
            {
                cursor = 0; // Reset to the first menu item
            }
            break;

        case ESC:
            flag = 0;
            break;

        case TAB:
            cursor = (cursor + 1) % 8; // Cycle through menu options
            break;
        }
    }
    while (flag == 555);

    return 0;
}
