#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Enter number of positions: ";
    cin >> n;

    if (n == 2) {

        cout << "Shooting sequence: 1 1" << endl;
        cout << "Number of shots: 2" << endl;

        return 0;
    }

    cout << "Shooting sequence: ";

    // Forward
    for (int i = 2; i <= n - 1; i++) {
        cout << i << " ";
    }

    // Backward
    for (int i = n - 1; i >= 2; i--) {
        cout << i << " ";
    }

    cout << endl;

    cout << "Number of shots = "
         << 2 * (n - 2) << endl;

    return 0;
}