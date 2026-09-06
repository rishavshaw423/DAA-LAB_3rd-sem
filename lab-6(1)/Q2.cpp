#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

// Function to print a matrix
void printMatrix(int A[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// 1. Matrix Addition - O(n^2)
void addition(int A[][MAX], int B[][MAX],
              int C[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 2. Matrix Multiplication - O(n^3)
void multiplication(int A[][MAX], int B[][MAX],
                    int C[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 3. Check Zero Matrix - O(n^2)
int isZeroMatrix(int A[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

// 4. Check Symmetric Matrix - O(n^2)
int isSymmetric(int A[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}

// 5. Determinant using cofactor expansion - O(n!)
int determinant(int A[][MAX], int n)
{
    // For 1 x 1 matrix
    if (n == 1)
    {
        return A[0][0];
    }

    // For 2 x 2 matrix
    if (n == 2)
    {
        return A[0][0] * A[1][1]
             - A[0][1] * A[1][0];
    }

    int det = 0;
    int minor[MAX][MAX];

    for (int col = 0; col < n; col++)
    {
        int r = 0;

        // Create minor matrix
        for (int i = 1; i < n; i++)
        {
            int c = 0;

            for (int j = 0; j < n; j++)
            {
                if (j == col)
                {
                    continue;
                }

                minor[r][c] = A[i][j];
                c++;
            }

            r++;
        }

        int sign;

        if (col % 2 == 0)
            sign = 1;
        else
            sign = -1;

        det = det + sign * A[0][col]
              * determinant(minor, n - 1);
    }

    return det;
}

// 6. Transpose in situ - O(n^2)
void transpose(int A[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = A[i][j];

            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

// 7. Eigenvalues and Eigenvectors for 2 x 2 matrix
void eigenValuesVectors(int A[][MAX])
{
    double a = A[0][0];
    double b = A[0][1];
    double c = A[1][0];
    double d = A[1][1];

    // Characteristic equation:
    // lambda^2 - (a+d)lambda + (ad-bc) = 0

    double trace = a + d;
    double determinantValue = a * d - b * c;

    double discriminant =
        trace * trace - 4 * determinantValue;

    if (discriminant < 0)
    {
        cout << "Complex eigenvalues are obtained."
             << endl;
        return;
    }

    double lambda1 =
        (trace + sqrt(discriminant)) / 2;

    double lambda2 =
        (trace - sqrt(discriminant)) / 2;

    cout << "Eigenvalue 1 = " << lambda1 << endl;
    cout << "Eigenvalue 2 = " << lambda2 << endl;

    cout << "\nCorresponding eigenvectors:" << endl;

    // Eigenvector for lambda1
    cout << "For eigenvalue " << lambda1 << ": ";

    if (b != 0)
    {
        cout << "v = [" << b << ", "
             << lambda1 - a << "]" << endl;
    }
    else if (c != 0)
    {
        cout << "v = [" << lambda1 - d
             << ", " << c << "]" << endl;
    }
    else
    {
        cout << "v = [1, 0] (one possible vector)"
             << endl;
    }

    // Eigenvector for lambda2
    cout << "For eigenvalue " << lambda2 << ": ";

    if (b != 0)
    {
        cout << "v = [" << b << ", "
             << lambda2 - a << "]" << endl;
    }
    else if (c != 0)
    {
        cout << "v = [" << lambda2 - d
             << ", " << c << "]" << endl;
    }
    else
    {
        cout << "v = [0, 1] (one possible vector)"
             << endl;
    }
}

int main()
{
    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    int n;

    // Input size
    cout << "Enter size of square matrix: ";
    cin >> n;

    // Input Matrix A
    cout << "\nEnter elements of Matrix A:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    // Input Matrix B
    cout << "\nEnter elements of Matrix B:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    // Display Matrix A
    cout << "\nMatrix A:" << endl;
    printMatrix(A, n);

    // Display Matrix B
    cout << "\nMatrix B:" << endl;
    printMatrix(B, n);

    // 1. Addition
    addition(A, B, C, n);

    cout << "\n1. Matrix Addition:" << endl;
    printMatrix(C, n);

    // 2. Multiplication
    multiplication(A, B, C, n);

    cout << "\n2. Matrix Multiplication:" << endl;
    printMatrix(C, n);

    // 3. Zero Matrix
    if (isZeroMatrix(A, n))
    {
        cout << "\n3. Matrix A is a Zero Matrix."
             << endl;
    }
    else
    {
        cout << "\n3. Matrix A is NOT a Zero Matrix."
             << endl;
    }

    // 4. Symmetric Matrix
    if (isSymmetric(A, n))
    {
        cout << "\n4. Matrix A is Symmetric."
             << endl;
    }
    else
    {
        cout << "\n4. Matrix A is NOT Symmetric."
             << endl;
    }

    // 5. Determinant
    cout << "\n5. Determinant of Matrix A = "
         << determinant(A, n) << endl;

    // 6. Transpose
    transpose(A, n);

    cout << "\n6. Transpose of Matrix A:" << endl;
    printMatrix(A, n);

    // 7. Eigenvalues and Eigenvectors
    if (n == 2)
    {
        cout << "\n7. Eigenvalues and Eigenvectors:"
             << endl;

        eigenValuesVectors(A);
    }
    else
    {
        cout << "\n7. Eigenvalue/Eigenvector calculation ";
        cout << "shown for 2 x 2 matrix only." << endl;

        cout << "For general n x n matrix, the complexity ";
        cout << "depends on the numerical algorithm used."
             << endl;
    }

    return 0;
}