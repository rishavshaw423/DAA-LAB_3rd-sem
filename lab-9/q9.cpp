
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of ordered weights: ";
    cin >> n;

    if (n <= 0 || n > 500) {
        cout << "Enter a number between 1 and 500.\n";
        return 0;
    }

    vector<long long> w(n), prefix(n + 1, 0);

    cout << "Enter weights in their required order: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];

        if (w[i] < 0) {
            cout << "Weights must be non-negative.\n";
            return 0;
        }

        prefix[i + 1] = prefix[i] + w[i];
    }

    vector<vector<long long>> dp(
        n, vector<long long>(n, 0)
    );

    vector<vector<int>> split(
        n, vector<int>(n, -1)
    );

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;

            long long sum = prefix[j + 1] - prefix[i];
            dp[i][j] = LLONG_MAX / 4;

            for (int k = i; k < j; k++) {
                long long cost =
                    dp[i][k] + dp[k + 1][j] + sum;

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum weighted path cost = "
         << dp[0][n - 1] << '\n';

    cout << "Optimal alphabetic tree structure:\n";

    auto printTree = [&](auto&& self, int i, int j) -> void {
        if (i == j) {
            cout << "L" << i + 1;
            return;
        }

        int k = split[i][j];

        cout << "(";
        self(self, i, k);
        cout << ", ";
        self(self, k + 1, j);
        cout << ")";
    };

    printTree(printTree, 0, n - 1);
    cout << '\n';

    return 0;
}