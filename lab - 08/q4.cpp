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

    vector<int> dp(n, 1);

    int answer = 1;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (a[j] < a[i]) {

                dp[i] =
                    max(dp[i],
                        dp[j] + 1);
            }
        }

        answer = max(answer, dp[i]);
    }

    cout << "Length of LIS = "
         << answer << endl;

    return 0;
}