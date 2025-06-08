#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 100

typedef struct
{
    int rollNumber;
    char name[NAME_LEN];
    float marks;
} Student;

Student students[MAX_STUDENTS];
size_t studentsSize = 0;

// Function declarations
void displayStudents();
void addStudent();
void searchStudent();
void deleteStudent();
void printStudent(Student student);

int main()
{
    int option;

    do
    {
        printf("\n====== Student Record System ======\n");
        printf("1. Display Students\n");
        printf("2. Add Student\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // Clear the newline
        printf("\n");

        switch (option)
        {
        case 1:
            displayStudents();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            printf("Thanks for trying app! Goodbye...\n");
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    } while (option != 5);

    return 0;
}

void displayStudents()
{
    if (studentsSize == 0)
    {
        printf("There are no students for now!\n");
        return;
    }

    for (int i = 0; i < studentsSize; i++)
    {
        Student student = students[i];
        printStudent(student);
    }
};

void addStudent()
{
    if (studentsSize >= MAX_STUDENTS)
    {
        printf("Too many students right now!\n");
        return;
    }

    Student newStudent;

    printf("Enter student roll number: ");
    scanf("%d", &newStudent.rollNumber);
    getchar(); // Clear newline character

    printf("Enter student name: ");
    fgets(newStudent.name, NAME_LEN, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    printf("Enter student marks: ");
    scanf("%f", &newStudent.marks);

    students[studentsSize++] = newStudent;
    printf("Added new user successfully!\n");
};

void searchStudent()
{
    int rollNumber;
    int found = 0;
    printf("Enter a student roll number to search: ");
    scanf("%d", &rollNumber);

    printf("Students found:\n");
    for (int i = 0; i < studentsSize; i++)
    {
        Student student = students[i];

        if (student.rollNumber == rollNumber)
        {
            printStudent(student);
            found = 1;
        }
    }

    if (!found)
        printf("No students found with roll number %d\n", rollNumber);
};

void deleteStudent()
{
    int rollNumber;

    printf("Enter a student roll number to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentsSize; i++)
    {
        Student student = students[i];
        if (student.rollNumber == rollNumber)
        {
            for (int j = i; j < studentsSize - 1; j++)
                students[j] = students[j + 1];

            studentsSize--;
            printf("Student with roll number %d deleted successfully!\n", rollNumber);
            return;
        }
    }

    printf("No student found with roll number %d\n", rollNumber);
};

void printStudent(Student student)
{
    printf("Roll number: %d | Name: %s | Marks: %.2f\n",
           student.rollNumber, student.name, student.marks);
};
