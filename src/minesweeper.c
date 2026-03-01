#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setInput(int *ptrK, int *ptrM, int *ptrN);
int** setBoard(int **board, int M, int N);
int** placeBombs(int **board, int M, int N, int K);
int** findNeighborBombs(int **board, int M, int N);
void printBoard2Stdout(int **board, int M, int N);
void printBoard2File(FILE *f, int **board, int M, int N);
void freeBoard(int **board, int M);

int main(int argc, char **argv)
{
    int K, M, N;
    int **board;
    FILE *f;
    char filename[100];

    srand(time(NULL));

    setInput(&K, &M, &N);
    board = setBoard(board, M, N);
    if (!board)
        exit(1);
    board = placeBombs(board, M, N, K);
    board = findNeighborBombs(board, M, N);
    printBoard2Stdout(board, M, N);

    snprintf(filename, sizeof(filename),
            "boards/board%dx%dx%d.txt", M, N, K);

    f = fopen(filename, "w");
    if (!f)
    {
        printf("Error opening file.\n");
        freeBoard(board, M);
        exit(1);
    }

    printBoard2File(f, board, M, N);
    
    fclose(f);
    freeBoard(board, M);

    return 0;
}

void setInput(int *ptrK, int *ptrM, int *ptrN)
{
    printf("====== INPUT ======\n");
    printf("Enter dimensions of minesweeper board\n");
    printf("Rows(M)    : ");
    scanf("%d", ptrM);
    printf("Columns(N) : ");
    scanf("%d", ptrN);
    printf("Enter number of bombs\n");
    printf("Bombs(K)   : ");
    scanf("%d", ptrK);
}

int** setBoard(int **board, int M, int N)
{
    int i, j;
    
    board = (int **) calloc(M, sizeof(int *));
    if (!board)
    {
        printf("Error in allocating heap memory for M dimension.\n");
        return NULL;
    }
    
    for (i = 0; i < M; i++)
    {
        board[i] = (int *) calloc (N, sizeof(int));
        if (!board[i])
        {
            printf("Error in allocating heap memory for N dimension.\n");
            for (j = 0; j < i; j++)
                free(board[j]);

            free(board);

            return NULL;
        }
    }

    return board;
}

int** placeBombs(int **board, int M, int N, int K)
{
    int placed = 0;
    int row, col;

    while (placed < K)
    {
        row = rand() % M;
        col = rand() % N;

        if (board[row][col] != -1) // not already a bomb
        {
            board[row][col] = -1;
            placed++;
        }
    }

    return board;
}

int** findNeighborBombs(int **board, int M, int N)
{
    int i, j, r, c;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j] == -1) // found bomb
            {
                for (r = i - 1; r <= i + 1; r++)
                {
                    for (c = j - 1; c <= j + 1; c++)
                    {
                        // Check boundaries
                        if (r >= 0 && r < M &&
                            c >= 0 && c < N)
                        {
                            // Skip the bomb cell itself
                            if (!(r == i && c == j))
                            {
                                // Only increment if not a bomb
                                if (board[r][c] != -1)
                                    board[r][c]++;
                            }
                        }
                    }
                }
            }
        }
    }

    return board;
}

void printBoard2Stdout(int **board, int M, int N)
{
    int i, j;

    printf("\n========== MINESWEEPER BOARD ==========\n\n");

    /* Print column numbers */
    printf("    ");
    for (j = 0; j < N; j++)
        printf("%2d ", j);
    printf("\n");

    /* Print top border */
    printf("    ");
    for (j = 0; j < N; j++)
        printf("---");
    printf("-\n");

    /* Print rows */
    for (i = 0; i < M; i++)
    {
        printf("%2d | ", i);  // row number

        for (j = 0; j < N; j++)
        {
            if (board[i][j] == -1)
                printf(" * ");
            else
                printf(" %d ", board[i][j]);
        }

        printf("|\n");
    }

    /* Bottom border */
    printf("    ");
    for (j = 0; j < N; j++)
        printf("---");
    printf("-\n");
}

void printBoard2File(FILE *f, int **board, int M, int N)
{
    int i, j;

    fprintf(f, "\n========== MINESWEEPER BOARD ==========\n\n");

    /* Column numbers */
    fprintf(f, "    ");
    for (j = 0; j < N; j++)
        fprintf(f, "%2d ", j);
    fprintf(f, "\n");

    /* Top border */
    fprintf(f, "    ");
    for (j = 0; j < N; j++)
        fprintf(f, "---");
    fprintf(f, "-\n");

    /* Rows */
    for (i = 0; i < M; i++)
    {
        fprintf(f, "%2d | ", i);

        for (j = 0; j < N; j++)
        {
            if (board[i][j] == -1)
                fprintf(f, " * ");
            else
                fprintf(f, " %d ", board[i][j]);
        }

        fprintf(f, "|\n");
    }

    /* Bottom border */
    fprintf(f, "    ");
    for (j = 0; j < N; j++)
        fprintf(f, "---");
    fprintf(f, "-\n");
}

void freeBoard(int **board, int M)
{
    int i;

    for (i = (M - 1); i >= 0; i--)
        free(board[i]);
    free(board);
}
