#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee
{
    int id;
    char name[50];
    float baseSalary;
    float bonus;
    float deduction;
    float netSalary;
};

float calculateNetSalary(float base, float bonus, float deduction)
{
    return base + bonus - deduction;
}

void addEmployee(struct Employee employees[], int *count)
{
    if (*count >= MAX_EMPLOYEES)
    {
        printf("Employee limit reached!\n");
        return;
    }

    struct Employee e;

    printf("Enter employee ID: ");
    scanf("%d", &e.id);
    printf("Enter employee Name: ");
    scanf(" %[^\n]", e.name);
    printf("Enter Base Salary: ");
    scanf("%f", &e.baseSalary);
    printf("Enter Bonus: ");
    scanf("%f", &e.bonus);
    printf("Enter Deduction: ");
    scanf("%f", &e.deduction);

    e.netSalary = calculateNetSalary(e.baseSalary, e.bonus, e.deduction);

    employees[*count] = e;
    (*count)++;

    printf("Employee added successfully!\n");
}

void displayEmployees(struct Employee employees[], int count)
{
    printf("\n--- Employees Salary Report ---\n");
    for (int i = 0; i < count; i++)
    {
        struct Employee employee = employees[i];
        printf("\nEmployee #%d\n", i + 1);
        printf("ID: %d\n", employee.id);
        printf("Name: %s\n", employee.name);
        printf("Base Salary: %.2f\n", employee.baseSalary);
        printf("Bonus: %.2f\n", employee.bonus);
        printf("Deduction: %.2f\n", employee.deduction);
        printf("Net Salary: %.2f\n", employee.netSalary);
    }
}

int main()
{
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do
    {
        printf("\n----- Employee Salary Manager -----\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee(employees, &count);
            break;
        case 2:
            displayEmployees(employees, count);
            break;
        case 3:
            printf("\nExiting...\n");
            break;
        default:
            printf("Invalid choice...\n");
        }
    } while (choice != 3);

    return 0;
}