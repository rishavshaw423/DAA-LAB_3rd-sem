#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string A, B;

    cout << "Enter first string: ";
    cin >> A;

    cout << "Enter second string: ";
    cin >> B;

    int m = A.length();
    int n = B.length();

    vector<vector<int>> dp(
        m + 1,
        vector<int>(n + 1)
    );

    // Base cases
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    // DP table
    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            if (A[i - 1] == B[j - 1]) {

                dp[i][j] =
                    dp[i - 1][j - 1];
            }
            else {

                dp[i][j] =
                    1 + min({
                        dp[i - 1][j],     // Delete
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j - 1]  // Replace
                    });
            }
        }
    }

    cout << "\nMinimum edit distance = "
         << dp[m][n] << endl;

    // Traceback
    cout << "\nOperations:\n";

    int i = m;
    int j = n;

    vector<string> operations;

    while (i > 0 || j > 0) {

        // Same character
        if (i > 0 && j > 0 &&
            A[i - 1] == B[j - 1]) {

            i--;
            j--;
        }

        // Replacement
        else if (i > 0 && j > 0 &&
                 dp[i][j] ==
                 dp[i - 1][j - 1] + 1) {

            operations.push_back(
                "Replace '" +
                string(1, A[i - 1]) +
                "' with '" +
                string(1, B[j - 1]) + "'"
            );

            i--;
            j--;
        }

        // Deletion
        else if (i > 0 &&
                 dp[i][j] ==
                 dp[i - 1][j] + 1) {

            operations.push_back(
                "Delete '" +
                string(1, A[i - 1]) +
                "'"
            );

            i--;
        }

        // Insertion
        else {

            operations.push_back(
                "Insert '" +
                string(1, B[j - 1]) +
                "'"
            );

            j--;
        }
    }

    reverse(operations.begin(),
            operations.end());

    for (string op : operations)
        cout << op << endl;

    return 0;
}