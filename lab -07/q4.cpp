#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;

    cout << "Enter number of switches: ";
    cin >> n;

    if (n == 0) {
        cout << "Minimum moves = 0" << endl;
        return 0;
    }

    vector<long long> dp(n + 1);

    dp[1] = 1;

    if (n >= 2)
        dp[2] = 2;

    for (int i = 3; i <= n; i++) {

        dp[i] =
            dp[i - 1]
            + 2 * dp[i - 2]
            + 1;
    }

    cout << "Minimum moves = "
         << dp[n] << endl;

    return 0;
}