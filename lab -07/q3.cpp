#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    vector<long long> dp(n + 1, 0);

    dp[0] = 0;

    if (n >= 1)
        dp[1] = 1;

    for (int i = 2; i <= n; i++) {

        dp[i] = LLONG_MAX;

        for (int k = 1; k < i; k++) {

            long long threePegMoves =
                (1LL << (i - k)) - 1;

            long long moves =
                2 * dp[k]
                + threePegMoves;

            dp[i] = min(dp[i], moves);
        }
    }

    cout << "Minimum moves = "
         << dp[n] << endl;

    return 0;
}