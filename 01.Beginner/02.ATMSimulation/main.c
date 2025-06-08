#include <stdio.h>

// Account Struct
typedef struct
{
    char *username;
    int pin;
    float balance;
} Account;

// Function Declrations
void displayBalance(Account *);
void deposit(Account *);
void withdraw(Account *);
void checkPin(Account *);

// Main
int main()
{
    printf("Launching ATM...\n\n");

    Account *account = &(Account){.username = "Maverick", .pin = 1234, .balance = 1000.0};

    int pin;
    int attempts = 0;
    while (attempts < 3)
    {
        printf("Enter your pin: ");
        scanf("%d", &pin);

        if (pin == account->pin)
        {
            printf("Valid pin! Entering ATM...\n\n");
            break;
        }
        else
        {
            printf("Invalid pin! Try again...\n");
            attempts++;
        }
    }

    if (attempts == 3)
    {
        printf("Too many failed attempts! You are blocked!\n");
        return 0;
    }

    int option;

    do
    {
        printf("\n----- ATM Simulation -----\n");
        printf("1. Display Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Pin\n");
        printf("5. Exit\n");

        printf("Select option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            displayBalance(account);
            break;
        case 2:
            deposit(account);
            break;
        case 3:
            withdraw(account);
            break;
        case 4:
            checkPin(account);
            break;
        case 5:
            printf("\nThanks for using ATM! Goodbye...\n");
            break;
        default:
            printf("Invalid option! Please try again...\n");
            break;
        }
    } while (option != 5);

    return 0;
}

void displayBalance(Account *account)
{
    printf("\n==== Balance Info:\n");
    printf("Username: %s\n", account->username);
    printf("Balance: $%.2f\n", account->balance);
};

void deposit(Account *account)
{
    float amount;

    printf("\nEnter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0)
    {
        account->balance += amount;
        printf("Deposited $%.2f successfully!\n", amount);
    }
    else
    {
        printf("Deposit amount cannot be negative!\n");
    }
};

void withdraw(Account *account)
{
    float amount;

    printf("\nEnter withdraw amount: ");
    scanf("%f", &amount);

    if (amount > 0 && amount <= account->balance)
    {
        account->balance -= amount;
        printf("Withdrewn $%.2f successfully!\n", amount);
    }
    else if (amount > 0)
    {
        printf("Insufficient balance!\n");
    }
    else
    {
        printf("Withdraw amount cannot be negative!");
    }
};

void checkPin(Account *account)
{
    printf("\n==== Pin:");
    printf("%d\n", account->pin);
};
