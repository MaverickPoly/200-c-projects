#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];

// Function Declarations
void initializeBoard();
void printBoard();
void makeMove(char);
int checkWin();
int isDraw();

int main()
{
    printf("====== Welcome to Tic Tac Toe Game! ======\n");

    int running = 1;
    char again;

    while (running)
    {
        initializeBoard();
        char player = 'X';
        printf("\n---- Game Started\n\n");

        while (1)
        {
            printBoard();
            makeMove(player);

            if (checkWin())
            {
                printBoard();
                printf("Player %c won!\n", player);
                break;
            }

            if (isDraw())
            {
                printBoard();
                printf("Draw!\n");
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        printf("\nDo you want to play again(y/n)? ");
        scanf(" %c", &again);
        if (again == 'N' || again == 'n')
            running = 0;
    }

    printf("\nThanks for playing! Goodbye...\n");
    return 0;
}

// Function implementations
void initializeBoard()
{
    char count = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = count++;
};

void printBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
};

void makeMove(char currentPlayer)
{
    int move;
    while (1)
    {
        printf("Player %c move: ", currentPlayer);
        scanf("%d", &move);

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("Invalid move!\n");
            continue;
        }

        board[row][col] = currentPlayer;
        return;
    }
};

int checkWin()
{
    // Horizontal
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    // Vertical
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;

    return 0;
};

int isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char el = board[i][j];
            if (el != 'X' && el != 'O')
                return 0;
        }
    }
    return 1; // It is draw
};
