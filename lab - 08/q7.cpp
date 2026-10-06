#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;

    cout << "Enter rod length: ";
    cin >> n;

    vector<int> price(n + 1);

    cout << "Enter prices for lengths 1 to "
         << n << ": ";

    for (int i = 1; i <= n; i++)
        cin >> price[i];

    vector<int> dp(n + 1, 0);
    vector<int> cut(n + 1, 0);

    for (int length = 1;
         length <= n;
         length++) {

        for (int piece = 1;
             piece <= length;
             piece++) {

            int revenue =
                price[piece]
                + dp[length - piece];

            if (revenue > dp[length]) {

                dp[length] = revenue;

                cut[length] = piece;
            }
        }
    }

    cout << "\nMaximum revenue = "
         << dp[n] << endl;

    cout << "Optimal pieces: ";

    int remaining = n;

    while (remaining > 0) {

        cout << cut[remaining] << " ";

        remaining -= cut[remaining];
    }

    cout << endl;

    return 0;
}