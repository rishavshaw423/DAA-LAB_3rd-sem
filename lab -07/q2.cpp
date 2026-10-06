#include <iostream>
#include <vector>
using namespace std;

int main() {

    int E, F;

    cout << "Enter number of eggs: ";
    cin >> E;

    cout << "Enter number of floors: ";
    cin >> F;

    // dp[e] = maximum floors testable
    // with e eggs and current number of drops
    vector<long long> dp(E + 1, 0);

    int drops = 0;

    while (dp[E] < F) {

        drops++;

        // Go backwards so old dp[e-1]
        // is still available
        for (int e = E; e >= 1; e--) {

            dp[e] = dp[e]
                  + dp[e - 1]
                  + 1;
        }
    }

    cout << "Minimum drops = "
         << drops << endl;

    return 0;
}