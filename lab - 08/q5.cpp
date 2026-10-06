#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n);

    for (int i = 0; i < n; i++)
        dp[i] = a[i];

    int answer = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (a[j] < a[i]) {

                dp[i] =
                    max(dp[i],
                        dp[j] + a[i]);
            }
        }

        answer = max(answer, dp[i]);
    }

    cout << "Maximum sum = "
         << answer << endl;

    return 0;
}