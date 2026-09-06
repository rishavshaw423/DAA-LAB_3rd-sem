#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#define PI 3.14159265358979323846

struct Complex
{
    double real;
    double imag;
};

/* Complex addition */
Complex add(Complex a, Complex b)
{
    Complex c;

    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;

    return c;
}

/* Complex subtraction */
Complex subtract(Complex a, Complex b)
{
    Complex c;

    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;

    return c;
}

/* Complex multiplication */
Complex multiply(Complex a, Complex b)
{
    Complex c;

    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;

    return c;
}

/* Divide and Conquer FFT */
void FFT(Complex a[], int n, int inverse)
{
    if (n == 1)
        return;

    Complex *even = new Complex[n / 2];
    Complex *odd = new Complex[n / 2];

    /* Divide */
    for (int i = 0; i < n / 2; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    /* Conquer */
    FFT(even, n / 2, inverse);
    FFT(odd, n / 2, inverse);

    /* Combine */
    double angle = 2 * PI / n;

    if (inverse)
        angle = -angle;

    Complex w;
    w.real = 1;
    w.imag = 0;

    Complex wn;
    wn.real = cos(angle);
    wn.imag = sin(angle);

    for (int k = 0; k < n / 2; k++)
    {
        Complex t = multiply(w, odd[k]);

        a[k] = add(even[k], t);

        a[k + n / 2] = subtract(even[k], t);

        w = multiply(w, wn);
    }

    delete[] even;
    delete[] odd;
}

/* Inverse FFT */
void inverseFFT(Complex a[], int n)
{
    FFT(a, n, 1);

    for (int i = 0; i < n; i++)
    {
        a[i].real = a[i].real / n;
        a[i].imag = a[i].imag / n;
    }
}

/* Find next power of 2 */
int nextPowerOfTwo(int x)
{
    int p = 1;

    while (p < x)
        p *= 2;

    return p;
}

/* Convolution using FFT */
void convolution(int A[], int m, int B[], int n)
{
    int resultSize = m + n - 1;

    int size = nextPowerOfTwo(resultSize);

    Complex *FA = new Complex[size]();
    Complex *FB = new Complex[size]();

    /* Store A */
    for (int i = 0; i < m; i++)
    {
        FA[i].real = A[i];
        FA[i].imag = 0;
    }

    /* Store B */
    for (int i = 0; i < n; i++)
    {
        FB[i].real = B[i];
        FB[i].imag = 0;
    }

    /* FFT(A) */
    FFT(FA, size, 0);

    /* FFT(B) */
    FFT(FB, size, 0);

    /* Multiply FFT(A) and FFT(B) */
    for (int i = 0; i < size; i++)
    {
        FA[i] = multiply(FA[i], FB[i]);
    }

    /* Inverse FFT */
    inverseFFT(FA, size);

    /* Print result */
    cout << "\nConvolution Result:\n";

    for (int i = 0; i < resultSize; i++)
    {
        cout << round(FA[i].real) << " ";
    }

    cout << endl;

    delete[] FA;
    delete[] FB;
}

int main()
{
    int m, n;

    cout << "Enter size of vector A: ";
    cin >> m;

    int *A = new int[m];

    cout << "Enter elements of A:\n";

    for (int i = 0; i < m; i++)
        cin >> A[i];

    cout << "Enter size of vector B: ";
    cin >> n;

    int *B = new int[n];

    cout << "Enter elements of B:\n";

    for (int i = 0; i < n; i++)
        cin >> B[i];

    /* Q3 condition */
    if (n < m)
    {
        cout << "Please ensure n >= m.\n";

        delete[] A;
        delete[] B;

        return 0;
    }

    cout << "\nVector A: ";

    for (int i = 0; i < m; i++)
        cout << A[i] << " ";

    cout << "\nVector B: ";

    for (int i = 0; i < n; i++)
        cout << B[i] << " ";

    convolution(A, m, B, n);

    delete[] A;
    delete[] B;

    return 0;
}