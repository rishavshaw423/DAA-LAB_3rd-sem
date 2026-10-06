#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, V;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter target amount: ";
    cin >> V;

    const int INF = 1e9;

    vector<int> dp(V + 1, INF);

    dp[0] = 0;

    for (int amount = 1; amount <= V; amount++) {

        for (int coin : coins) {

            if (coin <= amount &&
                dp[amount - coin] != INF) {

                dp[amount] =
                    min(dp[amount],
                        dp[amount - coin] + 1);
            }
        }
    }

    if (dp[V] == INF)
        cout << "Answer = -1\n";
    else
        cout << "Minimum number of coins = "
             << dp[V] << endl;

    return 0;
}