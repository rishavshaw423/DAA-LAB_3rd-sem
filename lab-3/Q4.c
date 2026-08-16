#include <stdio.h>
#include <stdlib.h>

/* Allocate a square matrix */
int **allocateMatrix(int n)
{
    int **matrix = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    return matrix;
}

/* Free a matrix */
void freeMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);

    free(matrix);
}

/* Add two matrices */
void addMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/* Subtract two matrices */
void subtractMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/* Strassen's multiplication */
void strassen(int **A, int **B, int **C, int n)
{
    /* Base case */
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    /* Allocate submatrices */
    int **A11 = allocateMatrix(newSize);
    int **A12 = allocateMatrix(newSize);
    int **A21 = allocateMatrix(newSize);
    int **A22 = allocateMatrix(newSize);

    int **B11 = allocateMatrix(newSize);
    int **B12 = allocateMatrix(newSize);
    int **B21 = allocateMatrix(newSize);
    int **B22 = allocateMatrix(newSize);

    /* Allocate M1-M7 */
    int **M1 = allocateMatrix(newSize);
    int **M2 = allocateMatrix(newSize);
    int **M3 = allocateMatrix(newSize);
    int **M4 = allocateMatrix(newSize);
    int **M5 = allocateMatrix(newSize);
    int **M6 = allocateMatrix(newSize);
    int **M7 = allocateMatrix(newSize);

    /* Temporary matrices */
    int **T1 = allocateMatrix(newSize);
    int **T2 = allocateMatrix(newSize);

    /* Divide A and B into four parts */
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    /* M1 = (A11 + A22)(B11 + B22) */
    addMatrix(A11, A22, T1, newSize);
    addMatrix(B11, B22, T2, newSize);
    strassen(T1, T2, M1, newSize);

    /* M2 = (A21 + A22)B11 */
    addMatrix(A21, A22, T1, newSize);
    strassen(T1, B11, M2, newSize);

    /* M3 = A11(B12 - B22) */
    subtractMatrix(B12, B22, T2, newSize);
    strassen(A11, T2, M3, newSize);

    /* M4 = A22(B21 - B11) */
    subtractMatrix(B21, B11, T2, newSize);
    strassen(A22, T2, M4, newSize);

    /* M5 = (A11 + A12)B22 */
    addMatrix(A11, A12, T1, newSize);
    strassen(T1, B22, M5, newSize);

    /* M6 = (A21 - A11)(B11 + B12) */
    subtractMatrix(A21, A11, T1, newSize);
    addMatrix(B11, B12, T2, newSize);
    strassen(T1, T2, M6, newSize);

    /* M7 = (A12 - A22)(B21 + B22) */
    subtractMatrix(A12, A22, T1, newSize);
    addMatrix(B21, B22, T2, newSize);
    strassen(T1, T2, M7, newSize);

    /* Calculate C11, C12, C21, C22 */

    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            /* C11 = M1 + M4 - M5 + M7 */
            C[i][j] =
                M1[i][j] +
                M4[i][j] -
                M5[i][j] +
                M7[i][j];

            /* C12 = M3 + M5 */
            C[i][j + newSize] =
                M3[i][j] +
                M5[i][j];

            /* C21 = M2 + M4 */
            C[i + newSize][j] =
                M2[i][j] +
                M4[i][j];

            /* C22 = M1 - M2 + M3 + M6 */
            C[i + newSize][j + newSize] =
                M1[i][j] -
                M2[i][j] +
                M3[i][j] +
                M6[i][j];
        }
    }

    /* Free memory */
    freeMatrix(A11, newSize);
    freeMatrix(A12, newSize);
    freeMatrix(A21, newSize);
    freeMatrix(A22, newSize);

    freeMatrix(B11, newSize);
    freeMatrix(B12, newSize);
    freeMatrix(B21, newSize);
    freeMatrix(B22, newSize);

    freeMatrix(M1, newSize);
    freeMatrix(M2, newSize);
    freeMatrix(M3, newSize);
    freeMatrix(M4, newSize);
    freeMatrix(M5, newSize);
    freeMatrix(M6, newSize);
    freeMatrix(M7, newSize);

    freeMatrix(T1, newSize);
    freeMatrix(T2, newSize);
}

/* Print matrix */
void printMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter size of square matrices: ");
    scanf("%d", &n);

    /*
       Strassen recursively divides the matrix into
       halves, so n should be a power of 2.
    */
    if (n <= 0 || (n & (n - 1)) != 0)
    {
        printf("Error: n must be a power of 2.\n");
        return 1;
    }

    int **A = allocateMatrix(n);
    int **B = allocateMatrix(n);
    int **C = allocateMatrix(n);

    printf("\nEnter elements of Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(A, B, C, n);

    printf("\nMatrix A:\n");
    printMatrix(A, n);

    printf("\nMatrix B:\n");
    printMatrix(B, n);

    printf("\nResult Matrix C = A x B:\n");
    printMatrix(C, n);

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}