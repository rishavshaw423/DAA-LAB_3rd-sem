#include <stdio.h>

#define MAX 128

int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int R[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            R[i][j] = A[i][j] + B[i][j];
}

void subMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int R[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            R[i][j] = A[i][j] - B[i][j];
}

/*
    Recursive multiplication of matrices having the form

          | A1 A2 |
    A =   | A2 A1 |

          | B1 B2 |
    B =   | B2 B1 |
*/
void multiplySpecial(int A[MAX][MAX], int B[MAX][MAX],
                     int C[MAX][MAX], int n)
{
    // Base case
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A1[MAX][MAX], A2[MAX][MAX];
    int B1[MAX][MAX], B2[MAX][MAX];

    int S1[MAX][MAX], S2[MAX][MAX];
    int D1[MAX][MAX], D2[MAX][MAX];

    int P[MAX][MAX], Q[MAX][MAX];

    int C1[MAX][MAX], C2[MAX][MAX];

    // Divide matrices into blocks
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    // S1 = A1 + A2
    addMatrix(A1, A2, S1, k);

    // S2 = B1 + B2
    addMatrix(B1, B2, S2, k);

    // D1 = A1 - A2
    subMatrix(A1, A2, D1, k);

    // D2 = B1 - B2
    subMatrix(B1, B2, D2, k);

    // P = (A1 + A2)(B1 + B2)
    multiplySpecial(S1, S2, P, k);

    // Q = (A1 - A2)(B1 - B2)
    multiplySpecial(D1, D2, Q, k);

    // C1 = (P + Q) / 2
    // C2 = (P - Q) / 2
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C1[i][j] = (P[i][j] + Q[i][j]) / 2;
            C2[i][j] = (P[i][j] - Q[i][j]) / 2;
        }
    }

    // Combine
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C1[i][j];
            C[i][j + k] = C2[i][j];

            C[i + k][j] = C2[i][j];
            C[i + k][j + k] = C1[i][j];
        }
    }
}

void printMatrix(int M[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", M[i][j]);

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter matrix size n (power of 2): ");
    scanf("%d", &n);

    printf("\nEnter Matrix A:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter Matrix B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    multiplySpecial(A, B, C, n);

    printf("\nResult Matrix C = A * B:\n");
    printMatrix(C, n);

    return 0;
}