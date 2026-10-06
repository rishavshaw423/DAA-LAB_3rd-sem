#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    long long a = 1; // M(1)
    long long b = 2; // M(2)

    for (int i = 3; i <= n; i++) {

        long long c =
            b + 2 * a + 1;

        a = b;
        b = c;
    }

    cout << b;

    return 0;
}