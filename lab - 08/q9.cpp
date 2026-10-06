#include <iostream>
#include <limits>

using namespace std;

struct Result {
    unsigned long long steps;
    unsigned long long maximum;
    bool overflow;
};

Result analyze(unsigned long long n) {

    Result result;

    result.steps = 0;
    result.maximum = n;
    result.overflow = false;

    cout << n;

    while (n != 1) {

        if (n % 2 == 0) {

            n = n / 2;
        }
        else {

            // Check overflow before 3*n + 1
            if (n >
                (numeric_limits<unsigned long long>::max()
                 - 1) / 3) {

                result.overflow = true;

                cout << " -> OVERFLOW";

                break;
            }

            n = 3 * n + 1;
        }

        result.steps++;

        if (n > result.maximum)
            result.maximum = n;

        cout << " -> " << n;
    }

    cout << endl;

    return result;
}

int main() {

    unsigned long long n;

    cout << "Enter starting value: ";
    cin >> n;

    if (n == 0) {

        cout << "Collatz is defined only "
             << "for positive integers.\n";

        return 0;
    }

    Result result = analyze(n);

    cout << "\nNumber of steps = "
         << result.steps << endl;

    cout << "Maximum value reached = "
         << result.maximum << endl;

    if (result.overflow)
        cout << "Overflow occurred.\n";
    else
        cout << "Sequence reached 1.\n";

    return 0;
}