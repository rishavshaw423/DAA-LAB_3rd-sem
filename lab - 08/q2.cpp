#include <iostream>
#include <vector>
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

    vector<long long> dp(V + 1, 0);

    dp[0] = 1;

    for (int coin : coins) {

        for (int amount = coin;
             amount <= V;
             amount++) {

            dp[amount] +=
                dp[amount - coin];
        }
    }

    cout << "Total number of ways = "
         << dp[V] << endl;

    return 0;
}
