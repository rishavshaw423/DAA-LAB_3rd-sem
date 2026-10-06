#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printOrder(const vector<vector<int>>& split,
                int i, int j) {

    if (i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";

    printOrder(split, i, split[i][j]);

    cout << " x ";

    printOrder(split, split[i][j] + 1, j);

    cout << ")";
}

int main() {

    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter " << n + 1
         << " dimensions: ";

    for (int i = 0; i <= n; i++)
        cin >> p[i];

    vector<vector<int>> m(
        n + 1,
        vector<int>(n + 1, 0)
    );

    vector<vector<int>> split(
        n + 1,
        vector<int>(n + 1, 0)
    );

    // length = number of matrices in chain
    for (int length = 2;
         length <= n;
         length++) {

        for (int i = 1;
             i <= n - length + 1;
             i++) {

            int j = i + length - 1;

            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost =
                    m[i][k]
                    + m[k + 1][j]
                    + p[i - 1]
                    * p[k]
                    * p[j];

                if (cost < m[i][j]) {

                    m[i][j] = cost;

                    split[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum scalar multiplications = "
         << m[1][n] << endl;

    cout << "Optimal order = ";

    printOrder(split, 1, n);

    cout << endl;

    return 0;
}