#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

int main() {

    int n;

    cout << "Enter number of keys: ";
    cin >> n;

    vector<double> p(n + 1);
    vector<double> q(n + 1);

    cout << "Enter successful probabilities p1...pn:\n";

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    cout << "Enter unsuccessful probabilities "
         << "q0...qn:\n";

    for (int i = 0; i <= n; i++)
        cin >> q[i];

    vector<vector<double>> e(
        n + 2,
        vector<double>(n + 1, 0)
    );

    vector<vector<double>> w(
        n + 2,
        vector<double>(n + 1, 0)
    );

    vector<vector<int>> root(
        n + 1,
        vector<int>(n + 1, 0)
    );

    // Empty subtrees
    for (int i = 1; i <= n + 1; i++) {

        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    // Chain length
    for (int length = 1;
         length <= n;
         length++) {

        for (int i = 1;
             i <= n - length + 1;
             i++) {

            int j = i + length - 1;

            e[i][j] =
                numeric_limits<double>::infinity();

            w[i][j] =
                w[i][j - 1]
                + p[j]
                + q[j];

            // Try every key as root
            for (int r = i; r <= j; r++) {

                double cost =
                    e[i][r - 1]
                    + e[r + 1][j]
                    + w[i][j];

                if (cost < e[i][j]) {

                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    cout << fixed << setprecision(4);

    cout << "\nMinimum expected search cost = "
         << e[1][n] << endl;

    cout << "Root key index = "
         << root[1][n] << endl;

    return 0;
}