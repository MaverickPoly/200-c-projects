#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get number of days in a month
int getDaysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
        return 31;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return 0;
    }
}

// Finds the day of the week
int getStartDay(int month, int year)
{
    if (month < 3)
    {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int day = (1 + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + 5 * j) % 7;

    // Zeller's returns 0 = Saturday, 1=Sunday etc
    // Convert to 0=Sunday 1=Monday etc
    return (day + 6) % 7;
}

// Print the calendar
void printCalendar(int month, int year)
{
    char *months[] = {
        "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int days = getDaysInMonth(month, year);
    int startDay = getStartDay(month, year);

    printf("\n  ---------- %s %d ----------\n", months[month], year);
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Initial Spacing
    for (int i = 0; i < startDay; i++)
    {
        printf("      ");
    }

    // Print days
    for (int day = 1; day <= days; day++)
    {
        printf("%5d", day);
        if ((startDay + day) % 7 == 0)
            printf("\n");
    }

    printf("\n");
}

int main()
{
    int month, year;

    printf("Enter month(1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || year < 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printCalendar(month, year);

    return 0;
}