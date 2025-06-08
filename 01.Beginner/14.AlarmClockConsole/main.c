#include <stdio.h>
#include <windows.h>

int main()
{
    int timeout;
    printf("Enter timeout (in seconds): ");
    scanf("%d", &timeout);

    printf("\nAlarm has started...\n\n");

    while (timeout > 0)
    {
        printf("%d\n", timeout);
        Sleep(1000);
        timeout--;
    }

    printf("\nAlarm is ringing!\n");
    Beep(700, 2000); // Beep sound indicating the end of alarm
    return 0;
}