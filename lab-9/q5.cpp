
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of children: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of children.\n";
        return 0;
    }

    vector<int> rating(n), candy(n, 1);

    cout << "Enter ratings: ";
    for (int i = 0; i < n; i++)
        cin >> rating[i];

    // Left to right
    for (int i = 1; i < n; i++) {
        if (rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;
    }

    // Right to left
    for (int i = n - 2; i >= 0; i--) {
        if (rating[i] > rating[i + 1])
            candy[i] = max(candy[i], candy[i + 1] + 1);
    }

    long long total = 0;

    cout << "Candies assigned: ";
    for (int x : candy) {
        cout << x << ' ';
        total += x;
    }

    cout << "\nMinimum total candies = " << total << '\n';
    return 0;
}