#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50
#define MAX_AUTHOR 40

typedef struct
{
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
} Book;

Book library[MAX_BOOKS];
size_t size = 0;

// Function declarations
void displayBooks();
void printBook(Book);
void addBook();
void searchBook();
void deleteBook();

int main()
{
    printf("===== Welcome to library management system!!\n\n");

    int choice;

    do
    {
        printf("\n====== Library management system ======\n");
        printf("1. Display Books\n");
        printf("2. Add Book\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Quit\n");

        printf("Choice: ");
        scanf("%d", &choice);
        puts("\n");

        switch (choice)
        {
        case 1:
            displayBooks();
            break;
        case 2:
            addBook();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

// Function implementations
void displayBooks()
{
    if (size == 0)
    {
        printf("Library is empty!\n");
        return;
    }

    printf("---- Library ----\n");
    for (int i = 0; i < size; i++)
        printBook(library[i]);
};

void printBook(Book book)
{
    printf("Id: %d | Title: %s | Author: %s | Year: %d\n",
           book.id, book.title, book.author, book.year);
};

void addBook()
{
    if (size >= MAX_BOOKS)
    {
        printf("Library is FULL!\n");
        return;
    }

    Book newBook;

    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    getchar();

    printf("Enter title: ");
    fgets(newBook.title, MAX_TITLE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

    printf("Enter author: ");
    fgets(newBook.author, MAX_AUTHOR, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    printf("Enter year: ");
    scanf("%d", &newBook.year);

    library[size++] = newBook;
    printf("Book added successfully!\n");
};

void searchBook()
{
    int id;
    printf("Enter book id to search: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++)
    {
        Book book = library[i];
        if (book.id == id)
        {
            printf("Book found:\n");
            printBook(book);
            return;
        }
    }

    printf("Book with id %d not found!\n", id);
};

void deleteBook()
{
    int id;
    printf("Enter book id to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++)
    {
        Book book = library[i];
        if (book.id == id)
        {
            for (int j = i; j < size - 1; j++)
                library[j] = library[j + 1];
            size--;
            printf("Book deleted successfully!\n");
            return;
        }
    }

    printf("Book with id %d not found!\n", id);
};
