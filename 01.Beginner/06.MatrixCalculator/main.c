#include <stdio.h>

#define SIZE 10

// Function Declarations
void inputMatrix(int matrix[SIZE][SIZE], int row, int col);
void printMatrix(int matrix[SIZE][SIZE], int row, int col);
void addMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE], int row, int col);
void subtractMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE], int row, int col);
void multiplyMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE], int r1, int c1, int c2);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE], int row, int col);

int main()
{
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], result[SIZE][SIZE];
    int r1, c1, r2, c2;
    int choice;

    do
    {
        printf("\n--- Matrix Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter rows and columns of matrices: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter elements of Matrix A:\n");
            inputMatrix(matrix1, r1, c1);

            printf("Enter elements of Matrix B:\n");
            inputMatrix(matrix2, r1, c1);

            addMatrices(matrix1, matrix2, result, r1, c1);
            printf("Result (A + B):\n");
            printMatrix(result, r1, c1);
            break;
        case 2:
            printf("Enter rows and columns of matrices: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter elements of Matrix A:\n");
            inputMatrix(matrix1, r1, c1);

            printf("Enter elements of Matrix B:\n");
            inputMatrix(matrix2, r1, c1);

            subtractMatrices(matrix1, matrix2, result, r1, c1);
            printf("Result (A - B):\n");
            printMatrix(result, r1, c1);
            break;
        case 3:
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter rows and columns of Matrix B: ");
            scanf("%d%d", &r2, &c2);

            if (c1 != r2)
            {
                printf("Multiplication not possible! Columns of A must equal rows if B.\n");
                break;
            }

            printf("Enter elements of Matrix A:\n");
            inputMatrix(matrix1, r1, c1);

            printf("Enter elements of Matrix B:\n");
            inputMatrix(matrix2, r2, c2);

            multiplyMatrices(matrix1, matrix2, result, r1, c1, c2);
            printf("Result (A * B):\n");
            printMatrix(result, r1, c2);
            break;
        case 4:
            printf("Enter rows and columns of Matrix: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter elements of Matrix:\n");
            inputMatrix(matrix1, r1, c1);
            transposeMatrix(matrix1, result, r1, c1);

            printf("Transpose:\n");
            printMatrix(result, r1, c1);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

// Function implementations
void inputMatrix(int matrix[SIZE][SIZE], int row, int col)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            scanf("%d", &matrix[i][j]);
};

void printMatrix(int matrix[SIZE][SIZE], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
};

void addMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE], int row, int col)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            result[i][j] = a[i][j] + b[i][j];
};

void subtractMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE], int row, int col)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            result[i][j] = a[i][j] - b[i][j];
};

void multiplyMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE], int r1, int c1, int c2)
{
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; ++k)
                result[i][j] += a[i][k] * b[k][j];
        }
};

void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE], int row, int col)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            result[j][i] = matrix[i][j];
};
