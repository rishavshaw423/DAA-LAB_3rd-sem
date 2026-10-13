
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter number of sticks: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    priority_queue<long long, vector<long long>,
                   greater<long long>> pq;

    cout << "Enter stick lengths: ";

    for (int i = 0; i < n; i++) {
        long long length;
        cin >> length;

        if (length < 0) {
            cout << "Stick lengths must be non-negative.\n";
            return 0;
        }

        pq.push(length);
    }

    long long totalCost = 0;

    while (pq.size() > 1) {
        long long x = pq.top();
        pq.pop();

        long long y = pq.top();
        pq.pop();

        long long combined = x + y;
        totalCost += combined;

        cout << "Connect " << x << " and " << y
             << " -> cost " << combined << '\n';

        pq.push(combined);
    }

    cout << "Minimum total cost = " << totalCost << '\n';
    return 0;
}