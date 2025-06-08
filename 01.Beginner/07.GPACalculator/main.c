#include <stdio.h>

// Function to convert percentage to GP (grade point)
float getGradePoint(int marks)
{
    if (marks >= 90)
        return 4.0;
    if (marks >= 80)
        return 3.5;
    if (marks >= 70)
        return 3.0;
    if (marks >= 60)
        return 2.5;
    if (marks >= 50)
        return 2.0;
    return 0.0;
}

int main()
{
    printf("==== GPA Calculator ====\n\n");

    int numberOfSubjects, marks, credit;
    float gradePoint, totalPoints = 0, totalCredits = 0;

    printf("Enter number of subjects: ");
    scanf("%d", &numberOfSubjects);

    for (int i = 1; i <= numberOfSubjects; i++)
    {
        printf("\nSubject %d\n", i);

        printf("Enter marks (0-100): ");
        scanf("%d", &marks);

        printf("Enter credit hours: ");
        scanf("%d", &credit);

        gradePoint = getGradePoint(marks);

        totalPoints += gradePoint * credit;
        totalCredits += credit;
    }

    if (totalCredits == 0)
    {
        printf("Invalid total credits!\n");
    }
    else
    {
        float gpa = totalPoints / totalCredits;
        printf("Your GPA is %.2f\n", gpa);
    }
}
