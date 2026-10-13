
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size.\n";
        return 0;
    }

    priority_queue<int> maxHeap;
    int currentMin = INT_MAX;

    cout << "Enter positive integers: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x <= 0 || x > INT_MAX / 2) {
            cout << "Invalid value or value too large.\n";
            return 0;
        }

        if (x % 2 == 1)
            x *= 2;

        maxHeap.push(x);
        currentMin = min(currentMin, x);
    }

    int answer = INT_MAX;

    while (true) {
        int currentMax = maxHeap.top();
        maxHeap.pop();

        answer = min(answer, currentMax - currentMin);

        if (currentMax % 2 == 1)
            break;

        int reduced = currentMax / 2;
        currentMin = min(currentMin, reduced);
        maxHeap.push(reduced);
    }

    cout << "Minimum deviation = " << answer << '\n';
    return 0;
}