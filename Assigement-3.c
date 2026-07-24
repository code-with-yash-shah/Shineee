#include <stdio.h>

// Function to read a matrix
void ReadMatrix(int rows, int cols, int matrix[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void DisplayMatrix(int rows, int cols, int matrix[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void AddMatrix(int rows, int cols, int A[rows][cols], int B[rows][cols], int C[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nAddition of Matrix:\n");
    DisplayMatrix(rows, cols, C);
}

// Function to subtract two matrices
void SubtractMatrix(int rows, int cols, int A[rows][cols], int B[rows][cols], int C[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("\nSubtraction of Matrix:\n");
    DisplayMatrix(rows, cols, C);
}

// Function to multiply two matrices
void MultiplyMatrix(int r1, int c1, int c2, int A[r1][c1], int B[c1][c2], int C[r1][c2])
{
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMultiplication of Matrix:\n");
    DisplayMatrix(r1, c2, C);
}

// Function to find sum of each row
void RowSum(int rows, int cols, int matrix[rows][cols])
{
    int i, j, sum;

    printf("\nRow Sum:\n");

    for (i = 0; i < rows; i++)
    {
        sum = 0;

        for (j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }

        printf("Row %d = %d\n", i + 1, sum);
    }
}

// Function to find sum of each column
void ColumnSum(int rows, int cols, int matrix[rows][cols])
{
    int i, j, sum;

    printf("\nColumn Sum:\n");

    for (j = 0; j < cols; j++)
    {
        sum = 0;

        for (i = 0; i < rows; i++)
        {
            sum += matrix[i][j];
        }

        printf("Column %d = %d\n", j + 1, sum);
    }
}

int main()
{
    int r1, c1, r2, c2;

    printf("Enter rows of Matrix A: ");
    scanf("%d", &r1);

    printf("Enter columns of Matrix A: ");
    scanf("%d", &c1);

    printf("Enter rows of Matrix B: ");
    scanf("%d", &r2);

    printf("Enter columns of Matrix B: ");
    scanf("%d", &c2);

    int A[r1][c1];
    int B[r2][c2];

    printf("\nEnter elements of Matrix A:\n");
    ReadMatrix(r1, c1, A);

    printf("\nEnter elements of Matrix B:\n");
    ReadMatrix(r2, c2, B);

    printf("\nMatrix A:\n");
    DisplayMatrix(r1, c1, A);

    printf("\nMatrix B:\n");
    DisplayMatrix(r2, c2, B);

    if (r1 == r2 && c1 == c2)
    {
        int C[r1][c1];

        AddMatrix(r1, c1, A, B, C);
        SubtractMatrix(r1, c1, A, B, C);
    }
    else
    {
        printf("\nAddition and Subtraction are not possible.\n");
    }

    if (c1 == r2)
    {
        int C[r1][c2];

        MultiplyMatrix(r1, c1, c2, A, B, C);
    }
    else
    {
        printf("\nMultiplication is not possible.\n");
    }

    printf("\nMatrix A:\n");
    RowSum(r1, c1, A);
    ColumnSum(r1, c1, A);

    printf("\nMatrix B:\n");
    RowSum(r2, c2, B);
    ColumnSum(r2, c2, B);

    return 0;
}